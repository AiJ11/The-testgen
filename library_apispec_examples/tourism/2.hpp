#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <memory>
#include "../../ast.hpp"
#include "../../algo.hpp"


class tourism_example2 {
public:
    static void example(std::vector<std::unique_ptr<API>> &apis, SymbolTable &root) {
        // ================================
        // Step 1: RegisterUserOK
        // PRE:  email not_in dom(U)
        // CALL: register_user(email, password) ==> 201
        // POST: U[email] = password
        // ================================
        {
            // PRE
            std::vector<std::unique_ptr<Expr>> pre1_args;
            pre1_args.push_back(std::make_unique<Var>("email"));
            std::vector<std::unique_ptr<Expr>> dom_args;
            dom_args.push_back(std::make_unique<Var>("U"));
            pre1_args.push_back(std::make_unique<FuncCall>("dom", std::move(dom_args)));
            auto pre1 = std::make_unique<FuncCall>("not_in", std::move(pre1_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args1;
            args1.push_back(std::make_unique<Var>("email"));
            args1.push_back(std::make_unique<Var>("password"));
            auto call1 = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("register_user", std::move(args1)),
                Response(HTTPResponseCode::CREATED_201, nullptr)
            );

            // POST: [] (U, email) = password
            std::vector<std::unique_ptr<Expr>> post1_args, index1_args;
            index1_args.push_back(std::make_unique<Var>("U"));
            index1_args.push_back(std::make_unique<Var>("email"));
            post1_args.push_back(std::make_unique<FuncCall>("[]", std::move(index1_args)));
            post1_args.push_back(std::make_unique<Var>("password"));
            auto post1 = std::make_unique<FuncCall>("=", std::move(post1_args));

            apis.push_back(std::make_unique<API>(std::move(pre1), std::move(call1),
                        Response(HTTPResponseCode::CREATED_201, std::move(post1))));

            // Inputs for Step 1
            auto *c1 = new SymbolTable();
            c1->symtable.insert(Var("email"));
            c1->symtable.insert(Var("password"));
            root.children.push_back(c1);
        }

        // ================================
        // Step 2: LoginOK
        // PRE:  U[email] = password
        // CALL: login(email, password) ==> 200
        // POST: T[tokenVal] = email
        // ================================
        {
            // PRE
            std::vector<std::unique_ptr<Expr>> pre2_args, idx2_args;
            idx2_args.push_back(std::make_unique<Var>("U"));
            idx2_args.push_back(std::make_unique<Var>("email"));
            pre2_args.push_back(std::make_unique<FuncCall>("[]", std::move(idx2_args)));
            pre2_args.push_back(std::make_unique<Var>("password"));
            auto pre2 = std::make_unique<FuncCall>("=", std::move(pre2_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args2;
            args2.push_back(std::make_unique<Var>("email"));
            args2.push_back(std::make_unique<Var>("password"));
            auto call2 = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("login", std::move(args2)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: [] (T, tokenVal) = email
            std::vector<std::unique_ptr<Expr>> post2_args, idxT_args;
            idxT_args.push_back(std::make_unique<Var>("T"));
            idxT_args.push_back(std::make_unique<Var>("tokenVal"));
            post2_args.push_back(std::make_unique<FuncCall>("[]", std::move(idxT_args)));
            post2_args.push_back(std::make_unique<Var>("email"));
            auto post2 = std::make_unique<FuncCall>("=", std::move(post2_args));

            apis.push_back(std::make_unique<API>(std::move(pre2), std::move(call2),
                        Response(HTTPResponseCode::OK_200, std::move(post2))));

            // Inputs for Step 2
            auto *c2 = new SymbolTable();
            c2->symtable.insert(Var("email"));
            c2->symtable.insert(Var("password"));
            root.children.push_back(c2);
        }

        // ================================
        // Step 3: AddToWishlistOK(TourX)
        // PRE:  TourX in tourList
        // CALL: addToWishlist(TourX) ==> 200
        // POST: add_to_set(wishlist, TourX)
        // ================================
        {
            // PRE
            std::vector<std::unique_ptr<Expr>> pre3_args;
            pre3_args.push_back(std::make_unique<Var>("TourX"));
            pre3_args.push_back(std::make_unique<Var>("tourList"));
            auto pre3 = std::make_unique<FuncCall>("in", std::move(pre3_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args3;
            args3.push_back(std::make_unique<Var>("TourX"));
            auto call3 = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("addToWishlist", std::move(args3)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST
            std::vector<std::unique_ptr<Expr>> post3_args;
            post3_args.push_back(std::make_unique<Var>("wishlist"));
            post3_args.push_back(std::make_unique<Var>("TourX"));
            auto post3 = std::make_unique<FuncCall>("add_to_set", std::move(post3_args));

            apis.push_back(std::make_unique<API>(std::move(pre3), std::move(call3),
                        Response(HTTPResponseCode::OK_200, std::move(post3))));

            // Inputs for Step 3
            auto *c3 = new SymbolTable();
            c3->symtable.insert(Var("TourX"));
            root.children.push_back(c3);
        }

        // ================================
        // Step 4: RemoveFromWishlistOK(TourX)
        // PRE:  TourX in wishlist
        // CALL: removeFromWishlist(TourX) ==> 200
        // POST: remove_from_set(wishlist, TourX)
        // ================================
        {
            // PRE
            std::vector<std::unique_ptr<Expr>> pre4_args;
            pre4_args.push_back(std::make_unique<Var>("TourX"));
            pre4_args.push_back(std::make_unique<Var>("wishlist"));
            auto pre4 = std::make_unique<FuncCall>("in", std::move(pre4_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args4;
            args4.push_back(std::make_unique<Var>("TourX"));
            auto call4 = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("removeFromWishlist", std::move(args4)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST
            std::vector<std::unique_ptr<Expr>> post4_args;
            post4_args.push_back(std::make_unique<Var>("wishlist"));
            post4_args.push_back(std::make_unique<Var>("TourX"));
            auto post4 = std::make_unique<FuncCall>("remove_from_set", std::move(post4_args));

            apis.push_back(std::make_unique<API>(std::move(pre4), std::move(call4),
                        Response(HTTPResponseCode::OK_200, std::move(post4))));

            // Inputs for Step 4
            auto *c4 = new SymbolTable();
            c4->symtable.insert(Var("TourX"));
            root.children.push_back(c4);
        }
    }
};
