#include <iostream>
#include <cassert>
#include <memory>
#include <fstream>
#include "jsCodeGenerator/jsCodeGen.h"
#include "ast.hpp"
#include "algo.hpp"
#include "library_apispec_examples/Entry.hpp"
#include "./symbol_table.hpp"
#include "parser.hpp"  // Add this new include
using namespace std;

void test_manual_examples(){
    // Your existing manual test functionality
    auto res=Entry::start();
    auto spec = std::move(res.first);
    auto symtable=res.second;
    PrintVisitor visitor;
    spec->accept(visitor);
    Program p = convert(spec.get(), symtable);
    p.accept(visitor);
    ExpoSECodeGenerator ecg;

    cout<<"generating expoSE code:\n";
    string code = ecg.generateCode(p);
    cout << code;
}

void test_parser_integration(){
    cout << "=== TESTING PARSER INTEGRATION ===" << endl;
    
    // Test with file input
    ifstream file("library_spec.txt");
    if (!file) {
        cerr << "Error: Could not open library_spec.txt" << endl;
        return;
    }
    
    // Parse the specification
    auto spec = parse_spec(file);
    if (!spec) {
        cerr << "Error: Failed to parse specification" << endl;
        return;
    }
    
    cout << "Successfully parsed specification!" << endl;
    
    // Print the parsed AST
    PrintVisitor visitor;
    cout << "\n=== PARSED AST ===" << endl;
    spec->accept(visitor);
    
    // Create symbol table (simplified version)
    SymbolTable rootSymtable;
    for (const auto& global : spec->globals) {
        rootSymtable.symtable.insert(Var(global->name));
    }
    
    // Create child symbol tables for API blocks
    for (size_t i = 0; i < spec->blocks.size(); i++) {
        SymbolTable* childSymtable = new SymbolTable();
        childSymtable->par = &rootSymtable;
        
        if (spec->blocks[i]->call && spec->blocks[i]->call->call) {
            for (const auto& arg : spec->blocks[i]->call->call->args) {
                if (auto var = dynamic_cast<Var*>(arg.get())) {
                    childSymtable->symtable.insert(Var(var->name));
                }
            }
        }
        rootSymtable.children.push_back(childSymtable);
    }
    
    // Convert to Program
    cout << "\n=== CONVERSION ===" << endl;
    Program p = convert(spec.get(), rootSymtable);
    cout << "Converted to Program with " << p.statements.size() << " statements" << endl;
    
    // Print Program
    cout << "\n=== PROGRAM AST ===" << endl;
    p.accept(visitor);
    
    // Generate ExpoSE code
    cout << "\n=== JAVASCRIPT GENERATION ===" << endl;
    ExpoSECodeGenerator ecg;
    string code = ecg.generateCode(p);
    cout << code << endl;
    
    // Clean up
    for (auto* child : rootSymtable.children) {
        delete child;
    }
}

int main(int argc, char* argv[]){
    if (argc > 1 && string(argv[1]) == "parser") {
        test_parser_integration();
    } else {
        test_manual_examples();
    }
    return 0;
}
