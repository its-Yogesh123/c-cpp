//     creating Alias

// Literals  Fixed Values without name interpreted as it is at compile time
    // int float string double ....
    // binary literal 0b101010
    // hex literal etc..
#include <unordered_map>
#include <vector>
#include <thread>
#include <iostream>
using namespace std;
#define vii vector<int>    //    can use vii inplace  of vector<int>
// or
using newKey = vector<vector<vector<int>>> ;     //can use newKey
// or
typedef unordered_map<int,int> hash; 


/*.  🔴 datatypes  size are not fixed  🔴 
short >= 16 bits (acc. C++ standard  to maintain backward compatibility with C)
int >= 16 bits
long >= 32 bits (windows : 32 / Mac : 64)
long long >= 64 bits
-- fixed size container
int32_t num;
int16_t num;
int64_t num;
uint32_t num;   // unsigned integer of 32 bits

-- size_t (unsigned 32/64 bit int) - can represent size of any object in memory
sizeof() return size_t object

-- ptrdiff_t (signed 32/64 bit int) - for pointer arithematic
int* p1,p2;
auto x = p2-p1; (x type is ptrdiff_t)
*/
// --- in global scope(outside main) only delcarative statement allowed 
// int a =90; // valid
// cout<<"akjsdbfak";
// if(a<5) cout<<"afa"; // not valid because never gonna to execute
// memory(variable) we may use but normale statement will never execute that scope
//#include <iostream>
//using namespace std;
//int main(){
//	int x=10;
//	
//	cout << "Hello \n"<< x<<"hoiasdfioasfj";
//	return 0;
// }
/*  NOTE : IN C++ Nested classes are not automatically tied to outer class instances.
means creating inner class object will not instantiate  upper class 
*/
//------------ scoping  (Scope Resolution Operator)
// 1). in OOPs define class member function / static variable outside class
// 2). global scope variable fetch
// 3). in namespace
//#include <iostream>
//using namespace std;
//int a=10;   // global scope
//int main(){
//	int a=20;  // local scope
//	cout <<a;     // local > global 
//	cout <<::a;   // global 
//	return 0;
//}

// 4). Nested Class / Enum / Struct Members
// #include <iostream>
// using namespace std;
// class upper{
//     public:
//     class inner{
//         public:
//         void sayHi(){
//             cout<<"Hi form inner\n";
//     };
// };
// int main(){
//     // inner obj;   // error inner not in scope
//     upper::inner obj;
//     obj.sayHi();    // working
// 	return 0;
// }

// class ColorPicker {
// public:
//     enum Color {
//         RED,
//         GREEN,
//         BLUE
//     };
// };

// int main() {
//     ColorPicker::Color c = ColorPicker::GREEN;

//     if (c == ColorPicker::GREEN) {
//         cout << "You selected GREEN" << endl;
//     }
// }

//------- wide characters
//#include <iostream>
//using namespace std;
//int main(){
////	char x='a';
//	wchar_t var1=L"ellloh";   
//	cout <<var1<< endl;
//	return 0;
//}




/*          Default Arguments
    Either delare in declaration or in difinition not in both
    Default params not part of signature(no overloading)
    On right side of default params all params must be default
*/

// void fun(int =0,int =9);    // valid 🟢
// int main(){
//     fun();
//     return 0;
// }

// void fun(int a=0,int b=9){   // error on redefinition of default params
//     cout<<"Hi";
// }

//------------------------- integer promotion                                   (imp)
//#include <iostream>
//using namespace std;
//int main(){
//	char a=30,b=40,c=10;
//	char d=(a*b)/c;  // in calculation a*b = 1200 but char only upto 256(max) it means (not char overflowing)
//	                // while calculating char is promoted to int or unsigned int
////	cout <<+d;     // to print numbers(ASCII value)
//	cout <<d;
//	return 0;
//}


//-------    2nd example                                                                   (v.imp)
//#include <iostream>
//using namespace std;
//int main(){
//	char a=0xfb;   // using hexa-decimal literal (store as 2's compliment)
//	unsigned char b=0xfb;
//
////	cout <<+b;     // to print numbers
//	cout <<"a is "<<a <<endl<<"b is "<<b << endl;   // a and b are same characters
//	cout <<"a is "<<+a <<endl<<"b is "<<+b;   // a and b have diff values
//}
//---------------------------------------- Type conversion ------------------------------------------
/* Type conversion is the process by which a value is changed  from one data type to another compatible data type.
1. Implicit Conversion : (automatic conversion can be wider or narrow conversion)
    Compiler convert one type to another automatic
        Type Promotion (alsways safer): It is the automatic conversion of a smaller data type to a larger one to avoid data loss.
            Integer Promotion(any smaller data_type to int/unsigned int)
            Floating Point Promotion(float to double)
    Note : Can be narrowing char c =780; (int to char)
2. Explicit Conversion (Type Casting)  : Programmer
    Old/C Style (unary operator) : (int)a
    Static Cast, Dynammic, const cast and reinterpret casting
*/


// implicit conversion
// int main(){
//     // char a =776;    // narrow conversion
//     // int b = 364.89;   // implicit narrow conversion  (double to int)
//     // float c = 7.90;   // narrow conversion (double to float)

//     // int c = 'a'; // type promotion (in c++)
//     // short int sA = 34;   // implicit narrow type conversion
//     // int A = sA;       // (type promotion)

//     // any arithmetic on data smaller than int will promoted to int
//     // short a =89,b=90;  // narrow conversion
//     // short c = a+b;    // type promotion then narrow conversion(int to short)
//     // // better way
//     // short c = static_cast<short> (a+b); // or
//     // int c = a+b;
// }

// explicit conversion
/*
--------------------- 1st  static_cast<>()
syntax static_cast <new_datatype> (expression);
safer than  unary() because it doesn't allow invalid cast
compatible with conversion operator
In inheritence support Upcasting(parent me chile address) + downcasting(parent to child conversion)
cast to any pointer type to void* and vice versa
*/

// int main(){
// // 	float a=2.5;
// // 	int b=a*3;
// // //	int c=(int)a*3;  // working (C- style)
// // 	int c=static_cast <int> (a)*3; // working well (modern/C++ style more safer)
// // 	cout << b <<endl;
// // 	cout << c <<endl;
//     // char c='a';
//     // int* ptr = (int*) &c;   // no error but invalid conversion
//     // cout<<*ptr;
//     // int* ptr1 = static_cast<int*>(&c);      // give compile error doesn't allow invalid conversion
//     int a=9;
//     void* ptr = static_cast<void*> (&a); 
//     int* ptr1 = static_cast<int*> (ptr);
// 	return 0;
// }

// class integer {
//     int x;
// public:
//     integer(int x_in = 0)
//         : x{ x_in }
//     {
//         cout << "Constructor Called" << endl;
//     }
//     operator string()
//     {
//         cout << "Conversion Operator Called" << endl;
//         return to_string(x);
//     }
// };

// class Base{};
// class Child:private Base{};
// int main()
// {
//     // integer obj(3);
//     //  

//     // // using static_cast for typecasting
//     // string str2 = static_cast<string>(obj);
//     // obj = static_cast<integer>(30);   // temp object creating then copy constructor

//     // why static_cast better
//     Child c1;
//     Base* b1 = (Base*)&c1;  // C-style conversion no error which is disaster as base is not accessible thorugh c1(private inheritence)
//     Base* b2 = static_cast<Base*>(&c1);  // compile error
//     return 0;
// }




//------------------------ 2nd Dynamic Cast
// convert one into another at runtime (used special in Polymorphic conditions) + downcasting
// parent has multiple child then downcasting 
// if casting fails and casting via 
    // pointer then return nullptr and if refrence then throw an exception
// class Base{
//     public:
//     virtual void fun(){};
// };
// class Child1:public Base{};
// class Child2:public Base{};
// int main(){
//     Base* obj = new Child1();
//     Child2* ptr = dynamic_cast<Child2*>(obj); // check at runtime
//     if(ptr)cout<<"Success";
//     else cout<<"Casting Failed";
//     return 0;
// }


//------------------------ 3rd const_cast---------------
// used to remove temporary constancy of const variable
// const_cast <new_type> (expression)
// class Demo{                                                                                            ------ IMP
//     int a;
//     mutable int b;   // can changed by const function also
//     public:
//     void check()const {    // cannot change state of object
//     // a=90;   // error
//     // b=90;   // no error 
//     const_cast<Demo*>(this)->a=90;   // works fine.
//     cout<<a;
//     }
// };


// int main(){
//     // const int a=90;
//     // const_cast<int&>(a);   // wrong and will give undefined behavior                                  ---  (imp)
// 	const int a=5;
// //	int b=a;       // possible
// //	b=40;
// 	const int* ptr=&a;     // value of a will not change 
// //	int* ptr1=ptr;              // not possible that is why ???
// 	// int* temp=const_cast<int*> (ptr);     // const_cast is introduce
// 	// *temp=20;
//     // cout<<*temp<<endl;   // UB(undefined behaviour)
// 	// cout <<a;
//     // Demo obj1;
//     // obj1.check();

//     // ------------ use const_cast with not truly const variable
//     // int val1=90;      // not const
//     // const int* ptr=&val1;     // ptr is not truly const
//     // *const_cast<int*>(ptr)=100;  // change in val1 
//     // cout<<val1;
// 	// return 0;
// }
//------------------------ 4th reinterpret_cast                                                  (imp)
//used to convert the pointer to any other type of pointer
//#include <iostream> 
//using namespace std;
//int main(){
//	int a=5;
//	char ch=1;
//	cout <<ch;
//	int* ptr1=&a;
////	char* ptr2=&a;  // not possible
//	char* ptr2=reinterpret_cast <char*> (ptr1);
//	cout <<*ptr2; 
//	return 0;
//}

//-------------------- if-else -----same as in C
// ------------------------------------------- Range in switch case ----------------------------
//#include <iostream>
//using namespace std;
//int main(){
//	int a=5;
//	int n;
//	cout<<"Enter a number : ";
//	cin >>n;
//	switch(a){
//		case 1:{
//			cout <<"Number is 1";
//			break;
//		}
//		case 2 ... 6:{          // also in C
//		cout <<"Number is between 2 and 6";
//		break;
//		}
//	}
//	return 0;
//}

// ------------------------------------------- Range in for loop ----------------------------
//#include <iostream>
//using namespace std;
//int main(){
//	int x[]={11,22,33,44};
//	for(int i:x){
//		cout<<i<<'\n';        // work on latest compilers
//	}
//	return 0;
//}
//--------------------------------------------- function
//#include <iostream>
//using namespace std;
//int fun(int a,int b){
//	cout<<a+b;
//}
//int main(){
//	int (*ptr)(int,int)=&fun;   // function pointer
//	(*ptr)(3,5);
//	return 0;
//}



//--- function overloading
// #include <iostream>
// using namespace std;
// int sum(int a,int b){
// 	cout<<a+b<<'\n';
// }
// int sum(int a,int b,int c){
// 	cout<<a+b+c<<'\n';
// }
// int main(){
// 	sum(1,2);
// 	sum(1,2,3);   // function overloading
// 	return 0;
// }
//       🔴 IMP
// double fun(double a){
//     return a+1;
// }
// double fun(float a){
//     return a+0.1;
// }
// int main(){
//     cout<<fun(1);    // error 
// }
/* Error because int  to float and int to double both are standard valid conversions so compiler
ambigious which one to do
*/


//--------------------------------------------- Inline funtion ----------------
//#include <iostream>
//using namespace std;
//inline void sum(int a,int b){   // inline function
//    cout<<a+b<<endl;
//}
//int main(){
//    sum(1,3);
//    return 0;
//}
/* -----------------------------------------------🚨🚨🚨🚨 Pointers 🚨🚨🚨🚨-----------------------------------------------

==> a pointer is a special type of variable
Size (Memory Address size - depend on archetechture): 4 Bytes(32-bit) 8 bytes (64-bit)
* - Indirection Operation (indirectly Access to memory)
    1. Null Ptr : Null(doesn't pointing to any)
        *pre =0;    means nullptr
    2. Dangling Ptr : Pointing to Deallocated/Invalid memory
    3. Wild Ptr : Declared but not Initialize 
        Note(for both Wild + Dangling) :  primarily related to debugging, prevention, and communication.
        Issue? : These type of pointer may points to any valid(real object) and make unwanted changes (undefined behaviour) so 
        Smart Pointer just restrict the wild/dangling pointer creation (prevention) but not the memory access means any other wild pointer may access and make
        changes the location pointed by smart pointers
    4. Generic Pointer (void*) -> pointer to unknown type 
        can store address of any object except functions
        in C++ only support explicit conversion using static_cast (in C implicit supported)
    5. Funciton Pointer
    6. Smart Pointers
*/

// const int* funA(){                 // imp🟢
//     int a=90;
//     return &a;
// }
// int main(){
//     const int*  a= funA();
//     *a =90;
//     cout<<a;
//     return 0;
// }


//#include <iostream>
//using namespace std;
//// illustrating void pointer                                   Applications of void pointer
//void increase(void* data,int size){
//    if(size==sizeof(char)){
//        cout << "*Data Contains Character \n";
//        char* new_ptr;
//        new_ptr=(char*)data;           // primitive type_casting like in C
//        (*new_ptr)++;
//    }
//    else if(size==sizeof(int)){
//        cout << "*Data Contains Integer \n";
//        int* new_ptr;
//        new_ptr=reinterpret_cast<int*>(data);  // typecasting methods
//        (*new_ptr)++;
//    }
//}
//int main(){
//    char i='a';
//    int j=10;
//    increase(&i,1);
//    cout << "New Value is "<<i<<endl;
//    increase(&j,1);
//    cout << "New Value is "<<j<<endl;
//    return 0;
//}


// //#include <iostream>
// //using namespace std;
// int main(){
// 	int* ptr = 0;
// 	int* ptr = null;   // null pointers
// }

//     array of pointers

/* ----- Pointer Arithmetic
    1.Incrementing and Decrementing
        ++ or --
    2.Addition of Integer : new_ptr = ptr + n*sizeof(ptr);
    3.Subtraction of Integer : new_ptr = ptr + n*sizeof(ptr);
    4.Subtraction of Two Pointers of the Same Type : Give element/block of memo in b/w
    5. 🔴 Addition of 2 pointer doesn't make any sense
    6. Comparison of Pointers and NULL
    7. Double pointers (**)

*/

/*---------------------------------------------- Refrences
    1. Must Initialized at declaration with l-values
    2. Cannot Null
    3. Cannot reassigned to new object
*/
//#include <iostream>
//using namespace std;
//int main(){
//	int x=20;
//	int& ref=x;  // no address pass unlike pointer
//	
//	x=30;
//	cout<<x<<"and "<<ref<<endl;  // value change in both 
////	-
//	ref=60;
//	cout<<x<<"and "<<ref<<endl;
////	--
//	
//	return 0;
//}
// // ------------ 1). to modify value in func
// void inv(int& x,int& y){     // no copies of actual parameters
//     int temp=x;
//     x=y;
//     y=temp;
// }
// int main(){
//     int a=5,b=7;
//     cout<< "The value of a and b : "<< a<<" "<< b<<'\n';
//     inv(a,b);
//     cout<< "The value of a and b : "<< a <<" "<< b;
//     return 0;
// }
// --------- 2). avoiding copies (large structures)
// struct parent{
//     int age;
// }boy,girl;
// // void data(struct parent baby){// here if we call function then first it creat a copy of full structure then use it
// //     // ...
// // }
// void data(struct parent &baby){  // we use original data no copies
//     cout<< "Child with age : "<<baby.age;
// }
// int main(){
//     boy.age=10;
//     girl.age=12;
//     data(boy);
//     return 0;
// }

// ------------- 3). modify/avoid to make copies object in for each loops
//int main(){
//    int num[]={1,2,3,4,5};
//    for(int& i:num){
//        i*=2;
//    }
//    for(int& i:num){
//        cout<<i<<endl;
//    }
//    return 0;
//}

/*--------------------------- string ------------             ( 🔴🔴🔴🔴VVV. IMP)
string in C++(can also create like in C)
    string literal are in read-only memo-segment which decays to const char* 
*/
// #include <iostream>
// using namespace std;
// int main() {
//     // char str[] = {'Y','o','g','e','s','h','\0'};   // string in C-style
//     // char str[] = {'Y','o','g','e','s','h'};   // normal character array
//     // cout<<str;
//     // char str1[]="Yogesh";
//     char* str1="Yogesh";  // ⚠️🔴🔴🔴 Warning because we are assiging const char* to char* 
//     str1[0] ='s';   // if we see the str1 there is nothing const or something means at compile time
//     // compiler will raise no error as type is not const so we can change but at runtime when we try to
//     // write on read only memory then error
//     cout<<str1; // error
//     // cout<<str1;
//     // string str1("Helli this is Yogesh Kumar");  // method 1 constructors
//     // string str2="hi";                           // method 2 conversion constructor(convert string literal into string object)
//     // cout<< str1;
//     // cout<< endl<<str2;
//     return 0;
// }

//---------------------------- string as input 
// cin
// int main() {
//     string str1;
//     cin>>str1;       // like scanf untill space
//     cout<<str1;
//     return 0;
// }
// --- getline
// int main() {
//     string str1;
//     getline(cin,str1);       // like gets untill newline
//     cout<<str1;
//     return 0;
// }

// --------- string_stream
//It is used to take multiple strings as input at once. 
//#include <sstream>  // header file
//int main(){
//    string str1="hello this is Yogesh Kumar";
//    stringstream obj(str1);
//    string temp;
//    obj>>temp;   // extract word (in each run) form str1
//    cout<<temp;
//    return 0;
//}


//---------------- string functions 
//#include <iostream>
//#include <string>
//using namespace std;
//int main(){
//	string s1="hello this is Yogesh Kumar";
//	string s2="yogesh kuamr";
//	cout<<s1.length()<< "|"<<s2.length();  // for length
//	return 0;
//}


//------------------------------------------------   Structures in C++ -----------------------
// all definition is like C
//#include <iostream>
//using namespace std;
//struct parent{
//    int age=0;   // error in C but 
//    int id=0;    // considered as default value in C++
//    void detail(){  // in C++ can create member function
//        cout<<endl<<"Age is : "<<age<<" and id : "<<id;
//    };
//};
//int main(){
//    struct parent boy={17,987240};
//    struct parent girl;  // default value print
//    boy.detail();
//    girl.detail();
//    return 0;
//}

//------------Structures support access modifiers
//#include <iostream>
//using namespace std;
//struct car{
//    private:
//    int price=2000;
//    public:
//    int model;
//    int mfd;
//    void price_d(void){
//        cout<<"Enter Price of car : ";
//        cin>>price;
//        cout<<"Price of Car "<<model<< "is "<<price; // can be access internally  (this function is internal)
//    }
//};
//int main(){
//    struct car bmw;
//    bmw.model=333;  // can be accessed or modify
//    // bmw.price=222222; // Error !!cannot accessed externally
//    cout<<bmw.model<<endl;
//    bmw.price_d();  // can be accessed 
//    return 0;
//}
//--------------
/*---------------- Enumerators (define symbolic name to integral constants )
An enum (enumeration) is a user-defined type that represents a set of named integral constants. 
    Normal Enum
        implicit type conversion to Int
        ❌ No type safety — enum values are just ints under the hood.
        ❌ Enum names pollute the outer scope.(No scoping just wrapped INT values)      ⚠️
    Scoped Enum(Enum Class)
        all issue solved
*/
// enum values{val1,val2,val3,val4};
// // if not assigned value then starting value is 0
// // the value of next is previous+1;
// enum values1{value1=5,value2};  // counting start with 5
// int main(){
//     int i;
//     // cout<<val1<<endl
//     // <<val2<<endl
//     // <<val3<<endl
//     // <<val4<<endl;
//     // cout<< value2;
//     return 0;
// }

// -- issue
// enum COLOR{RED,GREEN};
// enum COLOR2{GREEN,RED};       // error
// int main(){
//     cout<<GREEN;  // to to scope there is ambiguity
// }
//     ----- enum class
// enum Color0{RED,GREEN};
// // enum class Color{RED,GREEN};
// // enum class Color1{RED=10,GREEN};
// int main(){
//     // cout<<Color1::RED<<endl;  // require type casting
//     // cout<<Color::RED;
//     int a = RED;  // implicit conversion
//     cout<< static_cast<int> (Color1::RED)<<endl;
//     cout<< static_cast<int> (Color::RED);
//     return 0;
// }
// -------------- application
// enum Gender{Male,Female};
// int main(){
//     Gender gender=Male;
//     if(gender==Male){
//         cout<<"Male is here";
//     }
//     return 0;
// }

// ---------- year function
//enum year{
//    jan,feb,mar,apr,may,june,
//    july,aug,sep,oct,nev,Dec};
//int main(){
//    int i;  // jan is name representing a integer
//    for(i=jan;i<=Dec;i++){
//        cout<<i<<endl;
//    }
//    return 0;
//}


// -----------------------Dynamic memory allocation in C++ -----------------------
// new and delete operators
// placement_new operator
// syntax  new d_type(value)  -- create only single block and store value in it
// new d_type[n] -- create n block
//#include <iostream>
//using namespace std;
//int main(){
//    // int* ptr=new int;  //an int block is created
//    // *ptr=45;
//    // cout<<*ptr;     // work
//    // int* ptr=new int(50);
//    // cout<<*ptr;
//    // ------------- block of memory
//    // int *ptr = new int[5]; //an dynamic array;
//    // int *ptr = new int[5](); //   will also intialised each block with respective default values(0 for int nul for pointers)  ----   (imp)
//    // ptr[0]=1; ptr[1]=2; ptr[2]=3; ptr[3]=4; ptr[4]=5;
//    // cout<< ptr[3];    // working
//// ----  delete keyword for free memory
//    int *ptr1=new int;
//    int *ptr2=new int[10];
//    delete ptr1 // delete only one block
//    delete[] ptr2 // delete entire block or array
//    return 0;
//}






//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part IInd <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,
/* ------------------- Exception Handling ------------------------


🟢 Stack Unwinding : 
🟢 Exception Propagation: 
🟢 Rethrowing Exception: 
1. Throw by value catch by const refrence
2. RAII (because on stack unwinding when object get destroyed but not the dynammic memory allocation)
3. Destructor should not throw exception

noexcept (will not throw exception)
noexcept(false) - default (may throw exception)

Note :
    All types can be throw (in java only throwable objects)
    throw (same as throws in java) but before c++11 now only use noexpect
    No Type promotion in try catch
    Object are destrioyed in reverse order they created
*/

// int fun() throw(runtime_error,logic_error){}   // 🔴 valid only before c++11 removed afterward

// class exception {
// public:

//     exception() noexcept;
//     exception(const exception&) noexcept;
//     exception& operator=(const exception&) noexcept;
    
//     virtual ~exception();
//     virtual const char* what() const noexcept;
// };
// try{}
// catch(exptype1 e1){}
// catch(exptype2 e2){}
// catch(exptype3 e3){}
// catch(...){if not match any above}

// order e1 e2 e3 should be in order specific to general

// class A{
//     public:
//     ~A(){
//         cout<<"Destructor Called ";
//         // throw exception();   // ❌ not
//     };
// };

// int funA(){
//     A obj;
//     throw exception();
// }
// int main(){
//     try{
//         funA();
//     }
//     catch(const exception& obj){
//         cout<<"Exception Caught\n";
//     }
//     return 0;
// }


// built-in exception(not catch by exception class)

// int main(){
//     try{
//         throw 1;
//     }
//     catch(int a){
//         cout<<a;
//     }
//     return 0;
// }

// ---------------------  why RAII
// class A{
//     public:
//     ~A(){
//         cout<<"Destructor Called ";
//         // throw exception();
//     };
// };
// void fun(){
//     A* obj = new A();      // dynamically allocated object not get freed upon stac unwinding
//     throw 1;
// }

// int main(){
//     try{fun();}
//     catch(const exception& e){
//         cout<<"Catched";
//     }
//     catch(int a){
//         cout<<"Catched";
//     }
//     return 0;
// }



// standard exception (predefined exception)
// custom exception (predefined exception)
// class no_int_exception:public exception{
//     public:
//     const char* what()const noexcept override{
//         return "No Integer Exception occur";
//     }
// };
// void fun(){
//     throw no_int_exception();
// }

// int main(){
//     try{fun();}
//     catch(const no_int_exception& e){
//         cout<<e.what()<<" Hi";
//     }
//     catch(const exception& e){
//         cout<<e.what();
//     }
//     return 0;
// }

// Rethrowing exception
// int main(){
//     try{
//         // throw runtime_error();   // error beccause runtime_error does not have default constructor
//         throw runtime_error("Something went wrong");
//     }
//     catch(const runtime_error& e){
//         cout<<e.what()<<" Hi\n";
//         throw;
//     }
//     catch(const exception& e){
//         cout<<e.what() <<"Finally last ";     // error because rethrow exception will go upward outside this try catch
//     }
//     return 0;
// }

// int main(){
//     try{
//          try{
//         throw runtime_error("Something went wrong");
//     }
//     catch(const runtime_error& e){
//         cout<<e.what()<<" Hi\n";
//         throw;
//     }
//     }
//     catch(const exception& e){
//         cout<<e.what() <<"Finally last ";    // now no error
//     }
//     return 0;
// }


// ---------------- user define exception

// class A{};
// class B:public A{};
// int main(){
//     try{
//         throw B();
//     }
//     catch(const A& obj){     // exception with inheritence
//         cout<<"Exception Caught\n";
//     }
// }
// ---------------- exception with constructor (throw in constructor then des will not called)
// why?????
// In C++, constructors often acquire resources — e.g.:
// Allocating dynamic memory, Opening a file, Establishing a network connection, Creating a thread
// If any of these fail, you can’t properly construct the object.
// So instead of creating an invalid or half-initialized object,
// you throw an exception from the constructor.
// class A{
//     public:
//     A(int x){
//         if(x==5)throw "Not valid Num";
//         cout<<"Object constructed\n";
//     }
//     ~A(){
//         cout<<"Object Destructed\n";
//     }
// };
// int main(){
//     try{
//         // throw A(2);   // need not to throw
//         A(8);
//         A(5);
//         A(8);
//     }
//     catch(const char* &obj){     // exception with inheritence
//         cout<<"Exception Caught\n"<<obj;
//     }
// }


//----------------------------- File Handling --------------------------
//#include <iostream>
//#include <fstream>
//using namespace std;
//int main(){
//	// creting new file and insertion data using insertion operator
//	ofstream file;
//	file.open("./files/demo1.txt");  // if file is not then will created
////	file<<"Hello this is Yogesh Kumar";  // insertion operator to store data
//	string name="YOgesh Kumar";
//	file<<name;
//	file.close();
//	return 0;
//}

//---
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main(){
//	ofstream file;
//	file.open("./files/demo1.txt");
//	string line;
//	while(true){
//		getline(cin,line);
//		if(line=="-1"){
//			break;
//		}
//		file<<line;
//		file<<'\n';  // for newline
//	}
//	file.close();
//	return 0;
//}

//------ reading a file
//#include <iostream>
//#include <fstream>
//using namespace std;
//int main(){
//	ifstream file;  // input stream object
//	file.open("./files/demo1.txt");
//	char ch;
////	file>>ch;   // read only character
////	cout<<ch;
//	while(!file.eof()){   // eof -- end of file
////	file>>ch;
////	cout<<ch;   // it will not read space or any special character
////	to handle this use get function
//	ch=file.get();
//	cout<<ch;
//}
//	file.close();
//	return 0;
//}
//----------- both simultaneously
//#include <iostream>
//#include <fstream>
//using namespace std;
//int main(){
//	fstream file;
//	file.open("./files/demo1.txt",ios::app | ios::in);
//	while(true){
//		string line;
//		cin>>line;
//		if (line=="-1"){
//			break;
//		}
//		file<<line;
//		file<<'\n';
//	}
//	while(!file.eof()){
//		cout<<file.get();
//	}
//	file.close();
//	return 0;
//}


//tellg() -- input stream  and tellp() -- output stream

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main(){
////	ifstream file1;
////	file1.open("./files/demo2.txt");
////	while(!file1.eof()){
////		char ch;
////		cout<<file1.tellg()<<endl;
////		ch=file1.get();
////	}
////	file1.close();
////--- tellp()  function
//	fstream file;
//	file.open("./files/demo2.txt",ios::app);
//	cout<<file.tellp()<<endl;
//	file<<"Hello this is";
//	cout<<file.tellp();
//	file.close();
//	return 0;
//}

//------------------- seekg() and seekp()

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main(){
//	ifstream file;
//	file.open("./files/demo2.txt");
//	cout<<file.tellg()<<endl;
//	char ch=file.get();
//	cout<<file.tellg()<<endl;
//	file.seekg(0,ios::beg);   // come to initial pos
//	cout<<file.tellg()<<endl;   
//	char ch1=file.get();
//	cout<<ch1;
//	file.close();
//	return 0;
//}

//>>>>>>>>>>>>>>>>>>>>>>>>> templates <<<<<<<<<<<<<<<<<<<<<<<
//#include <iostream>
//using namespace std;
//template <typename T>
//T max1(T x,T y){
//	return (x>y)?x:y;
//}
//int main(){
//	cout<< max1<int>(5,7);
//	cout<< max1<char>('z','x');   // this is how templates works
//	return 0;
//}
//------------- application
//#include <iostream>
//using namespace std;
//template <typename T>
//void bubble_Sort(T* array,int n){
//	int i,j;
//	for(i=0;i<n;i++){
//		for(j=i;j<n;j++){
//			if(array[i]>array[j]){
//				T temp=array[i];
//				array[i]=array[j];
//				array[j]=temp;
//			}
//		}
//	}
//}
//template<typename T>
//void print(T array[],int n){
//	int i;
//	for(i=0;i<n;i++){
//		cout<<array[i]<<endl;
//	}
//}
//int main(){
//	int n=10;
//	int array1[n]={3,7,1,9,4,5,0,11,22,80};
//	char array2[n]={'s','p','q','a','y','d','m','h','o','c'};
//	bubble_Sort<int>(array1,n);
//	bubble_Sort<char>(array2,n);  // working well
//	print<int>(array1,n);
//	print<char>(array2,n);
//	return 0;
//}
//
//
//
//
//--------------- Template Class
//#include <iostream>
//#include <string>
//using namespace std;
//template <typename T>
//class demo{
//	T data;
//	public:
//		demo(T value){
//			this->data=value;
//		}
//		T get(){
//			return this->data;
//		}
//};
//int main(){
//	demo<int> d1(5);
//	demo<float> d2(6.009);
//	demo<char> d3('l');
//	demo<string> d4("Yogesh Kumar");
//	cout<<d1.get()<<endl;
//	cout<<d2.get()<<endl;
//	cout<<d3.get()<<endl;
//	cout<<d4.get()<<endl;
//	return 0;
//}


//-------- Array of any datatype
//#include <iostream>
//#include <string>
//using namespace std;
//template <typename T>
//class Array{
//	T* data;
//	int size;
//	public:
//		Array(T arr[],int s);
//		void print();
//};
//template<typename T>Array<T>::Array(T arr[],int s){
//	data=new T[s];
//	size=s;
//	int i;
//	for(i=0;i<s;i++){
//		data[i]=arr[i];
//	}
//}
//template<typename T>void Array<T>::print(){
//	int i;
//	for(i=0;i<size;i++){
//		cout<<data[i]<<" ";
//	}
//}
//int main(){
//	int arr1[]={4,6,7,2,4};
//	char arr2[]={'a','b','z','x'};
//	Array<int> array1(arr1,5);
//	Array<char> array2(arr2,4);
//	array1.print();
//	cout<<endl;
//	array2.print();   // wprking properly
//	return 0;
//}

//--------->>>>>>>>more than one dataype as parameter
//#include <iostream>
//#include <string>
//using namespace std;
//template<typename T,typename U =char>   // can be assign default data-type
//class demo{
//	T x;
//	U y;
//	public:
//		demo(T a,U b){
//			x=a;
//			y=b;
//		}
//		void get(){
//			cout<<"First Value is : "<<this->x<<endl;
//			cout<<"Second Value is : "<<this->y<<endl;
//		}
//};
//int main(){
//	demo<int,char> d1(5,'x');
//	d1.get();
//	return 0;
//}

//------------------- templates with static variable
//#include <iostream>
//using namespace std;
//template <typename T>
//T demo(T value){
//	static int i=0;
//	i++;
//	return i;
//}
//int main(){
//	cout<<demo<int>(1)<<endl;  // 1
//	cout<<demo<int>(1)<<endl;  // 2 as we know
//	cout<<demo<float>(1.1);    // 1 why??
//	return 0;
//}

/*  Explanation :- For different datatypes there is separate copy of static variable
for int static i different for static float 
*/


// -- Template Argument Deducting
// implicit deducting of datatypes
//#include <iostream>
//using namespace std;
//template <typename T>
//T print(T a){
//	return a;
//}
//int main(){
//	cout<< print(5); 
//	cout<< print("H");   // we not explicit tell about data type of arguments
//	return 0;
//}


//--------------------------- Templates Specialization ------
//// used for performing a certain task for defferent data-type
//#include <iostream>
//using namespace std;
//template <typename t>
//void print(t var){
//	cout<<"This is Main Template Function"<<endl;
//}
////-- template specialization
//template<>
//void print(int a){     // both function name should be same
//	cout<<"Int DataType is Passed as Argument"<<endl;
//}
//int main(){
//	print<char>('a');
//	print<int>(5);
//	return 0;
//}

// same for class
//>>>>>>>>>>>>>>>>>>>>>>>>>>>> Standard Template Library <<<<<<<<<<<<<<<<<<<<<<<<
// algorithm given in STL 
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main(){
//	int arr[]={1,7,90,3,5,2,180};
//	sort(begin(arr),end(arr));
//	for(int i:arr){
//		cout<<i<<" ";
//	}
//	return 0;
//}

//----------------------- Array STL ----------------
//#include <iostream>
//#include <array>   // this header file to  use function of array class
//using namespace std;
//int main(){
//	array<int,8> arr={4,5,6,7,8,9,1,2};
//	cout<<arr.at(0);   // use to access the element of array
//	cout<<get<1>(arr);   // same like above
//	cout<<arr[2]; // normal array method
//	cout<<arr.front();       // return the first element refrence
//	int& lastElement=arr.back();       // return the last element  refrence
//	cout<<endl;
////	--
//	cout<<arr.size();   // return no. of element in aray
//	cout<<arr.max_size();   // return max size of array
//	return 0;
//}



//----------------- vector -----------------
// they are  dynamic array
//
//#include <iostream>
//#include <vector>
//using namespace std;
// int main(){
// 	vector<int> vec={1,2,3,4,5,6};  // using initialising list
//     // vector<int> res{2,2};
//     // vector<int> vec({1,2,3,4,5,6});
//     // vector<int> vec(iterator1,iterator2);
////	for(int i:vec){
////		cout<<i<<" ";
////	}
////-- to print the vector
//	auto i=vec.begin();
//	while(i!=vec.end()){
//		cout<<*i<<" ";
//		i++;
//	}
////	vec.push_back(10); // insert an element at th enf of vector
////	cout<<*(vec.begin());   // return  the iterator of first element
////	cout<<*(vec.end());   // return  the iterator of last element
//	return 0;
//}
//----------- vector with iterators
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(){
//	vector<int> vec={4,11,6,7,8,9};
//	auto i=vec.begin();  // i is iterator object
//	i++;
//	cout<<*i<<endl;
//	return 0;
//}
//------ methods of vector
// 1). size()
// 2). max_size()
// 3). capacity()
// 4). resize(int)
// 5). empty()  --> 
// 6). shrink_to_fit()
// 7). clear()
// 8). erase()
// 9). push_back()
// 10). pop_back()   // not return the popped element
// 11). ()
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(){
//	vector<int> vec={7,8,9,10,55,77};
//	vector<int> vec1={};
//	vec.resize(10);
//	cout<<vec.size()<<endl;
//	cout<<vec.max_size()<<endl;
//	vec.shrink_to_fit();
//	cout<<vec.max_size()<<endl;
//	cout<<vec.capacity()<<endl;
////	int a=vec.pop_back();  // error
//	return 0;
//}

/*  Points :- 
  ==> We cannot use intializing list {} with ternary operator
*/
// ------------------------- sets ---------------
// #include <unordered_set>
// unordered_set<int> s1;
// s1.insert(int_value)   
 // return a pair in which second value give success or not and first is an Iterator of inserted element
//>>>>>>>>>>>>>>>>>>>>>> Namespace <<<<<<<<<<<<<<<<<<<
//#include <iostream>
//namespace space1{
//	void fun(){
//		std::cout<<"I am a Fun function of space 1";
//	}
//}
//namespace space2{
//	void fun(){
//		std::cout<<"I am fun function of space 2";
//	}
//}
//using namespace space1;
//int main(){
//	fun();  // or
//	space1::fun();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//namespace first{
//	int value=10;	
//};
//namespace second{
//	double value=20.000059;
//}
//int main(){
//	cout<<first::value<<endl;
//	printf("%lf",second::value);
//	return 0;
//}
////-------------------------- unnamed namespace ----------------
//#include <iostream>
//using namespace std;
//namespace {
//	int x=10;
//}
//
//int main(){
//	int x=20;
////	cout<<::x;       // namespace variable will print
////	cout<<x;      // main function variable will print (override the namespace variabele)
//	
//	return 0;
//}
////	  if not define then namespace variable will print

//#include <iostream>
//using namespace std;
//namespace one{
//	int a=23;
//	namespace two{
//		int value=3;
//	}
//}
//namespace second{
//	inline namespace third{
//	int value=90;
//	}
//}
//int main(){
//	cout<<one::two::value<<endl;
////	cout<<one::value<<endl;   // show error  to handle this use inline
//	cout<<second::value;
//	return 0;
//}

//------------ or 2nd method
//#include <iostream>
//using namespace std;
//namespace ns1{
//	namespace ns2{
//		namespace ns3{
//			int var=60;
//		}
//		using namespace ns3;
//	}
//	using namespace ns2;
//}
//int main(){
//	cout<<ns1::var<<endl;
//	return 0;
//}
// --------------- Const_Keyword --------------
// const int fun(){}   // useless const
// const int& fun1(){}   // work
// int fun()const {}  // cannot change member variables (or state of object)
// int fun(const int a){}   // useless const  


/*               Key Points
after deleting it returns the iterator pointing to next element
*/ 
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Tokenizing of String <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// O(n)  --> time complexicity
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//    vector <string> data;
//    string s1="hhome/./../..../....helllo";
//    stringstream obj1(s1);   // creating a object of stringStream 
//    string token;
//    while(getline(obj1,token,'/')){
//        data.push_back(token);
//    }
//    for(int i=0;i<data.size();i++){
//        cout<<data[i]<<endl;
//    }
//    return 0;
//}
// -------------- lambda expression  or anonymous functions
// syntax[caputer clause ](params)->return_type{ definition };
// #include <iostream>
// using namespace std;
// // void callLambda(void fun()){
// //     fun();
// // }
// int main(){
    // int a=0;
    // callLambda([](){cout<<"Hello I'm lamda";});  // works fine

    // ---- capture clause
    // int a=7;
    // int b=89;
    // auto lambda=[&]()->void{    // can change all the surrounding variable value
    //     a*=2;
    // };
    // auto lambda1=[a,&b]()->void{    // or we can specify every variable capture type
    //     // a=2;       //  can't change so error 
    //     b*=2;       // capture by refrenc means can change
    // };
    // cout<<a<<" "<<b<<"\n";
    // // lambda();
    // lambda1();
    // cout<<a<<" "<<b<<"\n";   // value change
    // return 0;
// }


/*   Key Point                                                                ********IMP********
1). In Sorting, Lambda function used to how two pair differentiate
2). In priority_queue lambda used as custom comparator
3). IN lower and upper bound
4). We cannot create a Lambda funtion as member usign auto
*/
// ******************* Custom Comparator ************************
// --- in std::sort()   can define as 5 types
// 1 sort(it1,it2,greater<int>())   // default

// bool compare(){}    // normal free function (not a member of any class)
// 2 sort(it1,it2,compare)   // default

// static bool compare(){}    // member function of a class 
// 3 sort(it1,it2,compare)   // default

// auto compare=[](){}  // lambda function 
// 4 sort(it1,it2,compare)   // default


// --------------------------------------🚨🚨🚨🚨🚨🚨 Multithreading 🚨🚨🚨🚨🚨🚨------------------------------
#include <thread>
/* syntax : thread name(callable)
    callable: 
        function
        static/not-static member methods
        functor
        lambda expression
*/
void fun(){
    for(int i=0;i<10;i++)cout<<"Child Thread "<<i<<endl;
}
int main(){
    thread t1(fun);
    for(int i=0;i<10;i++)cout<<"Main Thread "<<i<<endl;
    // cout<<t1.joinable()<<endl;
    // t1.join();  // merging thread to parent
    t1.detach();     //(child may not exectue completly because main thread will terminate then all thing terminate)

    if(t1.joinable())t1.join();
    return 0;
}









// // --  funcion object or functors
// /* Functors :- Callable objects are functors (operator overloading must) 
// otherwise it will not callable
// */
// class c1{
//     public:
//     c1(){};
//     void operator() (){
//         cout<<"Hi ()";
//     }
// };

// // ------- using static and non static member
// class c2{
//     public:
//     void nonStatic(string name){
//         cout<<"Hi this is NonStatic "<<name;
//     }
//     static void Static(string name){
//         cout<<"Hi this is Static "<<name;
//     }
// };
// int main(){
//     thread thread_obj(f1);
//     thread_obj.join();   // to join threads to main thread
//     // --
//     c1 x;
//     thread t1(x);
//     thread t2(c2::Static,"Name1");
//     // -- thread using non static 
//     c2 obj1;
//     thread t3(&c2::nonStatic,obj1,"Name2");
//     // -- thread usign lambda
//     auto f1=[](){
//         cout<<"Hello Lambda";
//     };
//     thread t4(f1);
//     t1.join();
//     t2.join();
//     t3.join();
//     t4.join();
//     return 0;
// }
// --------------------- Smart Pointers -----------
// #include <iostream>
// using namespace std;
// class Smart{
//     int* ptr;
//     public:
//     Smart(int* p=NULL){ptr=p;};
//     int& operator*(){
//         return *ptr;
//     }
//     ~Smart(){delete (ptr);}
// };
// int main(){
//     Smart ptr1(new int());
//     *ptr1=90;
//     cout<<*ptr1;
//     return 0;
// }

// ---- auto_ptr
// #include <iostream>
// #include <memory>
// using namespace std;
// class c1{
//     public:
//     int a;
//     c1(int x=0){
//         a=x;
//         cout<<"Hello";
//     }
// };

// int main(){
//     // unique_ptr<c1> ptr1(new c1(7));
//     // cout<<ptr1->a<<endl;
//     // unique_ptr<c1> ptr2;
//     // ptr2=std::move(ptr1);
//     // cout<<ptr2<<endl;
//     // ------ shared smart pointer
//     // shared_ptr<c1> ptr1(new c1(2));
//     // shared_ptr<c1> ptr2;
//     // ptr2=ptr1;
//     // ptr2->a=90;    // change will deflected in both
//     // cout<<ptr1->a<<endl;
//     // cout<<ptr2->a<<endl;
//     // cout<<ptr1.use_count();    // tell how many pointers point to same one
//     // cout<<ptr2.use_count();
//     // -----weak pointers 

//     return 0;
// }

// ------------------------- this pointer ------------
/*   Buffer

    Output buffering methods
    Full Buffered : Flush when 
        1 Buffer Full
        2. Programm terminate normally
        3. Explicit call (using endl or cout.flush())
    Line Buffered : flush
        1. Full Buffer condition + newline appered it flushes the buffer
    Unbuffered 
*/
/* -------------------------  🚨 \n     vs   endl  🚨------------
    1. /n just only add newline but endl add newline + flush the buffer
    2. Normal 'cout'(interactive terminal) statement works as line buffered but if data is going to file/pipe then it changes to full buffered
    3. /n guarantedd flush only in line buffered
    4. As cin default tie with cout so whenever cin used it automatic flush output buffer(interactive terminal)
    5. endl = \n + flush
    Note : In Debugging (in case of threads) must use `endl` may be logs are saving to file then displaying over

*/
// int main() {
//     cout <<"1 Must Appear earlier in every case (Full + Line)"<<endl; 
//     // cout <<"1 Must Appear earlier in every case (Full + Line)"<<flush;  // ✅ work fine but not add line
//     cout<<"2 Must Appear earlier in Line Buffer case \n";
//     cout << "3 Buffer data without newline (must After pause and with next flush)...";
//     this_thread::sleep_for(chrono::seconds(3)); // pause 3 seconds
//     cout << "4 Buffer data with newline (if line buffer all data will flush here)\n";    // line buffered 
//     return 0;
// }
// // for send to any file use ./a.out > file.txt (in this case output accroding to full buffer)
// // also use `./a.out >file.txt tail -f file.txt` for proper log of that file



//cin untied with cout still cin flush the buffer but incase of interactive terminal(not with pipe | file)
//                               🔴 Important 🔴
// int main() {
//     // cin.tie(nullptr);
//     cout << "Hello"; // no newline, no flush
//     string a;
//     cin>>a;   // if cin flushes then Hello must appear before thread pause else after 
//     this_thread::sleep_for(chrono::seconds(3));   // to see effect because it takes input from file (so fast)
//     cout << " World " <<a<< endl;
// }

// Hello with print earlier  if print directly in terminal but if take input from file then cin will not flush after untie






/* ------------------------  🚨 working of cin 🚨------------
    1. Takes input from I/O untill  enter/newline
    2. cin will parse and take data according  rest will reamins in buffer
    3. If cin used again and buffer is not empty then it will get value from buffer
    4. if buffer is empty and cin used then contro lgoes to OS to I/O operation
    5. for single cin search will go upto whitespace(not leading)

*/
// int main(){
//     int a;
//     cin>>a;   // it will take first valid int (ignore leading spaces) rest will remain in buffer
//     string s;
//     // cin.clear();     // use if error in parsing value for 'a'(because cin>>a appears first) to clear state of cin for further input
//     cin>>s;
//     cout<<a<<" "<<s;
// }


/*
Imp testcase 
983Yogesh
983Y ogesh
    983Yog esh
902340984509235034Yog   --> with + without clear
Yog

*/


// with loops
// int main(){
//     vector<int> nums(5);
//     for(int i=0;i<5;i++){
//         cin>>nums[i];
//     }
// }
/*
input :- 
1 2 3 4 5
then all 1 2 3 4 5 goes to istream buffer
1st iteration cin 1 will goes rest remain in buffer
in 2nd  2 will go
ans so on....
input :- 
1 2 3
after 3 iteration buffer is empty so I/O operation performed by OS
4 5 (again input)
all iteratio complete in this way
*/
// -------------------- Ignore method
// int main(){
//     int a,b;
//     cin>>a;
//     // cin.clear();  // just clear flag status
//     cin.ignore();  // ignore that space
//     cin.ignore();  // ignore next int 
//     // only ignore 1 character in input stream including space
//     cin>>b;
//     cout<<a<<" "<<b;
//     return 0;
// }
