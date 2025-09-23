// TestGenSymbolicEnv.cpp
#include "TestGenSymbolicEnv.hpp"
#include <sstream>
#include <iostream>

const TestGenSymbolicEnv::MapInfo& TestGenSymbolicEnv::declareMap(const std::string& mapName) {
    auto& info = mapInfo[mapName];
    if (info.domainArray.empty()) {
        info.domainArray = "Dom_" + mapName;
        info.valueArray = "Val_" + mapName;
    }
    return info;
}

bool TestGenSymbolicEnv::isMap(const std::string& name) const { 
    return mapInfo.count(name) > 0; 
}

const TestGenSymbolicEnv::MapInfo& TestGenSymbolicEnv::getMapInfo(const std::string& name) const { 
    return mapInfo.at(name); 
}

const std::string& TestGenSymbolicEnv::getSymbolFor(const std::string& varName) {
    auto [it, inserted] = variableSymbols.emplace(varName, "");
    if (inserted) {
        it->second = "v" + std::to_string(++symbolCounter);
        symbolOrder.push_back(it->second);
        symbolToVar[it->second] = varName;
    }
    return it->second;
}

std::string TestGenSymbolicEnv::createFreshSymbol(const std::string& tag) {
    std::string symbol = "v" + std::to_string(++symbolCounter);
    symbolOrder.push_back(symbol);
    symbolToVar[symbol] = tag;
    return symbol;
}

void TestGenSymbolicEnv::addConstraint(const std::string& constraint) {
    if (!constraint.empty()) {
        constraints.push_back(constraint);
        constraintNames.push_back("c" + std::to_string(++constraintCounter));
    }
}

void TestGenSymbolicEnv::addInputVariable(const std::string& varName) {
    inputVariables.insert(varName);
    getSymbolFor(varName);  // Ensure it has a symbol
}

std::string TestGenSymbolicEnv::generateSMTLib(bool includeFooter) const {
    std::ostringstream smt;
    
    smt << "(set-logic ALL)\n";
    smt << "(set-option :produce-models true)\n\n";
    
    // Declare all variables as strings
    for (const auto& symbol : symbolOrder) {
        smt << "(declare-fun " << symbol << " () String)\n";
    }
    if (!symbolOrder.empty()) smt << "\n";
    
    // Declare maps as arrays
    for (const auto& [mapName, info] : mapInfo) {
        smt << "; Map: " << mapName << "\n";
        smt << "(declare-const " << info.domainArray << " (Array String Bool))\n";
        smt << "(declare-const " << info.valueArray << " (Array String String))\n\n";
    }
    
    // Add input variable constraints (non-empty strings)
    for (const auto& inputVar : inputVariables) {
        auto it = variableSymbols.find(inputVar);
        if (it != variableSymbols.end()) {
            smt << "(assert (> (str.len " << it->second << ") 0))\n";
        }
    }
    if (!inputVariables.empty()) smt << "\n";
    
    // Add constraints with names
    for (size_t i = 0; i < constraints.size(); ++i) {
        smt << "(assert (! " << constraints[i] << " :named " << constraintNames[i] << "))\n";
    }
    
    if (includeFooter) {
        smt << "\n(check-sat)\n";
        smt << "(get-model)\n";
    }
    
    return smt.str();
}

const std::unordered_map<std::string, std::string>& TestGenSymbolicEnv::getVariableSymbols() const { 
    return variableSymbols; 
}

const std::unordered_map<std::string, std::string>& TestGenSymbolicEnv::getSymbolToVar() const { 
    return symbolToVar; 
}

const std::vector<std::string>& TestGenSymbolicEnv::getConstraints() const { 
    return constraints; 
}

void TestGenSymbolicEnv::printDebugInfo() const {
    std::cout << "=== TestGen Symbolic Environment Debug ===" << std::endl;
    std::cout << "Variables: " << variableSymbols.size() << std::endl;
    for (const auto& [var, sym] : variableSymbols) {
        std::cout << "  " << var << " -> " << sym << std::endl;
    }
    std::cout << "Maps: " << mapInfo.size() << std::endl;
    for (const auto& [map, info] : mapInfo) {
        std::cout << "  " << map << " -> dom:" << info.domainArray 
                  << " val:" << info.valueArray << std::endl;
    }
    std::cout << "Constraints: " << constraints.size() << std::endl;
    for (size_t i = 0; i < constraints.size() && i < 5; ++i) {
        std::cout << "  [" << i << "] " << constraints[i] << std::endl;
    }
    if (constraints.size() > 5) {
        std::cout << "  ... and " << (constraints.size() - 5) << " more" << std::endl;
    }
}
