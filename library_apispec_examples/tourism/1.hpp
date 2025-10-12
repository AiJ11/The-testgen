#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "../../ast.hpp"
#include "../../algo.hpp"

using namespace std;

class tourism_example1 {
public:
    static void example(vector<unique_ptr<API>> &apis, SymbolTable &root) {
        // =========================================================
        // 1) LOGIN_OK
        // PRE:   U[email] = password
        // CALL:  login(email, password) ==> 200
        // POST:  T[tokenVal] = email
        // =========================================================
        {
            // PRE: [] (U, email) = password
            vector<unique_ptr<Expr>> pre1_args, idx1_args;
            idx1_args.push_back(make_unique<Var>("U"));
            idx1_args.push_back(make_unique<Var>("email"));
            pre1_args.push_back(make_unique<FuncCall>("[]", move(idx1_args)));
            pre1_args.push_back(make_unique<Var>("password"));
            auto pre1 = make_unique<FuncCall>("=", move(pre1_args));

            // CALL: login(email, password) -> 200
            vector<unique_ptr<Expr>> call1_args;
            call1_args.push_back(make_unique<Var>("email"));
            call1_args.push_back(make_unique<Var>("password"));
            auto call1 = make_unique<APIcall>(
                make_unique<FuncCall>("login", move(call1_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: [] (T, tokenVal) = email
            vector<unique_ptr<Expr>> post1_args, post1_index;
            post1_index.push_back(make_unique<Var>("T"));
            post1_index.push_back(make_unique<Var>("tokenVal"));
            post1_args.push_back(make_unique<FuncCall>("[]", move(post1_index)));
            post1_args.push_back(make_unique<Var>("email"));
            auto post1 = make_unique<FuncCall>("=", move(post1_args));

            apis.push_back(make_unique<API>(move(pre1), move(call1),
                        Response(HTTPResponseCode::OK_200, move(post1))));

            // Per-API inputs
            auto *c1 = new SymbolTable();
            c1->symtable.insert(Var("email"));
            c1->symtable.insert(Var("password"));
            root.children.push_back(c1);
        }

        // =========================================================
        // 2) BROWSE_TOURS_OK
        // PRE:   (t in T) AND ( [] (U, [] (T, t)) = [] (T, t) )  // i.e., T[t] exists in U
        // CALL:  browseTours(t) ==> 200
        // POST:  tourList = Tours
        // =========================================================
        {
            // PRE:
            // inMapVerify(T, t)
            vector<unique_ptr<Expr>> inT_args;
            inT_args.push_back(make_unique<Var>("T"));
            inT_args.push_back(make_unique<Var>("t"));
            auto inT = make_unique<FuncCall>("inMapVerify", move(inT_args));

            // [] (T, t)
            vector<unique_ptr<Expr>> tlookup_args;
            tlookup_args.push_back(make_unique<Var>("T"));
            tlookup_args.push_back(make_unique<Var>("t"));
            auto tlookup = make_unique<FuncCall>("[]", move(tlookup_args));

            // inMapVerify(U, [] (T, t))
            vector<unique_ptr<Expr>> inU_args;
            inU_args.push_back(make_unique<Var>("U"));
            inU_args.push_back(move(tlookup));
            auto inU = make_unique<FuncCall>("inMapVerify", move(inU_args));

            // AND(inT, inU)
            vector<unique_ptr<Expr>> pre2_args;
            pre2_args.push_back(move(inT));
            pre2_args.push_back(move(inU));
            auto pre2 = make_unique<FuncCall>("AND", move(pre2_args));

            // CALL: browseTours(t)
            vector<unique_ptr<Expr>> call2_args;
            call2_args.push_back(make_unique<Var>("t"));
            auto call2 = make_unique<APIcall>(
                make_unique<FuncCall>("browseTours", move(call2_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: tourList = Tours
            vector<unique_ptr<Expr>> post2_args;
            post2_args.push_back(make_unique<Var>("tourList"));
            post2_args.push_back(make_unique<Var>("Tours"));
            auto post2 = make_unique<FuncCall>("equals", move(post2_args));

            apis.push_back(make_unique<API>(move(pre2), move(call2),
                        Response(HTTPResponseCode::OK_200, move(post2))));

            // Per-API inputs
            auto *c2 = new SymbolTable();
            c2->symtable.insert(Var("t"));
            root.children.push_back(c2);
        }

        // =========================================================
        // 3) SELECT_TOUR_OK (Tour3)
        // PRE:   Tour3 in Tours
        // CALL:  selectTour(t, Tour3) ==> 200
        // POST:  add_to_set(cart, Tour3)
        // =========================================================
        {
            // PRE: in(Tour3, Tours)
            vector<unique_ptr<Expr>> pre3_args;
            pre3_args.push_back(make_unique<Var>("Tour3"));
            pre3_args.push_back(make_unique<Var>("Tours"));
            auto pre3 = make_unique<FuncCall>("in", move(pre3_args));

            // CALL: selectTour(t, Tour3)
            vector<unique_ptr<Expr>> call3_args;
            call3_args.push_back(make_unique<Var>("t"));
            call3_args.push_back(make_unique<Var>("Tour3"));
            auto call3 = make_unique<APIcall>(
                make_unique<FuncCall>("selectTour", move(call3_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: add_to_set(cart, Tour3)
            vector<unique_ptr<Expr>> post3_args;
            post3_args.push_back(make_unique<Var>("cart"));
            post3_args.push_back(make_unique<Var>("Tour3"));
            auto post3 = make_unique<FuncCall>("add_to_set", move(post3_args));

            apis.push_back(make_unique<API>(move(pre3), move(call3),
                        Response(HTTPResponseCode::OK_200, move(post3))));

            // Per-API inputs
            auto *c3 = new SymbolTable();
            c3->symtable.insert(Var("t"));
            c3->symtable.insert(Var("Tour3"));
            root.children.push_back(c3);
        }

        // =========================================================
        // 4) ADD_TO_CART_OK (Tour3)
        // PRE:   Tour3 in Tours
        // CALL:  addToCart(t, Tour3) ==> 200
        // POST:  add_to_set(cart, Tour3)
        // =========================================================
        {
            // PRE: in(Tour3, Tours)
            vector<unique_ptr<Expr>> pre4_args;
            pre4_args.push_back(make_unique<Var>("Tour3"));
            pre4_args.push_back(make_unique<Var>("Tours"));
            auto pre4 = make_unique<FuncCall>("in", move(pre4_args));

            // CALL: addToCart(t, Tour3)
            vector<unique_ptr<Expr>> call4_args;
            call4_args.push_back(make_unique<Var>("t"));
            call4_args.push_back(make_unique<Var>("Tour3"));
            auto call4 = make_unique<APIcall>(
                make_unique<FuncCall>("addToCart", move(call4_args)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: add_to_set(cart, Tour3)
            vector<unique_ptr<Expr>> post4_args;
            post4_args.push_back(make_unique<Var>("cart"));
            post4_args.push_back(make_unique<Var>("Tour3"));
            auto post4 = make_unique<FuncCall>("add_to_set", move(post4_args));

            apis.push_back(make_unique<API>(move(pre4), move(call4),
                        Response(HTTPResponseCode::OK_200, move(post4))));

            // Per-API inputs
            auto *c4 = new SymbolTable();
            c4->symtable.insert(Var("t"));
            c4->symtable.insert(Var("Tour3"));
            root.children.push_back(c4);
        }

        // =========================================================
        // 5) PLACE_ORDER_OK (Order2001)
        // PRE:   not_empty(cart)
        // CALL:  placeOrder(t, Order2001) ==> 201
        // POST:  orders[Order2001] = cart
        // =========================================================
        {
            // PRE: not_empty(cart)
            vector<unique_ptr<Expr>> pre5_args;
            pre5_args.push_back(make_unique<Var>("cart"));
            auto pre5 = make_unique<FuncCall>("not_empty", move(pre5_args));

            // CALL: placeOrder(t, Order2001)
            vector<unique_ptr<Expr>> call5_args;
            call5_args.push_back(make_unique<Var>("t"));
            call5_args.push_back(make_unique<Var>("Order2001"));
            auto call5 = make_unique<APIcall>(
                make_unique<FuncCall>("placeOrder", move(call5_args)),
                Response(HTTPResponseCode::CREATED_201, nullptr)
            );

            // POST: [] (orders, Order2001) = cart
            vector<unique_ptr<Expr>> post5_args, idx5_args;
            idx5_args.push_back(make_unique<Var>("orders"));
            idx5_args.push_back(make_unique<Var>("Order2001"));
            post5_args.push_back(make_unique<FuncCall>("[]", move(idx5_args)));
            post5_args.push_back(make_unique<Var>("cart"));
            auto post5 = make_unique<FuncCall>("=", move(post5_args));

            apis.push_back(make_unique<API>(move(pre5), move(call5),
                        Response(HTTPResponseCode::CREATED_201, move(post5))));

            // Per-API inputs
            auto *c5 = new SymbolTable();
            c5->symtable.insert(Var("t"));
            c5->symtable.insert(Var("Order2001"));
            root.children.push_back(c5);
        }
    }
};
