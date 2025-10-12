#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <memory>
#include "../../ast.hpp"
#include "../../algo.hpp"

class tourism_example4 {
public:
    static void example(std::vector<std::unique_ptr<API>> &apis, SymbolTable &root) {
        // ================================
        // Step 1: LoginOK
        // PRE:  U[email] = password
        // CALL: login(email, password) ==> 200
        // POST: T[tokenVal] = email
        // ================================
        {
            // PRE
            std::vector<std::unique_ptr<Expr>> pre_args, idx_args;
            idx_args.push_back(std::make_unique<Var>("U"));
            idx_args.push_back(std::make_unique<Var>("email"));
            pre_args.push_back(std::make_unique<FuncCall>("[]", std::move(idx_args)));
            pre_args.push_back(std::make_unique<Var>("password"));
            auto pre = std::make_unique<FuncCall>("=", std::move(pre_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args;
            args.push_back(std::make_unique<Var>("email"));
            args.push_back(std::make_unique<Var>("password"));
            auto call = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("login", std::move(args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: [] (T, tokenVal) = email
            std::vector<std::unique_ptr<Expr>> post_args, idxT_args;
            idxT_args.push_back(std::make_unique<Var>("T"));
            idxT_args.push_back(std::make_unique<Var>("tokenVal"));
            post_args.push_back(std::make_unique<FuncCall>("[]", std::move(idxT_args)));
            post_args.push_back(std::make_unique<Var>("email"));
            auto post = std::make_unique<FuncCall>("=", std::move(post_args));

            apis.push_back(std::make_unique<API>(std::move(pre), std::move(call),
                        Response(HTTPResponseCode::OK_200, std::move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("email"));
            c->symtable.insert(Var("password"));
            root.children.push_back(c);
        }

        // ================================
        // Step 2: ApplyCouponOK
        // PRE:  not_empty(cart) AND (coupon in validCoupons)
        // CALL: applyCoupon(coupon) ==> 200
        // POST: add_to_set(appliedCoupons, coupon)
        // ================================
        {
            // PRE: and(not_empty(cart), in(coupon, validCoupons))
            std::vector<std::unique_ptr<Expr>> notEmpty_args;
            notEmpty_args.push_back(std::make_unique<Var>("cart"));
            auto notEmpty = std::make_unique<FuncCall>("not_empty", std::move(notEmpty_args));

            std::vector<std::unique_ptr<Expr>> in_args;
            in_args.push_back(std::make_unique<Var>("coupon"));
            in_args.push_back(std::make_unique<Var>("validCoupons"));
            auto inCheck = std::make_unique<FuncCall>("in", std::move(in_args));

            std::vector<std::unique_ptr<Expr>> and_args;
            and_args.push_back(std::move(notEmpty));
            and_args.push_back(std::move(inCheck));
            auto pre = std::make_unique<FuncCall>("AND", std::move(and_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args;
            args.push_back(std::make_unique<Var>("coupon"));
            auto call = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("applyCoupon", std::move(args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST
            std::vector<std::unique_ptr<Expr>> post_args;
            post_args.push_back(std::make_unique<Var>("appliedCoupons"));
            post_args.push_back(std::make_unique<Var>("coupon"));
            auto post = std::make_unique<FuncCall>("add_to_set", std::move(post_args));

            apis.push_back(std::make_unique<API>(std::move(pre), std::move(call),
                        Response(HTTPResponseCode::OK_200, std::move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("coupon"));
            root.children.push_back(c);
        }

        // ================================
        // Step 3: RemoveFromCartOK(TourZ)
        // PRE:  TourZ in cart
        // CALL: removeFromCart(TourZ) ==> 200
        // POST: remove_from_set(cart, TourZ)
        // ================================
        {
            // PRE
            std::vector<std::unique_ptr<Expr>> pre_args;
            pre_args.push_back(std::make_unique<Var>("TourZ"));
            pre_args.push_back(std::make_unique<Var>("cart"));
            auto pre = std::make_unique<FuncCall>("in", std::move(pre_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args;
            args.push_back(std::make_unique<Var>("TourZ"));
            auto call = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("removeFromCart", std::move(args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST
            std::vector<std::unique_ptr<Expr>> post_args;
            post_args.push_back(std::make_unique<Var>("cart"));
            post_args.push_back(std::make_unique<Var>("TourZ"));
            auto post = std::make_unique<FuncCall>("remove_from_set", std::move(post_args));

            apis.push_back(std::make_unique<API>(std::move(pre), std::move(call),
                        Response(HTTPResponseCode::OK_200, std::move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("TourZ"));
            root.children.push_back(c);
        }

        // ================================
        // Step 4: PlaceOrderOK
        // PRE:  not_empty(cart)
        // CALL: placeOrder(OrderRef) ==> 201
        // POST: orders[OrderRef] = cart
        // ================================
        {
            // PRE
            std::vector<std::unique_ptr<Expr>> pre_args;
            pre_args.push_back(std::make_unique<Var>("cart"));
            auto pre = std::make_unique<FuncCall>("not_empty", std::move(pre_args));

            // CALL
            std::vector<std::unique_ptr<Expr>> args;
            args.push_back(std::make_unique<Var>("OrderRef"));
            auto call = std::make_unique<APIcall>(
                std::make_unique<FuncCall>("placeOrder", std::move(args)),
                Response(HTTPResponseCode::CREATED_201, nullptr)
            );

            // POST
            std::vector<std::unique_ptr<Expr>> post_args, idx_args;
            idx_args.push_back(std::make_unique<Var>("orders"));
            idx_args.push_back(std::make_unique<Var>("OrderRef"));
            post_args.push_back(std::make_unique<FuncCall>("[]", std::move(idx_args)));
            post_args.push_back(std::make_unique<Var>("cart"));
            auto post = std::make_unique<FuncCall>("=", std::move(post_args));

            apis.push_back(std::make_unique<API>(std::move(pre), std::move(call),
                        Response(HTTPResponseCode::CREATED_201, std::move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("OrderRef"));
            root.children.push_back(c);
        }
    }
};
