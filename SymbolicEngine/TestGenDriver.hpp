
// TestGenDriver.hpp

#pragma once

#include <string>

#include <map>

#include "TestGenSymbolicVisitor.hpp"

#include "TestGenSymbolicEnv.hpp"

#include "../ast.hpp"

// Removed: #include "../library_apispec_examples/Entry.hpp"

// Forward declarations

class Spec;

struct SymbolTable;

struct TypeMap;

class TestGenDriver {

public:

    struct TestResult {

        bool satisfiable;

        std::map<std::string, std::string> concreteValues;

        std::string smtContent;

        std::string z3Output;

        std::string errorMessage;

    };

    

    static TestResult generateConcreteTestCase(const Program& testGenProgram, bool debugMode = false);

    static void demonstrateTestGenSymbolicEngine();

private:

    static void writeFile(const std::string& filename, const std::string& content);

    static std::string runZ3(const std::string& smtFile);

    static std::map<std::string, std::string> parseZ3Model(const std::string& z3Output, const TestGenSymbolicEnv& env);

};

