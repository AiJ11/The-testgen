# Unified Makefile for TestGen with optional SymbolicEngine
CXX = g++
BASE_CXXFLAGS = -std=c++17 -Wall -Wextra -I. -g -O2

# Core sources (always needed)
CORE_SOURCES = \
    test_libapplication.cpp \
    jsCodeGenerator/jsCodeGen.cpp

# SymbolicEngine sources (optional)
SYMBOLIC_SOURCES = \
    SymbolicEngine/TestGenSymbolicEnv.cpp \
    SymbolicEngine/TestGenSymbolicVisitor.cpp \
    SymbolicEngine/TestGenDriver.cpp

# Default target - build basic TestGen
all: basic

# Basic TestGen (no symbolic engine)
basic: testgen_basic

testgen_basic: $(CORE_SOURCES)
	@echo "Building basic TestGen (no symbolic engine)..."
	$(CXX) $(BASE_CXXFLAGS) $^ -o $@
	@echo "Built: $@"

# TestGen with SymbolicEngine  
symbolic: testgen_symbolic

testgen_symbolic: $(CORE_SOURCES) $(SYMBOLIC_SOURCES)
	@echo "Building TestGen with SymbolicEngine..."
	$(CXX) $(BASE_CXXFLAGS) -ISymbolicEngine -DUSE_SYMBOLIC_ENGINE $^ -o $@
	@echo "Built: $@"

# Run targets
run: testgen_basic
	./testgen_basic

run-symbolic: testgen_symbolic
	./testgen_symbolic

# Clean
clean:
	rm -f testgen_basic testgen_symbolic *.o jsCodeGenerator/*.o SymbolicEngine/*.o

help:
	@echo "Usage:"
	@echo "  make basic      - Build basic TestGen (standalone)"
	@echo "  make symbolic   - Build TestGen + SymbolicEngine"
	@echo "  make run        - Build and run basic TestGen"
	@echo "  make run-symbolic - Build and run with symbolic engine"

.PHONY: all basic symbolic run run-symbolic clean help
