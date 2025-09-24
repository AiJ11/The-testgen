#!/bin/bash
# build_and_test_testgen.sh - Complete build and test script for TestGen Symbolic Engine

set -e  # Exit on any error

echo "======================================================"
echo "TestGen Symbolic Engine - Build and Test Script"
echo "======================================================"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if Z3 is installed
print_status "Checking Z3 installation..."
if ! command -v z3 &> /dev/null; then
    print_error "Z3 SMT solver not found!"
    echo "Please install Z3:"
    echo "  Ubuntu/Debian: sudo apt-get install z3"
    echo "  macOS: brew install z3"
    echo "  Or download from: https://github.com/Z3Prover/z3/releases"
    exit 1
fi

Z3_VERSION=$(z3 -version 2>&1 | head -1)
print_success "Found Z3: $Z3_VERSION"

# Check compiler
print_status "Checking C++ compiler..."
if ! command -v g++ &> /dev/null; then
    print_error "g++ compiler not found!"
    exit 1
fi

GCC_VERSION=$(g++ --version | head -1)
print_success "Found compiler: $GCC_VERSION"

# Create SymbolicEngine directory if it doesn't exist
print_status "Setting up directory structure..."
mkdir -p SymbolicEngine
print_success "SymbolicEngine directory ready"

# Check for required TestGen files
print_status "Checking TestGen core files..."
required_files=("ast.hpp" "algo.hpp" "ASTVis.hpp" "PrintVisitor.hpp" "symbol_table.hpp")
missing_files=()

for file in "${required_files[@]}"; do
    if [ ! -f "$file" ]; then
        missing_files+=("$file")
    fi
done

if [ ${#missing_files[@]} -gt 0 ]; then
    print_error "Missing required TestGen files:"
    for file in "${missing_files[@]}"; do
        echo "  - $file"
    done
    echo "Please ensure all TestGen core files are present."
    exit 1
fi

print_success "All required TestGen files found"

# Check for SymbolicEngine files
print_status "Checking SymbolicEngine files..."
symbolic_files=(
    "SymbolicEngine/TestGenSymbolicEnv.hpp"
    "SymbolicEngine/TestGenSymbolicEnv.cpp"
    "SymbolicEngine/TestGenSymbolicVisitor.hpp"
    "SymbolicEngine/TestGenSymbolicVisitor.cpp"
    "SymbolicEngine/TestGenDriver.hpp"
    "SymbolicEngine/TestGenDriver.cpp"
)

missing_symbolic=()
for file in "${symbolic_files[@]}"; do
    if [ ! -f "$file" ]; then
        missing_symbolic+=("$file")
    fi
done

if [ ${#missing_symbolic[@]} -gt 0 ]; then
    print_warning "Missing SymbolicEngine files:"
    for file in "${missing_symbolic[@]}"; do
        echo "  - $file"
    done
    echo ""
    print_status "Creating template files..."
    
    # Create template headers if they don't exist
    if [ ! -f "SymbolicEngine/TestGenSymbolicEnv.hpp" ]; then
cat > SymbolicEngine/TestGenSymbolicEnv.hpp << 'EOF'
// TestGenSymbolicEnv.hpp - Template
#pragma once
#include <string>
#include <map>
#include <vector>
#include <unordered_map>

class TestGenSymbolicEnv {
public:
    struct MapInfo { 
        std::string domainArray;
        std::string valueArray;  
    };

    const MapInfo& declareMap(const std::string& mapName);
    bool isMap(const std::string& name) const;
    const MapInfo& getMapInfo(const std::string& name) const;
    const std::string& getSymbolFor(const std::string& varName);
    std::string createFreshSymbol(const std::string& tag = "fresh");
    void addConstraint(const std::string& constraint);
    void addInputVariable(const std::string& varName);
    std::string generateSMTLib(bool includeFooter = true) const;
    const std::unordered_map<std::string, std::string>& getVariableSymbols() const;
    const std::unordered_map<std::string, std::string>& getSymbolToVar() const;
    void printDebugInfo() const;
    
private:
    std::unordered_map<std::string, std::string> variableSymbols;
    std::unordered_map<std::string, std::string> symbolToVar;
    std::vector<std::string> symbolOrder;
    std::map<std::string, MapInfo> mapInfo;
    std::vector<std::string> constraints;
    std::vector<std::string> constraintNames;
    int symbolCounter = 0;
    int constraintCounter = 0;
};
EOF
        print_status "Created SymbolicEngine/TestGenSymbolicEnv.hpp template"
    fi

    if [ ! -f "SymbolicEngine/TestGenSymbolicVisitor.hpp" ]; then
cat > SymbolicEngine/TestGenSymbolicVisitor.hpp << 'EOF'
// TestGenSymbolicVisitor.hpp - Template
#pragma once
#include "../ASTVis.hpp"
#include "../ast.hpp"
#include "TestGenSymbolicEnv.hpp"

class TestGenSymbolicVisitor : public ASTVisitor {
public:
    explicit TestGenSymbolicVisitor(TestGenSymbolicEnv& env, bool debugMode = false);
    
    void visit(const Assign& n) override;
    void visit(const FuncCallStmt& n) override;
    void visit(const Program& n) override;
    void visit(const Var& n) override;
    void visit(const FuncCall& n) override;
    void visit(const Num& n) override;
    void visit(const String& n) override;
    
    // Stub implementations for unused visitors
    void visit(const Set&) override {}
    void visit(const Map&) override {}
    void visit(const Tuple&) override {}
    void visit(const TypeConst&) override {}
    void visit(const FuncType&) override {}
    void visit(const MapType&) override {}
    void visit(const TupleType&) override {}
    void visit(const SetType&) override {}
    void visit(const Decl&) override {}
    void visit(const FuncDecl&) override {}
    void visit(const APIcall&) override {}
    void visit(const API&) override {}
    void visit(const Response&) override {}
    void visit(const Init&) override {}
    void visit(const Spec&) override {}
    
    std::string exprToSMT(const Expr& expr);
    
private:
    TestGenSymbolicEnv& env;
    bool debugMode;
    std::string convertExprToSMT(const Expr& expr);
};
EOF
        print_status "Created SymbolicEngine/TestGenSymbolicVisitor.hpp template"
    fi

    if [ ! -f "SymbolicEngine/TestGenDriver.hpp" ]; then
cat > SymbolicEngine/TestGenDriver.hpp << 'EOF'
// TestGenDriver.hpp - Template
#pragma once
#include <string>
#include <map>
#include "TestGenSymbolicVisitor.hpp"
#include "TestGenSymbolicEnv.hpp"
#include "../ast.hpp"
#include "../algo.hpp"
#include "../library_apispec_examples/Entry.hpp"

class TestGenDriver {
public:
    struct TestResult {
        bool satisfiable;
        std::map<std::string, std::string> concreteValues;
        std::string smtContent;
        std::string z3Output;
        std::string errorMessage;
    };

    static TestResult generateConcreteTestCase(const Program& testGenProgram, 
                                             bool debugMode = false);
    
    static void demonstrateTestGenSymbolicEngine();

private:
    static void writeFile(const std::string& filename, const std::string& content);
    static std::string runZ3(const std::string& smtFile);
    static std::map<std::string, std::string> parseZ3Model(const std::string& z3Output, 
                                                          const TestGenSymbolicEnv& env);
};
EOF
        print_status "Created SymbolicEngine/TestGenDriver.hpp template"
    fi

    print_warning "Template files created. You need to implement the .cpp files using the artifacts provided."
    print_warning "The build will fail until you implement all the .cpp files."
fi

# Try to build the project
print_status "Building TestGen Symbolic Engine..."

# Use make if Makefile exists, otherwise try manual build
if [ -f "Makefile" ]; then
    print_status "Using Makefile..."
    if make clean && make check-headers && make all; then
        print_success "Build completed successfully!"
        
        # Run test if build succeeded
        print_status "Running test..."
        if make test; then
            print_success "Test completed!"
        else
            print_warning "Test execution had issues, but build was successful"
        fi
    else
        print_error "Build failed!"
        echo "This is expected if .cpp implementation files are missing."
        echo "Please implement the .cpp files using the provided artifacts."
    fi
else
    print_status "No Makefile found, trying manual build..."
    
    BUILD_CMD="g++ -std=c++17 -Wall -Wextra -I. -g -o testgen_symbolic_engine \
        test_libapplication.cpp \
        SymbolicEngine/TestGenSymbolicEnv.cpp \
        SymbolicEngine/TestGenSymbolicVisitor.cpp \
        SymbolicEngine/TestGenDriver.cpp \
        jsCodeGenerator/jsCodeGen.cpp"
    
    print_status "Build command: $BUILD_CMD"
    
    if $BUILD_CMD 2>&1; then
        print_success "Manual build completed successfully!"
        
        if [ -f "./testgen_symbolic_engine" ]; then
            print_status "Running test..."
            ./testgen_symbolic_engine
        fi
    else
        print_error "Manual build failed!"
        echo "This is expected since we're creating a framework."
        echo "You'll need to implement the actual .cpp files."
    fi
fi

# Check for output files
print_status "Checking generated files..."
output_files=("*.smt2" "*.txt")
found_files=()

for pattern in "${output_files[@]}"; do
    for file in $pattern; do
        if [ -f "$file" ]; then
            found_files+=("$file")
        fi
    done
done

if [ ${#found_files[@]} -gt 0 ]; then
    print_success "Generated files found:"
    for file in "${found_files[@]}"; do
        echo "  - $file"
    done
else
    print_warning "No output files generated (this is normal if build failed)"
fi

# Summary
echo ""
echo "======================================================"
echo "SETUP SUMMARY"
echo "======================================================"
echo ""
echo "Directory Structure:"
echo "  ✓ SymbolicEngine/ folder created"
echo "  ✓ Required TestGen files verified"

if [ ${#missing_symbolic[@]} -eq 0 ]; then
    echo "  ✓ All SymbolicEngine files present"
else
    echo "  ⚠ Some SymbolicEngine files missing (templates created)"
fi

echo ""
echo "Next Steps:"
echo "1. Implement missing .cpp files using the provided artifacts:"
for file in "${missing_symbolic[@]}"; do
    if [[ "$file" == *.cpp ]]; then
        echo "   - $file"
    fi
done

echo ""
echo "2. Build and test:"
echo "   make clean && make && make test"
echo ""
echo "3. Check generated outputs:"
echo "   - testgen_output.smt2 (SMT constraints)"
echo "   - concrete_test_values.txt (test values)"
echo ""
print_success "TestGen Symbolic Engine framework setup complete!"
