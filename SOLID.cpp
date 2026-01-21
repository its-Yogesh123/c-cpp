#include <bits/stdc++.h>
using namespace std;




/*  ************************** Cohesion ***************************
    1. High Cohesion : highly releted parts inside a module
            we do have an answer to why 'this or that' belong to particular class/module?
    2. Low Cohesion :  no interdependency
            co-incidental neighbours
*/

// low cohesion
// class FirstAid {
// public:
//     void doBandage();      // medical
//     void repairTable();    // furniture repair
//     void calculateBill();  // accounting
// };


// high cohesion
// class FirstAid {
//     string disinfect;
//     string bandage;
// public:
//     void cleanWound();
//     void applyBandage();
// };


/*  ************************** Coupling ***************************
    1. Tight Coupling [Bad Design] : heavily Dependency on other classes (depends on implimentation)
    2. Loose Coupling [Good Design]  : weak dependency (depends on interface and use dependency injection)
*/
 






/* ************************ Dependency Injection *******************
Dependency : Need some other module/object to do somee work
Injection : Passing that object in from the outside, rather than creating it inside.
    Constructor Injection
    Setter Injection
Why?
    Open/Close Principle in SOLID
    Loose Coupling
    Easy Unit Testing
        in hard-coded dependency we have no control on dependecy for testing puspose also we have to initiate the
        full objects but Using DI we can inject fake object just to test ....
*/


//  ❌ High coupling 
// class Payment{
//     public:
//     void payByCash(){
//         cout<<"Payment By Cash";
//     };
// };

// class Counter{
//     Payment make_payment;  // dependecy created inside   
//     // tight coupling (depend directly on implimentation)
//     public:
//     void payBill(){
//         make_payment.payByCash();
//     }
// };

//  ✅ Low coupling 
// class Payment{
//     public:
//     virtual void pay()=0;  // interface
// };

// class Cash:public Payment{       // extension(Open/Close principle)
//     public:
//     void pay() override{
//         cout<<"Payment By Cash";
//     };
// };

// class UPI:public Payment{     // extension (not modification)
//     public:
//     void pay() override{
//         cout<<"Payment By UPI";
//     };
// };


// class Counter{
//     Payment* make_payment;    // loose coupling 
//     public:
//     Counter(Payment* dependency){      // DI via Constructor Injection
//         make_payment = dependency; 
//     }
//     void payBill(){     
//         make_payment->pay();
//     }
// };


/* ************************************** SOLID ***************************************/
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
/* ******************** Liskov's SP ******************** 

How ?
    via multi-level inheritence or multiple inheritence
*/



// not satifying LSP 
// class A{
//     public:
//     void m1();
//     void m2();
//     void m3();
// };


// class B:public A{        // it cannot implement m3 so we cannot directly make
//     public:
//     void m1();
//     void m2();    
//     void m3(){
//         throw std::runtime_error("Beyond My capability");
//     }    
// };


// // LSP
// class A{
//     public:
//     void m1();
//     void m2();
// };

// class B:public A{
//     public:
//     void m3();
// };



// // now classes who satisfies all can inherit B and who cannot impliment m3 can inherit A
// class C:public A{};    // fine


