#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "../../ast.hpp"
#include "../../algo.hpp"

using namespace std;

class Pesu_foods_example3 {
public:
    static void example(vector<unique_ptr<API>> &apis, SymbolTable &root) {
        // ==========================================
        // Step 1: RegisterUserOK
        // PRE:  username not_in dom(U)
        // CALL: register_user(username, password) ==> 201
        // POST: U[username] = password
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre1_args;
            pre1_args.push_back(make_unique<Var>("username"));
            vector<unique_ptr<Expr>> dom_args;
            dom_args.push_back(make_unique<Var>("U"));
            pre1_args.push_back(make_unique<FuncCall>("dom", move(dom_args)));
            auto pre1 = make_unique<FuncCall>("not_in", move(pre1_args));

            // CALL
            vector<unique_ptr<Expr>> args1;
            args1.push_back(make_unique<Var>("username"));
            args1.push_back(make_unique<Var>("password"));
            auto call1 = make_unique<APIcall>(
                make_unique<FuncCall>("register_user", move(args1)),
                Response(HTTPResponseCode::CREATED_201, nullptr)
            );

            // POST: [] (U, username) = password
            vector<unique_ptr<Expr>> post1_args, index_args;
            index_args.push_back(make_unique<Var>("U"));
            index_args.push_back(make_unique<Var>("username"));
            post1_args.push_back(make_unique<FuncCall>("[]", move(index_args)));
            post1_args.push_back(make_unique<Var>("password"));
            auto post1 = make_unique<FuncCall>("=", move(post1_args));

            apis.push_back(make_unique<API>(move(pre1), move(call1),
                        Response(HTTPResponseCode::CREATED_201, move(post1))));

            // Per-API inputs
            auto *c1 = new SymbolTable();
            c1->symtable.insert(Var("username"));
            c1->symtable.insert(Var("password"));
            root.children.push_back(c1);
        }

        // ==========================================
        // Step 2: AuthenticateOK
        // PRE:  U[username] = password
        // CALL: authenticate(username, password) ==> 200
        // POST: T[tokenVal] = username
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre2_args, index2_args;
            index2_args.push_back(make_unique<Var>("U"));
            index2_args.push_back(make_unique<Var>("username"));
            pre2_args.push_back(make_unique<FuncCall>("[]", move(index2_args)));
            pre2_args.push_back(make_unique<Var>("password"));
            auto pre2 = make_unique<FuncCall>("=", move(pre2_args));

            // CALL
            vector<unique_ptr<Expr>> args2;
            args2.push_back(make_unique<Var>("username"));
            args2.push_back(make_unique<Var>("password"));
            auto call2 = make_unique<APIcall>(
                make_unique<FuncCall>("authenticate", move(args2)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: [] (T, tokenVal) = username
            vector<unique_ptr<Expr>> post2_args, post2_index;
            post2_index.push_back(make_unique<Var>("T"));
            post2_index.push_back(make_unique<Var>("tokenVal"));
            post2_args.push_back(make_unique<FuncCall>("[]", move(post2_index)));
            post2_args.push_back(make_unique<Var>("username"));
            auto post2 = make_unique<FuncCall>("=", move(post2_args));

            apis.push_back(make_unique<API>(move(pre2), move(call2),
                        Response(HTTPResponseCode::OK_200, move(post2))));

            // Per-API inputs
            auto *c2 = new SymbolTable();
            c2->symtable.insert(Var("username"));
            c2->symtable.insert(Var("password"));
            root.children.push_back(c2);
        }

        // ==========================================
        // Step 3: GetMenuOK(CanteenY)
        // PRE:  (none)
        // CALL: get_menu(CanteenY) ==> 200
        // POST: MenuY = MenuMap[CanteenY]
        // ==========================================
        {
            // CALL
            vector<unique_ptr<Expr>> args3;
            args3.push_back(make_unique<Var>("CanteenY"));
            auto call3 = make_unique<APIcall>(
                make_unique<FuncCall>("get_menu", move(args3)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST: equals(MenuY, [] (MenuMap, CanteenY))
            vector<unique_ptr<Expr>> post3_args;
            post3_args.push_back(make_unique<Var>("MenuY"));
            vector<unique_ptr<Expr>> index3_args;
            index3_args.push_back(make_unique<Var>("MenuMap"));
            index3_args.push_back(make_unique<Var>("CanteenY"));
            post3_args.push_back(make_unique<FuncCall>("[]", move(index3_args)));
            auto post3 = make_unique<FuncCall>("=", move(post3_args));

            apis.push_back(make_unique<API>(nullptr, move(call3),
                        Response(HTTPResponseCode::OK_200, move(post3))));

            // Per-API inputs
            auto *c3 = new SymbolTable();
            c3->symtable.insert(Var("CanteenY"));
            // MenuMap/MenuY are state/derived; not inputs
            root.children.push_back(c3);
        }

        // ==========================================
        // Step 4: AddToCartOK(ItemY)
        // PRE:  ItemY in MenuY
        // CALL: add_to_cart(ItemY) ==> 200
        // POST: add_to_set(cart, ItemY)
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre4_args;
            pre4_args.push_back(make_unique<Var>("ItemY"));
            pre4_args.push_back(make_unique<Var>("MenuY"));
            auto pre4 = make_unique<FuncCall>("in", move(pre4_args));

            // CALL
            vector<unique_ptr<Expr>> args4;
            args4.push_back(make_unique<Var>("ItemY"));
            auto call4 = make_unique<APIcall>(
                make_unique<FuncCall>("add_to_cart", move(args4)),
                Response(HTTPResponseCode::OK_200, nullptr)
            );

            // POST
            vector<unique_ptr<Expr>> post4_args;
            post4_args.push_back(make_unique<Var>("cart"));
            post4_args.push_back(make_unique<Var>("ItemY"));
            auto post4 = make_unique<FuncCall>("add_to_set", move(post4_args));

            apis.push_back(make_unique<API>(move(pre4), move(call4),
                        Response(HTTPResponseCode::OK_200, move(post4))));

            // Per-API inputs
            auto *c4 = new SymbolTable();
            c4->symtable.insert(Var("ItemY"));
            root.children.push_back(c4);
        }

        // ==========================================
        // Step 5: PlaceOrderOK
        // PRE:  not_empty(cart)
        // CALL: place_order(OrderY) ==> 201
        // POST: orders[OrderY] = cart
        // ==========================================
        {
            // PRE
            vector<unique_ptr<Expr>> pre5_args;
            pre5_args.push_back(make_unique<Var>("cart"));
            auto pre5 = make_unique<FuncCall>("not_empty", move(pre5_args));

            // CALL
            vector<unique_ptr<Expr>> args5;
            args5.push_back(make_unique<Var>("OrderY"));
            auto call5 = make_unique<APIcall>(
                make_unique<FuncCall>("place_order", move(args5)),
                Response(HTTPResponseCode::CREATED_201, nullptr)
            );

            // POST: [] (orders, OrderY) = cart
            vector<unique_ptr<Expr>> post5_args, index5_args;
            index5_args.push_back(make_unique<Var>("orders"));
            index5_args.push_back(make_unique<Var>("OrderY"));
            post5_args.push_back(make_unique<FuncCall>("[]", move(index5_args)));
            post5_args.push_back(make_unique<Var>("cart"));
            auto post5 = make_unique<FuncCall>("=", move(post5_args));

            apis.push_back(make_unique<API>(move(pre5), move(call5),
                        Response(HTTPResponseCode::CREATED_201, move(post5))));

            // Per-API inputs
            auto *c5 = new SymbolTable();
            c5->symtable.insert(Var("OrderY"));
            root.children.push_back(c5);
        }
    }
};
