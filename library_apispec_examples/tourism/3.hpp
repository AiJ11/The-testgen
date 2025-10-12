#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "../../ast.hpp"
#include "../../algo.hpp"

using namespace std;

class tourism_example3 {
public:
    static void example(vector<unique_ptr<API>> &apis, SymbolTable &root) {
        // ==========================================
        // 1) LoginOK
        // PRE:  U[email] = password
        // CALL: login(email, password) ==> 200
        // POST: T[tokenVal] = email
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre_args, idx;
            idx.push_back(make_unique<Var>("U"));
            idx.push_back(make_unique<Var>("email"));
            pre_args.push_back(make_unique<FuncCall>("[]", move(idx)));
            pre_args.push_back(make_unique<Var>("password"));
            auto pre = make_unique<FuncCall>("=", move(pre_args));

            // CALL
            vector<unique_ptr<Expr>> call_args;
            call_args.push_back(make_unique<Var>("email"));
            call_args.push_back(make_unique<Var>("password"));
            auto call = make_unique<APIcall>(
                make_unique<FuncCall>("login", move(call_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: T[tokenVal] = email
            vector<unique_ptr<Expr>> post_args, post_idx;
            post_idx.push_back(make_unique<Var>("T"));
            post_idx.push_back(make_unique<Var>("tokenVal"));
            post_args.push_back(make_unique<FuncCall>("[]", move(post_idx)));
            post_args.push_back(make_unique<Var>("email"));
            auto post = make_unique<FuncCall>("=", move(post_args));

            apis.push_back(make_unique<API>(move(pre), move(call),
                        Response(HTTPResponseCode::OK_200, move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("email"));
            c->symtable.insert(Var("password"));
            root.children.push_back(c);
        }

        // ==========================================
        // 2) BrowseToursOK
        // PRE:  (t in T) AND (U[ T[t] ] exists)
        // CALL: browseTours(t) ==> 200
        // POST: tourList = Tours
        // ==========================================
        {
            // PRE: inMapVerify(T, t) && inMapVerify(U, T[t])
            vector<unique_ptr<Expr>> lhs, rhs, both;
            lhs.push_back(make_unique<Var>("T"));
            lhs.push_back(make_unique<Var>("t"));
            auto inT = make_unique<FuncCall>("inMapVerify", move(lhs));

            vector<unique_ptr<Expr>> tIdx;
            tIdx.push_back(make_unique<Var>("T"));
            tIdx.push_back(make_unique<Var>("t"));
            auto Tt = make_unique<FuncCall>("[]", move(tIdx));

            rhs.push_back(make_unique<Var>("U"));
            rhs.push_back(move(Tt));
            auto inUofTt = make_unique<FuncCall>("inMapVerify", move(rhs));

            both.push_back(move(inT));
            both.push_back(move(inUofTt));
            auto pre = make_unique<FuncCall>("AND", move(both));

            // CALL
            vector<unique_ptr<Expr>> call_args;
            call_args.push_back(make_unique<Var>("t"));
            auto call = make_unique<APIcall>(
                make_unique<FuncCall>("browseTours", move(call_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: tourList = Tours
            vector<unique_ptr<Expr>> post_args;
            post_args.push_back(make_unique<Var>("tourList"));
            post_args.push_back(make_unique<Var>("Tours"));
            auto post = make_unique<FuncCall>("equals", move(post_args));

            apis.push_back(make_unique<API>(move(pre), move(call),
                        Response(HTTPResponseCode::OK_200, move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("t"));
            root.children.push_back(c);
        }

        // ==========================================
        // 3) GetTourDetailsOK(TourId)
        // PRE:  TourId in Tours
        // CALL: getTourDetails(t, TourId) ==> 200
        // POST: tourDetails[TourId] = TD
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre_args;
            pre_args.push_back(make_unique<Var>("TourId"));
            pre_args.push_back(make_unique<Var>("Tours"));
            auto pre = make_unique<FuncCall>("in", move(pre_args));

            // CALL
            vector<unique_ptr<Expr>> call_args;
            call_args.push_back(make_unique<Var>("t2"));
            call_args.push_back(make_unique<Var>("TourId"));
            auto call = make_unique<APIcall>(
                make_unique<FuncCall>("getTourDetails", move(call_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: tourDetails[TourId] = TD
            vector<unique_ptr<Expr>> post_args, post_idx;
            post_idx.push_back(make_unique<Var>("tourDetails"));
            post_idx.push_back(make_unique<Var>("TourId"));
            post_args.push_back(make_unique<FuncCall>("[]", move(post_idx)));
            post_args.push_back(make_unique<Var>("TD"));
            auto post = make_unique<FuncCall>("=", move(post_args));

            apis.push_back(make_unique<API>(move(pre), move(call),
                        Response(HTTPResponseCode::OK_200, move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("t2"));
            c->symtable.insert(Var("TourId"));
            // TD is produced by server; not input
            root.children.push_back(c);
        }

        // ==========================================
        // 4) AddToCartOK(TourId)
        // PRE:  TourId in Tours
        // CALL: addToCart(t, TourId) ==> 200
        // POST: add_to_set(cart, TourId)
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre_args;
            pre_args.push_back(make_unique<Var>("TourId"));
            pre_args.push_back(make_unique<Var>("Tours"));
            auto pre = make_unique<FuncCall>("in", move(pre_args));

            // CALL
            vector<unique_ptr<Expr>> call_args;
            call_args.push_back(make_unique<Var>("t3"));
            call_args.push_back(make_unique<Var>("TourId"));
            auto call = make_unique<APIcall>(
                make_unique<FuncCall>("addToCart", move(call_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST
            vector<unique_ptr<Expr>> post_args;
            post_args.push_back(make_unique<Var>("cart"));
            post_args.push_back(make_unique<Var>("TourId"));
            auto post = make_unique<FuncCall>("add_to_set", move(post_args));

            apis.push_back(make_unique<API>(move(pre), move(call),
                        Response(HTTPResponseCode::OK_200, move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("t3"));
            c->symtable.insert(Var("TourId"));
            root.children.push_back(c);
        }

        // ==========================================
        // 5) PlaceOrderOK(OrderX)
        // PRE:  not_empty(cart)
        // CALL: placeOrder(t, OrderX) ==> 201
        // POST: orders[OrderX] = cart
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre_args;
            pre_args.push_back(make_unique<Var>("cart"));
            auto pre = make_unique<FuncCall>("not_empty", move(pre_args));

            // CALL
            vector<unique_ptr<Expr>> call_args;
            call_args.push_back(make_unique<Var>("t4"));
            call_args.push_back(make_unique<Var>("OrderX"));
            auto call = make_unique<APIcall>(
                make_unique<FuncCall>("placeOrder", move(call_args)),
                Response(HTTPResponseCode::CREATED_201, nullptr)
            );

            // POST: orders[OrderX] = cart
            vector<unique_ptr<Expr>> post_args, post_idx;
            post_idx.push_back(make_unique<Var>("orders"));
            post_idx.push_back(make_unique<Var>("OrderX"));
            post_args.push_back(make_unique<FuncCall>("[]", move(post_idx)));
            post_args.push_back(make_unique<Var>("cart"));
            auto post = make_unique<FuncCall>("=", move(post_args));

            apis.push_back(make_unique<API>(move(pre), move(call),
                        Response(HTTPResponseCode::CREATED_201, move(post))));

            auto *c = new SymbolTable();
            c->symtable.insert(Var("t4"));
            c->symtable.insert(Var("OrderX"));
            root.children.push_back(c);
        }
    }
};
