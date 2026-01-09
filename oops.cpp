/* TO do
Singleton 
Factory Method
Private Constructor


An aggregate is a type that:
    Has no user-declared constructors (no constructors written by you),
    Has no private or protected non-static data members,
    Has no base classes, and
    Has no virtual functions.
*/

//----------------------- Object Oriented Programming -------------------------------
// ----- class in C++
#include <iostream>
using namespace std;

/*
A function signature includes:
    The function’s name
    The number and types of its parameters (including their order)
It does NOT include:
    The return type
    Parameter names
    Default values

Function Prototype = Signature + return type + default arguments + const qualifier (etc.).
*/
// Access specifiers
// public : Members declared as public are accessible from anywhere the object is visible
// private : Members  are accessible only within class
// protected : Members are accessible from same class or derived/child class

// class car{
//     public:  // access specifiers(default private)
//     int model=0;   // data members
//     int price=0;
//     int mfd=0;
//     void detail(void){   // member function
//         cout<<"Model of car "<<model<<endl
//         <<"Price of car "<<price<<endl
//         <<"Mfd of car "<<mfd<<endl;
//     }
// };   
// int main(){
//     car bmw;
//     bmw.model=2023;
//     bmw.price=634824;
//     bmw.detail();
//     return 0;
// }

// defining member function outside the class
// scope resolution operator ::
// class car{
//    public:
//    int model;
//    int price;
//    int mfd=0;
//    void publicFun(); // function declaration 
//    private:
//    void detail(void);  // function declaration in private scope 
// };
// void car::detail(void){     // though it is private we can do this but only can call from object's method not via object
//     cout<<"Model of car "<<model<<endl
//        <<"Price of car "<<price<<endl
//        <<"Mfd of car "<<mfd<<endl;
// }
// void car::publicFun(){     // defining outside
//     this->detail();        // working
// }
// int main(){
//    car bmw;
//    bmw.model=2023;
//    bmw.price=31243;
//    bmw.publicFun();
// //    bmw.detail();  // working
//    return 0;
// }

/*
1. this works fine while defining method outside class (all class member accessible)
2. For any scope(public private or protected) we can define function outside the class (using ::) given that methods already declared 
but can only call private function from class scope only 
3. we can define constructors also outside the class
*/

//----------------------------------------------------- Constructors -----------------------------------
/*
constructor prototype
class_name();
class_name:: class_name(){};    --- definition outside the class [Must be declared outside the class]
    Types : 
        Default : Any constructor that can be called with 0 arguments .
        Parameterized : Any constructor that can be called with non-zero arguments.
        Copy
        Move(C++11)
        Conversion Constructor : Single parameterised constructor with no explicit keyword
    Operators :
        Copy Assignment Operator
        Move Assignmet Operator
    Delegation of Constructors (call one cons. from another)
*/

//#include <iostream>
//using namespace std;
// class car(){}  // implicit constructor
// class car{
//     public:
//     int model=657;
//     int price=0b101;
//     car(){                                // explicit + default constructor
//         cout<<"Model is "<<model<<endl
//         << "price is "<<price<<endl;
//     }
//     // car(int a=0,int b=0){}   // also a default constructor
// };
// int main(){
//     car bmw;
//     car tata;   // as 2 times obj created hence both times constructor run
//     return 0;
// }


// --- 2. parameterized constructor
// ⚠️ Any parameterized constructor could be a default constructor using (all default params)
//class car{
//    public:
//    int model;
//    int price;
//    car(int id){    //must be in public if not we cannot create object                        (important)
//        cout<<"Id : "<<id<<endl;
//        <<"Model : "<<model<<endl
//        <<"Price : "<<price<<endl;
//    }
//};
//int main(){
//    car tata(1234);  // obj cann't create without parameter
//    return 0;
//}

// ---------- copy constructor
// => nothing but a special type of parameterized function in which the parameter is object of same class
//  🔴 It must have only 1 parameter i.e. reference of another object of same type
// #include <iostream>
// using namespace std;
// class student{
//     public:
//     int id;
//     student(){
//         cin>>id;
//     }
//     student(student& obj){    // copy constructor  explicit define  not full
//         id=obj.id;
//     }
//     student(const student& obj){    // now it can take both (including r-values also) but not need ( as there is RVO)
//         id=obj.id;
//     }
// };
// int main(){
//     student s1;
//     student s2(s1);
//     cout<<s2.id;
//     return 0;
// }
// ---------------------- implicit copy constructors
// #include <iostream>
// using namespace std;
// class student{
//     public:
//     int id;
//     int age;
//     char ch;
//     student(){
//         id=3780;
//         age=40;
//         ch='Y';
//     }
// };
// int main(){
//     student s1;
//     student s2(s1);   // now automatic copy corresponding elements
//     cout<<s2.id;
//     return 0;
// }




//  ------- 🚨 conversion constructor  : single parameterized constructor without explicit keyword
// class test{
//     public:
//     int val,val1;
//     test(int a){
//         this->val =a;
//         cout<<"constructor Called\n";
//     }
//     test(int a,int b){
//         this->val =a;
//         this->val1=b;
//         cout<<"2-params constructor Called\n";
//     }
// };
// int main(){
//     // best example is string literal vs string object
//     // string name = "Yogesh";  // here 'Yogesh' is  string literal(const char*) which implicit convert to string object;
//     test obj =7;     // ✅ implicit conversion (Conversion Constructor) or
//     cout<<obj.val<<endl;
//     obj =10;            // this is implicit conversion (use of conversion constructors)
//     cout<<obj.val<<endl;
//     obj = {1,2};    // ❌ no implicit conversion  because using initalizing list( C++11) it will call corresponding constructor
//     obj ={90};    // ❌ no type conversion constructor instead normal 
//     cout<<obj.val;

// }
/*  🔴 IMP conversion constrcutor vs intialising list
    conversion constructor must be of single argument while
    in initializing list it will call corresponding constructor w.r.t to arguments
*/
     // avoid implicit converison  🟢 explicit keyword
// class test{
//     public:
//     int val;
//     explicit test(int a){
//         this->val = a; // constructor with Initializing list
//         cout<<"Constructor called \n";
//     }
// };
// int main(){
//     // test obj =50;     // error 
//     // test obj = {50};// still error because explicit allows only direct + default initialization
//     test obj(10);
//     cout<<obj.val;
//     return 0;
// }

/* Ways to initialise object
    Default Initialization
    Direct Initialization
    Direct Uniform Initialization
    Copy List Initialization
    Conversion Constructor
*/



// ******************** Initialisation  vs Assignment *****************************             (imp)
/* Before moving on we have 2-kind of initialization
   1. Parameter Initialisation ()
   2. uniform Initialisation  {}  --> strict type checking and restrict narrow conversions (like 280 to char)
    Order of Intialization :- According to declaration in class (matter if initialier list)
   like if a is declare before b then a will initialised first even if a is wrote before b in list
*/
// class demo{
//     public:
//     int a;
//     int b;
//     // demo(int b):b{this->a},a(this->b){
//     //     cout<<"Value of a : "<<this->a<<" and b : "<<this->b;
//     //     // if we initialised the member here using '=' then top to down matter
//     //     // means if we wrote b first then b will intialised first
//     // }
//     // proof a is initialised first
//     // demo(int b):b{a},a(this->b){    // error because b is not yet initialised
//     //     cout<<"Value of a : "<<this->a<<" and b : "<<this->b;
//     // }

//     // demo with more intution
//     demo(int x):b(x++),a(x++){}
// };
// int main(){
//     demo obj1(2);
//     cout<<obj1.a<<" "<<obj1.b;
//     return 0;
// }
// ----------------------------------- proof initializater not use copy assignment operator
// class Base{
//     public:
//     Base(){
//         cout<<"Constructor Called"<<endl;
//     }
//     Base(Base& obj){
//         cout<<"Copy Constructor called"<<endl;
//     }
//     Base& operator=(Base& obj){
//         cout<<"Copy Assignment Constructor called"<<endl;
//         return *this;
//     }
// };
// class A{
//     public:
//     Base obj;
//     // A(Base& obj1):obj(obj1){
//     // }

//     // assignment
//     A(Base& obj1){     // if pass by value then one copy-constructor to make local obj1 from passed value
//         obj = obj1;
//     }
// };

// int main(){
//     Base obj;       // 1st time constructor called for this
//     A obj1(obj);
//     return 0;
// }

/*
If using initializor list only copy constructor will called
if not then default initializor and then copy assignment operator for copying values
*/



/* --------- Move Constructor  (c++11+)
to move ownership of an object 
🔴 Why we need ?? 
As copy work for  l-values but for r-values(temporary objects) copy become chaos...
for e.g. if a function return an object(it will be a r-value) if we assign this object in a variable then a new object is created and
all data is copied and that temp. object having exact same data will released after sometime (unnecesssary creating and deletion)
Solution :  what if instead of creating a new object and copying data from temporary object we will make that r-value to l-value by
transferrign ownership 

⚠️ but c++17 RVO and NRVO compiler skip the move and copy functions
 */
// 

// class A{
//     public:
//     int a;
//     A(int n):a(n){
//         cout<<"constructor called\n";
//     }
//     // defining copy constructor
//     A(A& obj){
//         cout<<"Copy Constructor Called\n";
//     }
//    // defining move constructor
//     A(A&& obj){
//         this->a= obj.a;     // just shallow copy
//         obj.a = nullptr;
//         cout<<"Move Constructor Called\n";
//     }
//     ~A(){
//         cout<<"Destructor Called\n";
//     }
// };
// A fun(){
//     A obj(4);
//     return obj;
// }
// int main(){
//     // A obj(4);
//     // A obj1(obj)   // copy constructor  called (without RVO)
//     // A obj(fun());   // fun will return an r-value which will object of class A like above copy constructor  will called (if move not define)
//     // cout<<(obj.a)<<endl;
//     A obj2 = fun();
// }

//  🚨 RVO vs without RVO 🚨 (imp)
// without RVO or C++11
// class A{
//     public:
//     A(){
//         cout<<"Constructor Called \n";
//     }
//     A(A& obj){
//         cout<<"Copy Constructor Called \n";
//     }
//     A(A&& obj){
//         cout<<"Move Constructor Called \n";
//     }
//     ~A(){
//         cout<<"Destructor Called \n";
//     }
// };
// A fun(){
//     return A();   // only one object is created 
// }
// A fun1(){
//     A obj;       // constructor called (1 object create here)
//     return obj;   // another object created for return (move/copy constructor called)
// } // obj will destroyed after function return

// int main(){
//     A main_obj = fun1();  // move/copy constructor  called meand another object
//     // that temp. object created for return will destroyed here  
//     cout<<"hello";
// }   // after main function main_obj will also destroyed 

/* without RVO or c++11 (or previous)
1 time constructor 
2 time move/copy constructor
3 time destructor will callled      overall 3 object create
                    vs 
with RVO and C++17 + only 1 object will created
1 time constructor
1 time destructor 
*/




// ----------------------------------- Destructors-----------------------------------
/*
    Destructor is tied with object's lifetime only .
------ When a destructor is called ?????
    1). when object goes out of scope
    2). object is explicit delete
    3). Destuctor function called externally
*/

// #include <iostream>
// using namespace std;
// class class1{
//     public:
//     class1(){
//         cout<<"Constructor Called \n";
//     }
//     ~class1(){
//         cout<<"Destructor Called";
//     }
// };
// int main(){
//     class1 obj;
//       obj.~class1();    // explicit called destructor function
//     return 0;
// }
/* after destroying an object then its  variable store un-unified memory (may be hold previous memory)
*/
 // coding example
// class Dangling{
//     public:
//     int a;
//     Dangling(){a =60;}
// };
// int main(){
//     Dangling obj;
//     // cout<<obj.a;
//     obj.~Dangling();  // just calling destructor but object will not destroyed
//     cout<<obj.a;   // obj will not destroy here 
// }

// After calling destructor explicit obj is not destroyed ()
// class A{
//     public:
//     ~A(){
//         cout<<"Destructor Called\n";
//     }
// };

// void fun(){
//     A obj;
//     obj.~A();
// }
// int main(){
//     fun();
// }
// ----- Application of destructors
//#include <iostream>
//#include <string.h>
//using namespace std;
//class base{
//    char* s;
//    public:
//    base(char* a){
//        int size=strlen(a);
//        s=new char[size+1];
//        strcpy(s,a);
//        cout<<s;
//    }
//    ~base(){
//        delete[] s;
//    }
//};
//int main(){
//    base obj("Hello");
//    return 0;
//}

// -------private Desructors ------
// an class with private destructor cannot create its instance in stack memory
// #include <iostream>
// using namespace std;
// class c1{
//     ~c1(){    // destructor in private scope
//         cout<<"Destructor Called";
//     }
// };
// int main(){
//     c1 obj;    // error because private destructor not accessed
                // compiler automatic calls the destructor where object gooes out of scope(but not for dynamic objects)
//     return 0;
// }

// ---- to deal we use pointer
// class c1{
//     ~c1(){
//         cout<<"Destructor called";
//     }
//     public:
//     int age=10;
// };
// int main(){
//     c1* t=new c1;   // object is not created in stack  so no error
//     cout<<t->age;    // here dynamically created object
//     delete t;  // although here obj is not created but delete always call destructor...
//     // for using destructor in this case friend class/function required
//     return 0;
// }

/* ----------- for delete that object
    1. use static member function
    2. use non-static member function / using this
    3. use friend class/function
*/

// #include <iostream>
// using namespace std;
// class c1{
    
//     ~c1(){
//         cout<<"Destructor called";
//     }
//     public:
//     c1(){
//         cout<<"Constructor Called";
//     }
//     friend void des(c1*);      
//     static void des1(c1* obj){delete obj;}
//     void des2(){delete this;}
// };
// void des(c1* obj){    // friend function
//     delete obj;
// }
// int main(){
//     c1* t=new c1;
//     des(t);                   // Ist method
//     return 0;
// }

// ---- using this operator                                                 (imp)
// #include <iostream>
// using namespace std;
// class c1{
    
//     ~c1(){
//         cout<<"Destructor called";
//     }
//     public:
//     c1(){
//         cout<<"Constructor Called";
//     }
//     void des(){              // member function
//     delete this;
// }
// };
// int main(){
//     c1* t=new c1;
//   t->des();                // IInd method  working
//     return 0;
// }
//----------------------------------------
// shallow vs deep copy
// class box{
//     int len;
//     int* wid;
//     int hei;
//     public:
//     box(){
//         wid=new int;
//     }
//     void set(int l,int w,int h){
//         len=l;
//         *wid=w;
//         hei=h;
//     }
//     void show(){
//         cout<<"Length : "<<len<<endl
//         <<"Width : "<<*wid<<endl
//         <<"Height "<<hei<<endl;
//     }
// };
// int main(){
//     box b1,b2;
//     b1.set(10,10,10);
//     b2=b1;    // shallow copy
//     b1.show();
//     b2.show();
//     b2.set(20,500,30); // change in b2
//     b1.show();   // !!!!! change in width of b1 also occur  
//     b2.show();
//     return 0;
// }
// // so to avoid these changes we use deep copy means to define copy construtor explicit/ by developer



//------------------------------ Friend class ------
// a friend class can access or manage all private and protected members of that class
// no need forward declaration
// #include <iostream>
// using namespace std;
// class parent{           // base class
//    int add=85;
//    int code=898;
//    friend class son;                      // making friend class 
// }mem1;

// class son{                 // friend class
//    public:
//    void detail(parent& obj){
//        obj.code=0000;
//        obj.add=0;             // can change/access member data
//        cout<<obj.add<<endl
//        <<obj.code<<endl;
//    }
//    void hello(){
//     parent obj;
//     obj.add = 90;
//     cout<<obj.add<<endl;
//    }
// };
// int main(){
//    son spy;
//    spy.detail(mem1);
//    return 0;
// }
// -------- friend function
// global friend function
// #include <iostream>
// using namespace std;
// class base{
//     int age;
//     int otp;
//     public:
//     base(){
//         age=30;
//         otp=5547;
//     }
//     friend void spy_fun(base&);  // firend also declare the function
// };
// void spy_fun(base& obj){
//     cout<<"Age is : "<<obj.age<<endl
//     <<"Otp : "<<obj.otp;
// }
// int main(){
//     base obj1;
//     spy_fun(obj1);
//     return 0;
// }

// member function of another class
//#include <iostream>
//using namespace std;
//class base;                                      // order matter here
//
//class other{
//    public:
//    void detail(base&);
//};
//class base{
//    int age;
//    int otp;
//    public:
//    base(){
//        age=99;
//        otp=6575;
//    }
//    friend void other::detail(base&);
//};
//void other::detail(base& obj){
//    cout<<"Age : "<<obj.age<<endl
//    <<"otp : "<<obj.otp;
//}
//int main(){
//    base obj1;
//    other mem;
//    mem.detail(obj1);
//    return 0;
//}
//



//------------------------------------------------- Static Data Members
/*
    Must define outside the class but static const data members of 🚨integral type which can be initialized in the class declaration.
    Only 1 copy (shared among all objects) which can modify this
    Static member function can access static variables
    Static member function does not have 'this'
*/
// static int hello=90;

// class A{
//     static const int x = 100;  // cannot accessible even by objects
//     protected:
//     static const int z=90;
//     public:
//     static const  int a=90;
//     inline static  string b="knfsdf";   // valid c++17 +
// };
// class B:public A{
//     public:
//     A obj;   // accessible all members except private
//     B(){
//         cout<<A::z;
//     }
// };
// int main(){
//     A obj;
//     cout<<A::a;
// }



// class A{
//     public:
//     inline static int a=90; 
// };

// int main(){
//     A obj,obj1;    // only 1 copy which will share among every data member
//     obj.a=80;
//     cout<<obj1.a;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A{
//     public:
//     int x=50;
//     A(){
//         cout<<"Class A Constructor Called \n";
//     }
// };
// class B{
//     public:
//     // A b;    // every time obj create
//     static A a;    //created before main execute
    
//     B(){
//         cout<<"Class B Constructor Called \n";
//     }
// };
// A B::a;    // defining a is must
// int main(){
//     B b1;
//     cout<<b1.a.x;    // accessing element of a
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class A{
//     public:
//     int x=50;
//     A(){
//         cout<<"Class A Constructor Called \n";
//     }
// };
// class B{
//     public:
//     // A b;    // every time obj create
//     static A a;    //declaration
//     B(){
//         cout<<"Class B Constructor Called \n";
//     }
//     static A getA(){
//         return a;
//     }
// };
// A B::a;    // defining a
// int main(){
//     // B b1;
//     // cout<<a.x;  // error
//     // A a=b1.getA();
//     // cout <<a.x; // no error
//     A a=B::getA();  // if U not want any object in B but want a;
//     cout<< a.x;  // no errror
//     return 0;
// }



//---------------------------    this pointer (like A*)
// 🟢 this is a l-value(readonly pointer)
// *this is  the refrence of object
// // it is a hidden pointer used to represent the current object 
// #include <iostream>
// using namespace std;
// class Test{
//     int x;
//     int y;
//     public:
//     Test(int x,int y){
//         this->x=x;
//         this->y=y;   // this is like pointer
//     }
//     void show(){
//         cout<< this->x<<" "<<this->y;
//     }
//     // ~Test(){ 
//     //     delete this;  // can delete temporary objects
//     // }
// };
// int main(){
//     Test obj1(5,10);
//     obj1.show();
//     return 0;
// }
// -------    ------- ❌ V. Imp 
// ❌ delete this in destructor (runtime error )
// 🟢 delete can released memory allocated dynamically
// class A{
//     public:
//     int a;
//     A():a(5){};
//     ~A(){
//         delete this;   //  🔴 always error in destructor because delete will call destructor again and inside destructor delete again
//         // Recursive call and undefined behaviour
//     }
// };
// int main(){
//     // A a;
//     // a.~A(); // double deletion in stack object
//     // cout<<a.a;

//     // heap object     (Most Dangerous Things)  
//     // A* obj = new A();
//     // obj->~A(); // still error 

// }
// ⚠️ delete this in Constructor  (Compiles success)

// class A{
//     public:
//     int a;
//     A(){
//         a =90;
//         delete this;         // destructor called + memory released
//         // this become dangling from here
//         cout<<a<<" Constructor "<<endl;    
//     }
//     ~A(){
//         cout<<"Destructor \n";
//     }
// };
// int main(){
//     A obj; // error as object is in stack not in heap (use 'delete' always with object created by 'new')
//     A* obj = new A();
// }
// ----- -----------------application of this
// ---------for chain function
/*#include <iostream>
using namespace std;
class Test{
    int x;
    int y;
    public:
    Test& getX(int x){
        this->x=x;
        return *this;
    }
    Test& getY(int y){
        this->y=y;
        cout<<"X called"<<endl;
        return *this;
    }
    void show(){
        cout<<"Y called"<<endl;
        cout<<this->x<< " "<<this->y;
    }
}; 
int main(){
    Test obj1;
    obj1.getX(5).getY(10);
    obj1.show();
    return 0;
}*/

/*  local classes  
    1. local class is class inside a function/block
    2.  all non-static methods must define inside class
    3. cannot have static data-member but can have methods
    4. friends and virtual function not allowed
    5. local friend class allowed but (local to local ✅)(local's friend global ✅) (global's friend local ❌) but
    6. Methods of the local class can only access static and enum variables of the enclosing function.
    7. Local classes can access global types, variables, and functions. 
*/
// string global="global";
// static string globalStat="Global Static Variable";
// int main(){
//     int mainLocal=90;
//     static string localStat="Local Static Variable";
//     enum Number{One,Two,Three};
//     class local{
//         // static const int a =90;  //error cannot have static members
//         public:
//         static int sqr(int a){
//             return a*a;
//         }
//         void check1(){
//             // cout<<mainLocal;  // ❌ error local variable of function not allowed
//             cout<<global<<endl;  // ✅ global variable accessible
//             cout<<globalStat<<endl;  // ✅ global static variable accessible
//             cout<<localStat<<endl;  // ✅ local static variable accessible
//             cout<<Three<<endl;  // ✅ local enum variable accessible
//         }
//         void check2(void);
//     };
//     // void local::check2(){cout<<"Hello worlds";}  // ❌ function definition outside class not allowed
//     local obj;
//     obj.check1();
// }

/* friend in local class
 🚨 Local is saying: “If Global ever sees me, it has access to my private stuff.”
 ⚠️ But Global cannot sees Local, because it's outside the scope — so the access is granted but useless.
    because its functoin's local stuff anythign cannot access block's local stuff global class completely unaware
    about there exists any local class or not


*/
// class globalClass{
//     public:
//     void fun(){}
// };
// int main(){
//     class local1{
//         string l1var="Private Variable of local classs";
//         friend class local2;
//         friend class globalClass;  // no error but global cannot access local's private/protected stuffs
//     };
//     class local2{
//         public:
//         local2(){
//             local1 obj;
//             cout<<obj.l1var<<endl;     // accessible
//         }
//     };
// }

/*--------  Nested class ------------
    1. inner class directly access static + enum variables
    2. inner class can access private+public+protected member of outter class(indirectly)
    3. outter class is like global (normal class rule) for inner
    e.e vector<int> ::iterator  is nested class
*/

// class outter{
//     string nonStaticPvt;
//     inline static int a=90;    // static + enum  direct access to inner
//     enum Number{One,Two,Three};
//     int outerNonStatic;
//     public:
//     string nonStaticPub;
//     outter(){
//         this->nonStaticPub = "Outter class Non-Static Pubic Member";
//         this->nonStaticPvt = "Outter class Non-Static Private Member";
//     }
//     class inner{
//         string innerPvt;
//         int a;
//         string One;
//         public:
//         string innerPub;
//         inner(){
//             this->innerPub ="Inner class Public member";
//             this->innerPvt ="Inner class Private member";
//             this->a =1000;
//             // cout<<outter::outerNonStatic<<endl;      // ❌ cannot access non-static member as obj required
//             cout<<outter::a<<endl;
//             cout<<this->a<<endl;    // ✅ access static member
//             cout<<outter::One<<endl;           // ✅ access enum member
//             cout<<"inner class constructor"<<endl;  // inner class variable  shadows outter::a so use ::
//         }
//         void getOutter(outter& obj){
//             cout<<obj.nonStaticPvt<<endl;    //  ✅ access private member
//             cout<<obj.nonStaticPub<<endl;    //  ✅ access public member
//         }
//     };
//     void getInner(){
//         inner obj;
//         // cout<<obj.innerPub;  // ✅ outter class can access Public member but
//         // cout<<obj.innerPvt;  // ❌ cannot access Private member like general class rule
//     }
// };
// int main(){
//     outter::inner obj;
//     outter obj1;
//     obj.getOutter(obj1);
//     return 0;
// }

/*-----------------------------  Inheritance --------------------------------------
    1. Multipath(Spe. Hybrid Inheritence) : Diamond Problem
    2. If a child class declares a variable with the same name as one in the parent, the parent’s variable is hidden in that scope
     but can access using ::
    3. any member with same name will hide all base class members with same name (static + non-static)
    4.⚠️ Parent class pointer cannot call child-only methods even object is of child class

    ⚠️⚠️ In private(me only) inheritence IS-A relationship is hidden to outter world
    ⚠️⚠️ In protected(family only ) inheritence IS-A relationship is partially hidden (can access by derived or subclass)
*/
// class A{
//     public:
//     inline static int a=90;
//     string var1;
//     A():var1("A class Variable"){}
// };

// class B:public A{
//     // inline static int a=180; // not access so error
//     string var1;  // shadows the class A's var1 
//     public:
//     B():var1("B class Variable"){}
//     inline static int a=180;
// } ;

// int main(){
//     cout<<A::a<<endl;
//     cout<<B::A::a<<endl;
//     // cout<<B::a<<endl;
//     B obj;
//     cout<<obj.var1<<endl; // cannot access as var1 is private in class B
//     cout<<obj.A::var1<<endl;   
// }
// ----------------- Hide base class member of same name (static + non-static methods)
//  Solution :  either use :: operator  or using keyword in class
// class A{
//     public:
//     void fun(){cout<<"Base class fun";};
//     void fun(int i){cout<<"Base class fun1";};
// };
// class B:public A{
//     public:
//     // this makes A's fun() and fun(int i) hidden in this scope
//     // we can't even call fun(int i) which is not even in child scope 
//     void fun(){
//         cout<<"Child Class fun\n";
//     };
// };
// class C:public A{
//     public:
//     using A::fun;
//     void fun(){                     // 🔴 Not function overriding but function Hidding/Shadowing
//         cout<<"Child Class fun\n";
//     };
// };
// int main(){
//     B obj;
//     // obj.fun(1);   // ❌ error
//     // obj.A::fun();  // ✅ works fine
//     // or 
//     C obj1;
//     obj1.fun(8);   // ✅ works fine
//     return 0;
// }


/* Multiple Inheritence
    1. Parents have same name members(ambiguity error): Use scope res. operator (::)
    2. Parent constructor order is same as order of inheritence(FCFS)
    3. Diamond Problem : use virtual inheritence
        Real problem in Diamond is not ambiguty bcoz ambiguity can be resolve using :: but the lower class
        is maintaing 2 copies of grand-parent class via path (in diamond 2 path so 2 copies) which is major concern
    Note : Confusion Points - Like if they share common parent then change of one will affect another ......
        but point is object will be of D(lower part) class means we will never use that object as of purly either of parent
        if we create object of both parent seperatly everything go as usual 
        main point is D should inherit all properties from its parent and antecedent which will it do so no need t worry about
*/
// ------ Naming Ambiguity --------
// class A{
//     public:
//     string varA1;
//     string sameVar;
//     A():varA1("Class A Variable"),sameVar("Class A's Variable"){}
// };
// class B{
//     public:
//     string varB1;
//     string sameVar;
//     B():varB1("Class A Variable"),sameVar("Class B's Variable"){}
// };
// class C:public A,public B{};

// int main(){
//     C obj;
//     // cout<<obj.sameVar<<endl;  // ambiguity error
//     cout<<obj.A::sameVar<<endl;  // use ::
//     cout<<obj.B::sameVar<<endl; 
// }
// ------------------- Diamond Problem
// class A{
//     public:
//     string sameVar;
//     A():sameVar("Class A's Variable"){
//         cout<<"A's Constructor \n";
//     }
//     void fun(){
//         cout<<"FUnction Called\n";
//     }
// };
// class B:public A{
//     public:
//     B(){
//         cout<<"B's Constructor \n";
//     }
// };
// class C:public A{
//     public:
//     C(){
//         cout<<"C's Constructor \n";
//     }
// };
// class D:public B,public C{
//     public:
//     D(){
//         cout<<"D's Constructor \n";
//     }
// };

// int main(){
//     D obj;   // ✅ check order of constructor
//     cout<<obj.B::sameVar<<endl;   // resolved but obj has to maintain 2 state for B:: and for C:: but needed only 1
//     cout<<obj.C::sameVar<<endl;
//     // obj.fun(); 
//     obj.B::fun();
//     obj.C::fun();
// }

/*      ****** Polymorphism ******** Ability of a function or object to behave differently based on the context.
    1. Compile-time Poly. :
        Function Overloading + Operator Overloading
    2. Runtime Polymorphism
        Function Overriding(concept) + Virtual Functions(mechanism)

*/



/*-----------------------------     Funcion Overloading --------------------------------------
    Function Overloading Resolution
        Exact Match -> Type Promotion -> Type Conversion -> User Define -> Ellipsis(...)
    const param Overloadable if pass by refrence/pointer(low level const)
    Not Overloadable :
        1.Same Signature (name + arguments(order matter))
        2.Arrays by [] or *  both same
        3.Callbacks by () or (*)()
*/


// void fun(int&& a){
//     cout<<"Hi\n";
// }
// void fun(int& a){
//     cout<<"Hello\n";
// }
// void fun(int a){  // ❌ not overloadable bcoz here a can be l and r value
//     cout<<"Hello\n";
// }

// int main(){
//     fun(4);
// }
// Funcion Overloading  with const

// void fun(int a);   
// void fun(const int a);   // useless (top-level const)
// --- const methods
// class A{
//     int a;
//     public:
//     A(){};
//     void get()const{
//         cout<<"Hello\n";
//     }
//     void get(){
//         cout<<"hi\n";
//     }
// };
// int main(){
//     A obj;
//     obj.get();
//     const A obj2;
//     obj2.get();
//     return 0;
// }
// ----------------------------  Operator Overloading ----------------------
// // complex numbers
// #include <iostream>
// using namespace std;
// class complex{
//     int real;
//     int img;
//     public:
//     complex(int r=0,int i=0){
//         real=r;
//         img=i;
//     }
//     void operator++(){
//         this->real=this->real+1;
//         this->img=this->img+1;
//     }
//     void operator--(){
//         this->real=this->real-1;
//         this->img=this->img-1;
//     }
//     complex operator+(complex c1){
//         complex temp;
//         temp.real=this->real+c1.real;
//         temp.img=this->img+c1.img;
//         return temp;
//     }
//     complex operator-(complex c1){
//         complex temp;
//         temp.real=this->real-c1.real;
//         temp.img=this->img-c1.img;
//         return temp;
//     }
//     complex operator*(complex c1){
//         complex temp;
//         temp.real=this->real*c1.real;
//         temp.img=this->img*c1.img;
//         return temp;
//     }
//     friend complex operator/(complex c1,complex c2);
//     void show(){
//         cout<<this->real;
//         this->img>0?cout<<"+"<<this->img<<"i\n":cout<<"-"<<-1*(this->img)<<"i\n";
//     }
// };
// complex operator/(complex c1,complex c2){
//     complex temp;
//     temp.real=c1.real/c2.real;
//     temp.img=c1.img/c2.img;
//     return temp;
// }
// int main(){
//     complex c1(10,-8),c2(2,4);
//     complex c3;
//     // c3=c1+c2;
//     // c3=c1-c2;
//     // c3=c1*c2;
//     // c3=c1/c2;  // working overload from friend function
//     c3.show();
//     return 0;
// }
//---------       << Insertion operator overloading
// insert data to output stream
//#include <iostream>
//#include <string>
//
//using namespace std;
//class base{
//	string first_name;
//	string last_name;
//	int age;
//	public:
//		base(string s1,string s2,int age){
//			this->first_name=s1;
//			this->last_name=s2;
//			this->age=age;
//		}
//		friend ostream& operator<<(ostream& out,base b1);
//};
//ostream& operator<<(ostream& out,base b1){
//			out<<b1.first_name<<" "<<b1.last_name<<" Age is "<<b1.age;
//			return out;
//		}
//int main(){
//	base b1("Yogesh","kumar",18);
//	cout<<b1;
//	return 0;
//}

//-----------------------------     Function overriding  (Concept)--------------------------------------
/*
    Function Signature Must be same in both (sub & super) class 
    🔴 Return type must be covriant(not like int and string but like one erturning base other returning derived refrence)
    Super class methods must be virtual else it will functoin hidding not overriding
    override ensure that function must be virtual in base class else compile error
    🔴 Function Overriding != Runtime Polymorphism
*/
// class parent{
//     public:
//     void fun(){
//         cout<<"This is Parent functin \n";
//     }
//     virtual void par(){
//         cout<<"This is only in Parent functin \n";
//     }
// };
// class child:public parent{
//     public:
//     void fun(){
//         cout<<"This is Child functinon\n";   // ❌fun hide the base fun no Overriding
//     }
//     void par()override{   // override keyword of checks that given function is virtual or not
//         cout<<"This is Child functinon\n";   // ✅now Overriding
//     }
// };
// int main(){
//     child obj;
//     obj.fun();  
//     obj.par(); 
//     return 0;
// }
// ------------------------------------
// class parent{
//     public:
//     void fun(){
//         cout<<"This is Parent functin \n";
//     }
//     void par(){
//         cout<<"This is only in Parent functin \n";
//     }
// };
// class child:public parent{
//     public:
//     void fun(){
//         cout<<"This is Child functinon\n";
//     }
// };
// int main(){
//     parent *obj1=new child;
//     obj1->fun();  // using pointer here parent class fun called
// //  pointer usi ko point krega jis class me pointer bna h
// // to handle this we need virtual function
//     return 0;
// }
/*----------------------------------------------- Virtual Function ---------------
    1.Runtime  Polymorphism occurs only when base class pointer have child refrences + Overriding
    2. virtual function is eligible to polymorphism but do only when using base class refrence
    3. Cannot static
*/
//virtual function working
// #include <iostream>
// using namespace std;
// class base{
//     public: 
//     virtual void show(){    
//         cout<<"This is Base class show() function\n";
//     }
//     void print(){
//         cout<<"This is Base class print() function\n";
//     }
// };
// class child:public base{
//     public:
//     void show(){
//         cout<<"This is Child class show() function\n";
//     }
//     void print(){
//         cout<<"This is Child class print() function\n";
//     }
// };
// int main(){
//     base* ptr=new child;  // pointer type is base and pointed to child class
//     // base* ptr;
//     // child obj;
//     // ptr=&obj     //  2nd Method
//      ptr->show();
//      ptr->print();
//     return 0;
// }
/*Explanation :- 
as show is virtual functoin which bind at runtime and print is non-virtual function  bind at compile time
As at complie time type of pointer prior
and at run time the location pointed by pointer is prior*/
// ----------------------------- 🚨 IMP 🚨
// class A{
//     public:
//     virtual void fun(){};            // LateBinding
//     virtual void fun(int x){};       // LateBinding
// };
// class B:public A{
//     public:
//     void fun(int a,int b){};      //  EarlyBinding  child-only method (not overriden)
//     virtual void fun1(int a,int b){};  // Late Binding
// };

// int main(){
//     A* obj = new B();
//     obj->fun(1,2);     
//     obj->fun1(1,2); // here error also because which function is  
//     return 0;
// }

/*  Explanation
Compiler check static type -> check function in caller's scope -> check virtual or not  -> run
whether function is virtual or not binding is done accordingly but  at compile time it must be in caller's scope
*/
// -------------- Virtual function in all types
// class base{
//    public:
//    void fun1(){     // EB
//        cout<<" func1() of base class \n";
//    }
//    virtual void fun2(){                  // LB
//        cout<<" func2() of base class \n";
//    }
//    virtual void fun3(){                 // LB
//        cout<<" func3() of base class \n";
//    }
//    virtual void fun4(){                 // LB
//        cout<<" func4() of base class \n";
//    }
// };              // 🟢 vtable = [fun2,fun3,fun4]
// class child:public base{
//    public:
//    void fun1(){            // EB
//        cout<<" func1() of child class \n";
//    }
//    void fun2(){                 // LB
//        cout<<" func2() of child class \n";
//    }
//    void fun4(int x){  // EB
//        cout<<" func4() of child class \n";
//    }
//    virtual void fun5(int x,int y){  // LB
//        cout<<" func4() of child class \n";
//    }
// };              // 🟢 vtable = [fun2(overriden),fun3(base version),fun4(base version),fun5(child-only)]
// int main(){
//    base *ptr =new child;
//    ptr->fun1();  // base version called
//    ptr->fun2();  // child's version
//    ptr->fun3();  // base version
//    ptr->fun4();  // base versino
//    // ptr->fun4(5); // early bind so compilation error -----------------------(imp)
//    // ptr->fun5(4,5); // late bind still compilation error because not in parent class
//    base* ptr = new base();
//    ptr->fun2();     // ❌ no runtime polymorphism (Compile time binding)
//    return 0;
// }


// class A{
//     public:
//     virtual void fun(){
//         cout<<"Class A\n";
//     };
//     void fun(int a,int b){
//         cout<<"Class A fun 2\n";
//     };
// };
// class B : public A{
//     public:
//     void fun(int a){
//         cout<<"Class B Fun\n";
//     };
// };

// int main(){
//     B* obj = new B();
//     obj->fun();  //error  because as fun name in B it will hide all base class function
//     return 0;
// }

//   virtual + default values
// class A{
//     public:
//     virtual void fun(int x=90){
//         cout<<"A's Function called\n";
//     }
// };
// class B:public A{
//     public:
//     void fun(int x=100){
//         cout<<x<<" B's Fun called\n";
//     }
// };
// int main(){
//     A* obj = new B();
//     obj->fun(12);    // correct
//     obj->fun();      // Base class's default will print
//     return 0;
// }

// /* Default values are resolved as compile time and default values not part of signature
//    type of pointer will decide the default values
//    above type of pointer is A so A's default printed

// */

/* --------------------- Virtual destructors ------------------------------------------
    1. Destructor shows Runtinme Polymorphism although signature are not same
    2. 🚨 any time you have a virtual function in a class, you should immediately add a virtual destructor (even if it does nothing).
*/
// #include <iostream>
// using namespace std;
// class base{
//     public:
//     base(){
//         cout<<"Base class Constructor \n";
//     }
//     ~base(){                    // child class memory will not resolve
//         cout<<"Base class Desstructor \n";
//     }
//     // virtual ~base(){
//     //     cout<<"Base class Desstructor \n";
//     // }
// };
// class child:public base{
//     public:
//     child(){
//         cout<<"Child class Constructor \n";
//     }
//     ~child(){
//         cout<<"Child class Destructing \n";
//     }
// };
// int main(){
//     base* ptr=new child;
//     delete ptr; // here not any destructor of child class
//     return 0;
// }


/*---------------------------------------- Casting ------------------------
Upcasting : Converting pointer/refrence from child  to parent 
Always safer because child IS-A parent

DownCasting : Converting pointer/refrence from parent  to child
static_cast<Child*> (parent_pointer)   - not safe if parent_pointer is pointing an base class object
as static_cast<>() is compile time so if object is not actually pointing toward child onbject then it will be more dangerous like 
undefined behaviour
so use dynammic_cast(slow due to runtime checks) :
    to use dynamic_cast base class must have 1 virtual function as to know information at runtime it need vtable/vptr
    dynamic_cast use RTTI(runtime type information) which is implimented by vtable
*/

// class Base{};
// class Child:public Base{};

// int main(){
//     Child c1;
//     Base* obj = &c1;   // upcasting(implicit)

//     Child* ptr1 = static_cast<Child*>(obj);  // downcasting(not implicit)
//     // not safer of obj is not refrencing to child object
//     // so use dynamic_cast if obj is not refrencing to child object it return nullptr
//     return 0;
// }
// ================================================ Abs.
/*     Abstraction : It is principle of hiding complex implementation details and showing only essential features(interface) of an object.
    -> Separation of what and how
    focus on what object does rather than how it does
    Interface : Those essential feature(visible to outsiders) by which user interact with system
    Implementation : The actual definition of everything states in interface
    All methods are pure virtual act as interface
    2 ways to achieve
        1. Using Access specifiers (like encapsulation) with normal classes
        2. Using abstract classes (Pure Virtual Function)
            Any class with at least 1 pure virtual function in abstract class
            Cannot initialize a abstract class
            Any concrete class inherted a abstract class must have define those function properly
*/
// class Demo{   // abstract class
//     public:
//     virtual void sayHi() = 0;
// };

// int main(){
//     // Demo obj;   // 🔴 cannot initiate abstract-class object
//     return 0;
// }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Important >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// #include <iostream>
// using namespace std;
// void fun(const int* i){   // overload fine 
//     cout<<"Consta fun() \n";
// }
// void fun(int* i){
//     cout<<"Non Constant fun() \n";
// }
// int main(){
//     int i=5;
//     const int j=10;
//     fun(&i);
//     fun(&j);
//     return 0;
// }
// Explanation:-  
/*When normal variable passed in func then every func create a copy of that actual parameter.
The function cannot change original value to writing const before normal parameters is useless...
But in Pointer case is sensitive because we can change value of that pointer from anywhere in file*/

/// ----------- <> Diamond problem
//#include <iostream>
//using namespace std;
//class person{
//    public:
//    person(){
//        cout<<"Person constructor Called \n";
//    }
//    person(int x){
//        cout<<"Person Parameter constructor Called \n";
//    }
//};
//class student:virtual public person{     // diamond problem solved
//    public:
//    student(int x):person(x){
//        cout<<"student constructor Called \n";
//    }
//};
//class teacher:virtual public person{    // if not use  two member data/function created and amigious error occur    (very imp)
//    public:
//    teacher(int x):person(x){
//        cout<<"teacher constructor Called \n";
//    }
//};
//
//class common:public student,public teacher{
//    public:
//    common(int x):student(x),teacher(x),person(x){    //how to run parameterised grand_parent constructors
//        cout<<"Common constructor Called \n";
//    }
//};
//int main(){
//    common obj(6);
//    // person constructor is called twice means two copies created in obj 1
//    return 0;
// }

// -------- this is where i Got confusion in Diamond Problem (in sharing of grandparent by parent ....)
// class A{
//     public:
//     int x;
// };
// class B:virtual public A{
//     public:
//     void setA(int n){
//         this->x = n;
//     }
// };
// class C:virtual public A{
//     public:
//     void setA(int n){
//         this->x = n;
//     }
// };
// class D:public B,public C{};
// int main(){
//     B obj;
//     C obj1;
//     obj1.setA(100);
//     obj.setA(90);
//     cout<<obj.x;
// }

// --------------------------------- Disallowing function ----------------
// //  to make default functions of class unaccessable
// class file{
//     public:
//     file(string s){
//         cout<<"File is "<<s<<"\n";
//     }
//     file(file& obj)=delete;  // M-1  disallowing function
//     private:
//     void operator=(file& obj){};    // disallowing  assignment operator
// };
// int main(){
//     file f1("My one");   
//     // file f2(f1);    // cann't copy object
//     return 0;
// }


/* ---------------------- Coupling
 ----------------
    1. Tight Coupling : heavily Dependency on other classes
    2. Loose Coupling : weak dependency
*/

// class A{};
// class B{
//     A obj;   // if A not exists then B cannot intiate (Tight Coupling)
// };
