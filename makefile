
CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -I. -g -O2

CORE_SOURCES = test_libapplication.cpp jsCodeGenerator/jsCodeGen.cpp

SYMBOLIC_SOURCES = SymbolicEngine/TestGenSymbolicEnv.cpp SymbolicEngine/TestGenSymbolicVisitor.cpp SymbolicEngine/TestGenDriver.cpp

basic: testgen_basic

testgen_basic: $(CORE_SOURCES)

	$(CXX) $(CXXFLAGS) $^ -o $@

symbolic: testgen_symbolic

testgen_symbolic: $(CORE_SOURCES) $(SYMBOLIC_SOURCES)

	$(CXX) $(CXXFLAGS) -ISymbolicEngine -DUSE_SYMBOLIC_ENGINE $^ -o $@

clean:

	rm -f testgen_basic testgen_symbolic .o jsCodeGenerator/.o SymbolicEngine/*.o

help:

	@echo "make basic     - Build basic TestGen"

	@echo "make symbolic  - Build TestGen + SymbolicEngine"

.PHONY: basic symbolic clean help

