// TestGenSymbolicEnv.hpp
#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <set>

class TestGenSymbolicEnv {
public:
    struct MapInfo { 
        std::string domainArray;  // Array for domain membership
        std::string valueArray;   // Array for map values  
    };

    // Map management for TestGen map variables (U, S, T, etc.)
    const MapInfo& declareMap(const std::string& mapName);
    bool isMap(const std::string& name) const;
    const MapInfo& getMapInfo(const std::string& name) const;

    // Variable symbol management
    const std::string& getSymbolFor(const std::string& varName);
    std::string createFreshSymbol(const std::string& tag = "fresh");

    // Constraint management
    void addConstraint(const std::string& constraint);
    void addInputVariable(const std::string& varName);

    // SMT-LIB generation
    std::string generateSMTLib(bool includeFooter = true) const;

    // Access to mappings for result processing
    const std::unordered_map<std::string, std::string>& getVariableSymbols() const;
    const std::unordered_map<std::string, std::string>& getSymbolToVar() const;
    const std::vector<std::string>& getConstraints() const;
    
    // Debug info
    void printDebugInfo() const;

private:
    // Symbol management
    std::unordered_map<std::string, std::string> variableSymbols;  // var -> symbol
    std::unordered_map<std::string, std::string> symbolToVar;      // symbol -> var
    std::vector<std::string> symbolOrder;
    std::set<std::string> inputVariables;
    int symbolCounter = 0;
    
    // Map information
    std::map<std::string, MapInfo> mapInfo;
    
    // Constraints
    std::vector<std::string> constraints;
    std::vector<std::string> constraintNames;
    int constraintCounter = 0;
};
