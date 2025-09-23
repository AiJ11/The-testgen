// TestGenSymbolicVisitor.hpp
#pragma once
#include "../ASTVis.hpp"
#include "../ast.hpp"
#include "TestGenSymbolicEnv.hpp"
#include <string>
#include <vector>

/*
 * Symbolic visitor for TestGen output
 * Handles TestGen function names: AND, OR, inMapVerify, equals, etc.
 */
class TestGenSymbolicVisitor : public ASTVisitor {
public:
    explicit TestGenSymbolicVisitor(TestGenSymbolicEnv& env, bool debugMode = false)
        : env(env), debugMode(debugMode) {}

    // Main statement visitors
    void visit(const Assign& n)       override;
    void visit(const FuncCallStmt& n) override;
    void visit(const Program& n)      override;

    // Expression visitors (used by smtOf function)
    void visit(const Var& n)      override;
    void visit(const FuncCall& n) override;
    void visit(const Num& n)      override;
    void visit(const String& n)   override;

    // Unused visitors (stubbed out)
    void visit(const Set&)        override {}
    void visit(const Map&)        override {}
    void visit(const Tuple&)      override {}
    void visit(const TypeConst&)  override {}
    void visit(const FuncType&)   override {}
    void visit(const MapType&)    override {}
    void visit(const TupleType&)  override {}
    void visit(const SetType&)    override {}
    void visit(const Decl&)       override {}
    void visit(const FuncDecl&)   override {}
    void visit(const APIcall&)    override {}
    void visit(const API&)        override {}
    void visit(const Response&)   override {}
    void visit(const Init&)       override {}
    void visit(const Spec&)       override {}

    void setDebug(bool debug) { debugMode = debug; }

    // Convert TestGen expression to SMT-LIB string
    std::string exprToSMT(const Expr& expr);

private:
    TestGenSymbolicEnv& env;
    bool debugMode = false;
    
    // Helper for recursive SMT conversion
    std::string convertExprToSMT(const Expr& expr);
};
