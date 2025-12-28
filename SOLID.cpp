#include <bits/stdc++.h>
using namespace std;


// class Restaurant{
//     public:
//     void make_food(){}
//     void clean_table(){}
//     void serve_order(){}
//     void place_order(){}
// };


// More clean readable Using SRP (Single Responsiblity Principle)
// There should be High Cohesion(Methods in class are closely related)
// class Chef{
//     public:
//     void make_food(){}
//     void boil_water(){}
//     void cut_vegies(){}
// };
// class Waiter{
//     public:
//     void server_order(){}
//     void take_order(){}
//     void clean_tables(){}
// };
// class Cashier{
//     public:
//     void place_order(){}
//     void give_bills(){}
// };

// class Restaurants{
//     Chef veg_chef,nonveg_chef;
//     Waiter w1,w2,w3;
//     Cashier C1,c2,c3;
//     public:
//     void run(){}
// };





//  Open-Close Principle : Open for extension closed for modification
// Add new things without touching older ones
// Electric Wiring/Socket(Main Board) exmaple is best for intution
// Every time we are connecting wires we just made a socket board(work as base class) now can extend

// class Payment{
//     enum Payment_methods{CASH,NETB};
//     public:
//     void pay(int mode){
//         if(mode == CASH){}
//         else if(mode == NETB){}
//         // now i want to add UPI for payment then i have to write another block in this class
//         // means i'm modifying that class instead use
//     }
// };
// class Payment{
//     public:
//     virtual void pay(){}
//     virtual ~Payment(){}
// };

// class UPI:public Payment{
//     public:
//     void pay() override{}
// };
// class Paytm:public Payment{
//     public:
//     void pay() override{}
// };
// class PayPal:public Payment{
//     public:
//     void pay() override{}
// };