// TestGenSymbolicVisitor.cpp
#include "TestGenSymbolicVisitor.hpp"
#include <sstream>
#include <stdexcept>

void TestGenSymbolicVisitor::visit(const Assign& n) {
    // Handle assignments like: x = input() or x = fresh()
    const std::string varName = n.left->name;
    
    if (auto* funcCall = dynamic_cast<const FuncCall*>(n.right.get())) {
        if (funcCall->name == "input" && funcCall->args.empty()) {
            // This is an input variable declaration
            env.addInputVariable(varName);
            if (debugMode) {
                std::cout << "[TestGenSymbolic] Input variable: " << varName << std::endl;
            }
        } else {
            // Other assignments - convert RHS to SMT
            std::string rhsSMT = convertExprToSMT(*n.right);
            std::string lhsSymbol = env.getSymbolFor(varName);
            env.addConstraint("(= " + lhsSymbol + " " + rhsSMT + ")");
        }
    }
}

void TestGenSymbolicVisitor::visit(const FuncCallStmt& n) {
    if (!n.call) return;
    
    const std::string& funcName = n.call->name;
    
    if (funcName == "assume" && !n.call->args.empty()) {
        // Convert assumption to SMT constraint
        std::string constraint = convertExprToSMT(*n.call->args[0]);
        env.addConstraint(constraint);
        
        if (debugMode) {
            std::cout << "[TestGenSymbolic] Added assumption: " << constraint << std::endl;
        }
    }
    else if (funcName == "assert" && !n.call->args.empty()) {
        // Convert assertion to SMT constraint
        std::string constraint = convertExprToSMT(*n.call->args[0]);
        env.addConstraint(constraint);
        
        if (debugMode) {
            std::cout << "[TestGenSymbolic] Added assertion: " << constraint << std::endl;
        }
    }
    else if (funcName == "input" && n.call->args.size() == 1) {
        // Handle input statements: input(varName)
        if (auto* var = dynamic_cast<const Var*>(n.call->args[0].get())) {
            env.addInputVariable(var->name);
            if (debugMode) {
                std::cout << "[TestGenSymbolic] Input variable: " << var->name << std::endl;
            }
        }
    }

    else if (funcName == "=" && n.call->args.size() == 2) {
    if (auto* lhs = dynamic_cast<const Var*>(n.call->args[0].get())) {
        if (auto* rhs = dynamic_cast<const Var*>(n.call->args[1].get())) {
            const auto& L = env.declareMap(lhs->name);
            const auto& R = env.declareMap(rhs->name);
            std::string c = "(and (= " + L.domainArray + " " + R.domainArray + ")"
                                 " (= " + L.valueArray  + " " + R.valueArray  + "))";
            env.addConstraint(c);
            if (debugMode) std::cout << "[TestGenSymbolic] Map assign: " << c << "\n";
            return;
        }
    }
    // Fallback to scalar equality
    std::string c = "(= " + convertExprToSMT(*n.call->args[0]) + " " + convertExprToSMT(*n.call->args[1]) + ")";
    env.addConstraint(c);
    if (debugMode) std::cout << "[TestGenSymbolic] Scalar assign: " << c << "\n";
    return;
}

    else if (funcName != "assume" && funcName != "assert" && funcName != "input") {
        // This is an API call - we don't generate constraints for it but note it
        if (debugMode) {
            std::cout << "[TestGenSymbolic] API call: " << funcName << std::endl;
        }
    }
}

void TestGenSymbolicVisitor::visit(const Program& n) {
    if (debugMode) {
        std::cout << "[TestGenSymbolic] Processing program with " 
                  << n.statements.size() << " statements" << std::endl;
    }
    
    for (const auto& stmt : n.statements) {
        stmt->accept(*this);
    }
}

// Stub implementations for expression visitors (used by convertExprToSMT)
void TestGenSymbolicVisitor::visit(const Var& n) {
    // This gets called from convertExprToSMT
}
void TestGenSymbolicVisitor::visit(const FuncCall& n) {
    // This gets called from convertExprToSMT  
}
void TestGenSymbolicVisitor::visit(const Num& n) {
    // This gets called from convertExprToSMT
}
void TestGenSymbolicVisitor::visit(const String& n) {
    // This gets called from convertExprToSMT
}

std::string TestGenSymbolicVisitor::exprToSMT(const Expr& expr) {
    return convertExprToSMT(expr);
}

std::string TestGenSymbolicVisitor::convertExprToSMT(const Expr& expr) {
    // Handle variables
    if (auto* var = dynamic_cast<const Var*>(&expr)) {
        // Special handling for boolean literals
        if (var->name == "true" || var->name == "false") {
            return var->name;
        }
        // Map variables - check if they need to be declared
        if (var->name == "U" || var->name == "S" || var->name == "T" || 
            var->name == "B" || var->name == "R" || var->name == "BS") {
            env.declareMap(var->name);
        }
        return env.getSymbolFor(var->name);
    }
    
    // Handle numbers
    if (auto* num = dynamic_cast<const Num*>(&expr)) {
        return std::to_string(num->value);
    }
    
    // Handle strings
    if (auto* str = dynamic_cast<const String*>(&expr)) {
        return "\"" + str->value + "\"";
    }
    
    // Handle function calls (the main logic)
    if (auto* funcCall = dynamic_cast<const FuncCall*>(&expr)) {
        const std::string& name = funcCall->name;
        
        // Boolean operators
        if (name == "AND" && funcCall->args.size() >= 2) {
            std::ostringstream result;
            result << "(and";
            for (const auto& arg : funcCall->args) {
                result << " " << convertExprToSMT(*arg);
            }
            result << ")";
            return result.str();
        }
        
        if (name == "OR" && funcCall->args.size() >= 2) {
            std::ostringstream result;
            result << "(or";
            for (const auto& arg : funcCall->args) {
                result << " " << convertExprToSMT(*arg);
            }
            result << ")";
            return result.str();
        }
        
        // Equality
if (name == "equals" && funcCall->args.size() == 2) {
    // Pattern: equals( Var("S"), Union(Var("S_old"), idExpr) )
    if (auto* leftVar = dynamic_cast<const Var*>(funcCall->args[0].get())) {
        if (auto* unionCall = dynamic_cast<const FuncCall*>(funcCall->args[1].get())) {
            if (unionCall->name == "Union" && unionCall->args.size() == 2) {
                if (auto* baseMapVar = dynamic_cast<const Var*>(unionCall->args[0].get())) {
                    const auto& S    = env.declareMap(leftVar->name);       // "S"
                    const auto& Sold = env.declareMap(baseMapVar->name);    // "S_old"
                    std::string idExpr = convertExprToSMT(*unionCall->args[1]);

                    std::ostringstream r;
                    // If Union means "add key to domain, keep values same"
                    r << "(and (= " << S.domainArray << " (store " << Sold.domainArray << " " << idExpr << " true))"
                      << " (= " << S.valueArray  << " " << Sold.valueArray  << "))";
                    return r.str();
                }
            }
        }
    }
    // fallback: scalar equality
    return "(= " + convertExprToSMT(*funcCall->args[0]) + " " + convertExprToSMT(*funcCall->args[1]) + ")";
}

        
        // Map operations
        if (name == "inMapVerify" && funcCall->args.size() == 2) {
    // Case 1: (map, key)
    if (auto* mapVar = dynamic_cast<const Var*>(funcCall->args[0].get())) {
        // Declare map by the *actual* name you see (T, U, S, S_old, ...)
        const auto& mi = env.declareMap(mapVar->name);
        std::string keyExpr = convertExprToSMT(*funcCall->args[1]);
        return "(select " + mi.domainArray + " " + keyExpr + ")";
    }
    // Case 2: (key, map)
    if (auto* mapVar = dynamic_cast<const Var*>(funcCall->args[1].get())) {
        const auto& mi = env.declareMap(mapVar->name);
        std::string keyExpr = convertExprToSMT(*funcCall->args[0]);
        return "(select " + mi.domainArray + " " + keyExpr + ")";
    }
    // Fallback: don't invent "<expr>_domain"—return a benign tautology instead
    if (debugMode) std::cout << "[TestGenSymbolic] WARN: inMapVerify on non-var map\n";
    return "true";
}

        
        if (name == "mapAccess" && funcCall->args.size() == 2) {
            // mapAcess(map, key) -> get value from map
            std::string mapExpr = convertExprToSMT(*funcCall->args[0]);
            std::string keyExpr = convertExprToSMT(*funcCall->args[1]);
            
            if (auto* mapVar = dynamic_cast<const Var*>(funcCall->args[0].get())) {
                if (env.isMap(mapVar->name)) {
                    const auto& mapInfo = env.getMapInfo(mapVar->name);
                    return "(select " + mapInfo.valueArray + " " + keyExpr + ")";
                }
            }
            
            return "(select " + mapExpr + "_values " + keyExpr + ")";
        }
        
        // Field access functions
        if (name == "getId" && funcCall->args.size() == 1) {
            // For now, treat as identity function ,may need to adjust this
            // based on the domain model
            return convertExprToSMT(*funcCall->args[0]);
        }
        
        if (name == "getRoles" && funcCall->args.size() == 1) {
            // Similar to getId, may need domain-specific handling
            return convertExprToSMT(*funcCall->args[0]);
        }
        
        // Set operations
        if (name == "inList" && funcCall->args.size() == 2) {
            // inList(element, set) -> check membership
            return "(select " + convertExprToSMT(*funcCall->args[1]) + " " + 
                              convertExprToSMT(*funcCall->args[0]) + ")";
        }
        
        // Input/fresh
        if (name == "input" && funcCall->args.empty()) {
            return env.createFreshSymbol("input");
        }
        
        if (name == "fresh" && funcCall->args.empty()) {
            return env.createFreshSymbol("fresh");
        }
        
        // Dash operator (primed variables)
        if (name == "'" && funcCall->args.size() == 1) {
            // Handle primed variables like S'
            if (auto* var = dynamic_cast<const Var*>(funcCall->args[0].get())) {
                return env.getSymbolFor(var->name + "_prime");
            }
            return convertExprToSMT(*funcCall->args[0]) + "_prime";
        }
        
        // Set operations
        if (name == "\\" && funcCall->args.size() == 2) {
            // Set difference - may need specific encoding
            return "(set_minus " + convertExprToSMT(*funcCall->args[0]) + " " + 
                                  convertExprToSMT(*funcCall->args[1]) + ")";
        }
        
        //if (name == "Union" && funcCall->args.size() == 2) {
           // return "(set_union " + convertExprToSMT(*funcCall->args[0]) + " " + 
                            //      convertExprToSMT(*funcCall->args[1]) + ")";
        //}
        if (name == "Union") {
    // Should be handled inside equals(S, Union(...)).
    if (debugMode) std::cout << "[TestGenSymbolic] WARN: standalone Union encountered\n";
    // Conservative fallback: just return the base map expression unchanged
    // (keeps SMT valid; semantics come from the equals pattern above).
    return convertExprToSMT(*funcCall->args[0]);
}

        
        // Default: uninterpreted function
        std::ostringstream result;
        result << "(" << name;
        for (const auto& arg : funcCall->args) {
            result << " " << convertExprToSMT(*arg);
        }
        result << ")";
        return result.str();
    }
    
    throw std::runtime_error("Unsupported expression type in convertExprToSMT");
}
