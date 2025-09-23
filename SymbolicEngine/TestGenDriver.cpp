#include "TestGenDriver.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <regex>
#include <iterator>

TestGenDriver::TestResult TestGenDriver::generateConcreteTestCase(const Program& testGenProgram, 
                                                                 bool debugMode) {
    TestResult result;
    result.satisfiable = false;
    
    try {
        TestGenSymbolicEnv env;
        TestGenSymbolicVisitor visitor(env, debugMode);
        
        if (debugMode) {
            std::cout << "\n=== TestGen Symbolic Execution Starting ===" << std::endl;
        }
        
        const_cast<Program&>(testGenProgram).accept(visitor);
        
        if (debugMode) {
            env.printDebugInfo();
        }
        
        result.smtContent = env.generateSMTLib(true);
        
        if (result.smtContent.empty()) {
            result.errorMessage = "No SMT constraints generated";
            return result;
        }
        
        writeFile("testgen_constraints.smt2", result.smtContent);
        
        if (debugMode) {
            std::cout << "\n=== Generated SMT-LIB ===\n";
            std::cout << result.smtContent.substr(0, 1000);
            if (result.smtContent.length() > 1000) {
                std::cout << "\n... (truncated, total: " << result.smtContent.length() << " chars)";
            }
            std::cout << std::endl;
        }
        
        result.z3Output = runZ3("testgen_constraints.smt2");
        
        if (debugMode) {
            std::cout << "\n=== Z3 Output ===\n" << result.z3Output << std::endl;
        }
        
        if (result.z3Output.find("sat") != std::string::npos && 
            result.z3Output.find("unsat") == std::string::npos) {
            
            result.satisfiable = true;
            result.concreteValues = parseZ3Model(result.z3Output, env);
            
            if (debugMode) {
                std::cout << "\n=== Concrete Test Values ===\n";
                for (const auto& [var, value] : result.concreteValues) {
                    std::cout << var << " = " << value << std::endl;
                }
            }
            
        } else if (result.z3Output.find("unsat") != std::string::npos) {
            result.errorMessage = "Constraints are unsatisfiable";
        } else {
            result.errorMessage = "Unexpected Z3 output: " + result.z3Output;
        }
        
    } catch (const std::exception& e) {
        result.errorMessage = "Exception: " + std::string(e.what());
    }
    
    return result;
}

void TestGenDriver::writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot write file: " + filename);
    }
    file << content;
}

std::string TestGenDriver::runZ3(const std::string& smtFile) {
    const std::string outputFile = "z3_result.txt";
    std::string command = "z3 -model " + smtFile + " > " + outputFile + " 2>&1";
    
    int exitCode = std::system(command.c_str());
    if (exitCode != 0) {
        std::cerr << "Warning: Z3 exited with code " << exitCode << std::endl;
    }
    
    std::ifstream file(outputFile);
    if (!file) {
        return "Error: Could not read Z3 output";
    }
    
    std::string content((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
    return content;
}

std::map<std::string, std::string> TestGenDriver::parseZ3Model(const std::string& z3Output, 
                                                              const TestGenSymbolicEnv& env) {
    std::map<std::string, std::string> result;
    
    std::regex modelRegex("\\(define-fun\\s+(\\w+)\\s+\\(\\)\\s+String\\s+\"([^\"]*)\"\\)");
    std::smatch match;
    
    const auto& symbolToVar = env.getSymbolToVar();
    
    auto searchStart = z3Output.cbegin();
    while (std::regex_search(searchStart, z3Output.cend(), match, modelRegex)) {
        std::string symbol = match[1].str();
        std::string value = match[2].str();
        
        auto it = symbolToVar.find(symbol);
        if (it != symbolToVar.end()) {
            result[it->second] = value;
        } else {
            result[symbol] = value;
        }
        
        searchStart = match.suffix().first;
    }
    
    return result;
}

void TestGenDriver::demonstrateTestGenSymbolicEngine() {
    std::cout << "Demo function not available in standalone mode" << std::endl;
}
