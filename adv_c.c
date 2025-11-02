//#include <stdio.h>
//=============================================== function =====================
// declaration
// user define & tailor made

// 1).  Argument via value
//void swap(int a,int b){     // values are only copies from original
//	int temp;
//	a=temp;
//	a=b;
//	b=temp;
//}
//int main(){
//	int var1=0,var2=1;
//	printf("Before Swap fun values :- %d & %d\n",var1,var2);
//	swap(var1,var2);                                         // values will change only inside the swap function only
//	printf("Before Swap fun values :- %d & %d",var1,var2);
//	return 0;
//}
// 1).  Argument via refrence
//void swap(int *a,int *b){     // these parameters are the actual variable of main funcion -- value can change
//	int temp;
//	temp=*a;
//	*a=*b;
//	*b=temp;
//}
//int main(){
//	int var1=0,var2=1;
//	printf("Before Swap fun values :- %d & %d\n",var1,var2);
//	swap(&var1,&var2);                                         // values will change only inside the swap function only
//	printf("Before Swap fun values :- %d & %d",var1,var2);
//	return 0;
//}

//function_prototype
//int hello(int a, char b,int c);
//int hello(int,char,int);
//--
//----------------- 
//fun(int x){    // implicit  tells that return is int   valid in c99
//	return 2*x;
//}

//=======================   callbacks                      --------------pending


//-------------- nested function    
// int main(){
// 	int f1(){
// 		printf("this is F1");
// 		 int f2(){
// 			printf("This is F2");
// 		}
// 	}
// 	f1();   // no error (only in GCC GNU compiler)
// 	printf("sashdf");
// 	f2();   // not accessable
// 	return 0;
// }


//-- auto keyword
//int main(){
//	auto int f1();
//	f1();
//	int f1(){
//		printf("Hello f1");
//	}
//	return 0;
//}



//-------------------------------------------- variadic function ------------------------------------
//int fun1(int x,...)    // syntax of variadic function
// to access the argument passed we have to use an header file --
//#include <stdarg.h>
//int sum(int n,...){
//	int sum=0;
//	va_list ptr;  //  delare pointer to arg. list
//	va_start(ptr,n);  //   Initializing argument to the list pointer
//	int i;
//	for(i=0;i<n;i++){
//		sum+=va_arg(ptr,int);
//	}
//	va_end(ptr);   //  ending 
//	return sum;
//}
//int main(){
//	printf("Sum of 1,2,3,4,5 is %d",sum(5,1,2,3,4,5));
//}
//-----------------------  _Noreturn keyword
//The _Noreturn keyword was introduced in C11.
// It tells the compiler that the function it's applied to doesn't return to the caller. 
//_Noreturn void f1(){
//	printf("Readched to Function");
//}
//int main(){
//	printf("Going to A Function");
//	f1();
//	printf("Come back to main");
//	return 0;
//} 

//====================================== predefined Identifiers
// __func__ , __FILE__ , __LINE__ 
//int hello(){
//	printf("%s",__func__);
//}
//int main(){
//	printf("%s \n",__func__);    // tell the function name
//	printf("%s \n",__FILE__);    // tells the CWD
//	printf("%d",__LINE__);    // tells the line including commented line
////	hello();  
//	return 0;
//}
//---------------------------------------------- Pointers -------------------------------------
//            1). Integer Pointer
//int main(){
//	int x=6;
//	int* ptr;   // int pointer
//	ptr=&x;
//	return 0;
//}
//            2). Array Pointer
//int main(){
//	int x[]={1,2,3};
//	int* ptr1=x;     
//	// here &x will represent the whole address of block of array
//	int* ptr2=&x[0];
//	printf("%d \n",ptr);
//	printf("%d \n",ptr1);
//	printf("%d \n",ptr2);
////	printf("%d",ptr);
////	printf("%d",ptr);
//}


//            3). Function Pointer
//int fun(int n){
//	printf("%d",2*n);
//}
//int main(){
//	int (*fun_ptr)(int)=&fun;   // if not use brackets around then it will a funciton returning a pointer
////	int (*fun_ptr)(int);
////	fun_ptr=&fun;
//
//	// to run funtion from pointer
//	(*fun_ptr)(10);   // 20 will output
//}
//------------- 2nd method
//void fun1(int a){printf("Hello World");};
//int main(){
//	void (* fun_ptr)(int)=fun1;  // & removed
//	fun_ptr(10);   // not (*fun_ptr)(10) 
//	
//}


//--------------------------------------- array of function pointer
//int sum(int a,int b){
//	printf("%d\n",a+b);
//}
//int sub(int a,int b){
//	printf("%d\n",a-b);
//}
//int mul(int a,int b){
//	printf("%d\n",a*b);
//}
//int main(){
//	int(*fun_array_ptr[])(int,int)={&sum,&sub,&mul};  
//	(*fun_array_ptr[0])(7,8);   // how to call
//	(*fun_array_ptr[1])(7,8);   // sub will call
//	(*fun_array_ptr[2])(7,8);   // mul will call
//}


//------------------ function pointer as an argument------------------
//#include <stdio.h>
//int fun1(){printf("fun1 \n");};
//int fun2(){printf("fun2 \n");};
//void wrapper(int(*fun)()){
////	(*fun)();
//	fun();  // also can use directly
//}
//int main(){
//	int (*fun1_ptr)()=&fun1;
//	int (*fun2_ptr)()=&fun2;
//	wrapper(fun1_ptr);
//	wrapper(fun2_ptr);
//	return 0;
//}
//-----------------
//------------------ const and pointer
//************ 1). Constant Pointer (like constant variable)   
//int main(){
//	int x=9;
//	int y=100;
//	printf("%d\n",x);
//	int* const ptr=&x;
////	int* const ptr=&y;   // address cannot change but 
//	*ptr=200;            // value can change
//	printf("%d",x);
//	return 0;
//}

//************ 2).Pointer to  Constant variable
//int main(){
//	int x=9;
//	int y=100;
//	printf("%d\n",x);
//	const int* ptr=&x;
//	ptr=&y;   // address can change but 
////	*ptr=200;            // value cannot change
//	printf("%d",*ptr);
//	return 0;
//}
//************ 3).Constant Pointer to  Constant variable  (nothong can change)

//.... many other pointers                                       (pending)

//            4). Double Pointer (pointers of pointers)
//int main(){
//	int** ptr;   // {int*,int*,int*,...}
//	// *ptr
//}

//            5). Null Pointer 
//int main(){
//	int* ptr=NULL;   // used when currently a pointer not in use
//}

//---------------------------------------- structure / struct
#include <stdio.h>
//struct students{      // only declaration no memory allocation
//	int u_name;    // member 1
//	int age;       // member 2
//	char sex;
//}boy,girl;         // here variable boy and girl are created so memory allocated
//
//int main(){
////	struct students var1,var2,...;
//	struct students other;  // by this variable also created
//// now struct students has 3 variable - boy, girl and other
////------- how to assign values
////m-1
//	struct student boy={}
//	return 0;
//}


//--------------- Assign values
//struct students{
//	char* u_name;
//	int age;
//	char sex;
//};
//int main(){
//	struct students boy={"Yogesh Kumar",29,'M'};   // using Initializer list
//	struct students girl={.u_name="hello",.age=30,.sex='F'};   // using Designated Initializer List
//	struct students other;    // using dot operator
//	other.u_name="ih";
//	other.age=20;
//	other.sex='X';
//	printf("%s %d %c\n",boy.u_name,boy.age,boy.sex);   // access the value via dot operator
//	printf("%s %d %c\n",girl.u_name,girl.age,girl.sex);
//	printf("%s %d %c\n",other.u_name,other.age,other.sex);
//	return 0;
//}


//**************** typedef *********    for giving nickname
//struct students{
//	int age;
//	char u_name[20];
//};
//typedef struct students std;   // struct student ---> std
//// 2nd 
//typedef struct company{
//	int hour;
//	int salary;
//}c;                   // c is nick-name
//int main(){
//	std boy={23,"Hello"};   // 
//	c hr={20,200000};
//	printf("%s %d \n",boy.u_name,boy.age);
//	printf("%d %d \n",hr.hour,hr.salary);
//	return 0;
//}



//------------- nested structure -------------
//-------------- 1st method Embedded Nested  Structure

//------------------2nd method Separate Nested Structure
//struct child{   // it should declare before parent structure
//	int x;    // child member
//	char y;  
//};
//
//struct parent{
//	int a;
//	struct child b;
//};
//int main(){
//	struct parent var1={1,2,'y'};
//	printf("%d %d %c",var1.a,var1.b.x,var1.b.y);
//	return 0;
//	};



//========================= structure pointers =================
//struct students{
//	char u_name[20];
//	int age;
//};
//int main(){
//	struct students boy={"Yogesh",23};   
//	struct students* ptr=&boy;  // kuch bhi krna hai to struct struct_name jaroor aaega
//	// how to access
//	printf("%d\n",ptr->age);  //ptr -> member_name
//	printf("%d",(*ptr).age);  //*ptr.member_name
//	return 0;
//}


//------------- self refrenced structure                                ---- pending
//struct student{
//	char name[30];
//	int age;
//};
//int main(){
//	return 0;
//}



//-------------------------- padding and packing
//struct s1{    // due to padding  create some empty 
//	char a;
//	short int b;
//	int c;
//};
//int main(){
//	printf("%d",sizeof(struct s1));   // 8 is output but  1(char)+1 (padding)  +2(short)+4(int)= 8 bytes
//}


//--- size of structure will be multiple of longest data_type
//struct s1{
//	char a;
//	double c;
//	int b;
//};
//int main(){
//	printf("%d",sizeof(struct s1));   // 24  1 (char) +7 (paddding -- rule1) + 8 (double) + 4 (int) + 4(padding -- rule2)=24
//}


//---- to remove padding
//1).  use #pragma pack(1)    remave padding from all structures
//2). use __attribute__((packed));  // for one struc
//#pragma pack(1)
//struct s1{
//	char a;
//	double c;
//	int b;
//};
//struct s2{
//	char a;
//	double c;
//	int b;
//}__attribute__((packed));
//int main(){
//	printf("%d \n",sizeof(struct s1)); 
//	printf("%d",sizeof(struct s2)); 
//}
//************************************ flexible array member in structure **********************            (pending)



//******************************************* Union ********************************
//union hello{
//	int a;
//	char b;
//	char c;
//}var1,var2;   // declaration like structures
//// all syntax same as structures
//
////size of Union == size of largest data_type memeber
//int main(){
//	printf("%d",sizeof(var1));  // 4 will output
//}

//---------------we can store data only in one variable at same time
//union a{
//	int a;
//	int b;
//	char c;
//}var1;
//int main(){
//	var1.a=10;
//	var1.b=13;  // var1.a and .b both updated to 13
//	var1.c='a';   // var.a , .b and .c all updated to ASCII value of 'a' = 97
//	printf("%d %d %d",var1.a,var1.b,var1.c);  
//	return 0;
//}
//----------- bit fields
//struct st1{ 
//	int age:8;   // specify max length in bits
////	int id:40;    // error 4*8 =32 but we specify 40  
//};

// if we make strucutre to save date 
//struct date{
//	int d;  
//	int m;
//	int y;
//};
//struct date1{
//	unsigned int d:5;    // 5 bytes max,
//	unsigned int m:4;   //4 bytes maximum
//	unsigned int y;
//};
 // size of date1 < date 


//
//
//


//------------------- storage classes --------------------

// 1). auto class
//int hello(){
//	auto int a=5;
//	a+=1;
//	printf("%d\n",a);
//}
//int main(){
//	auto int x;    // only for local variable
//	hello();   // 6 output
//	hello();   //  same
//	hello();   //  same
//	hello();   //  same output because every time when function close auto a removed from memory.
//	return 0;
//}
//static int y;   // can be declare globally
//int hello(){
//	static int a=5;
//	a+=1;
//	printf("%d\n",a);
//}
//
//int main(){
//	static int x;    // only for local variable
//	hello();   // 6 output
//	hello();   // 7
//	hello();   // 8
//	hello();   // 9  because every time when function close but 'a' remain in memory.
//	return 0;   // here a will free 
//}



//------  extern   form external file
//void hello(){
//	extern int a;    // local declaration we cannot use a in main function 
//	printf("%d \n",a);
//}
//extern int a;  // global declaration now we can use a anywhere in this file
//int main(){
////	printf("%d \n",a); 
//	return 0;
//}

//---- register only for local
// CPU only execute the program which is in register
//int main(){
//	register int a;  // store garbage value
//	int b;
//	printf("%p\n",&b);
////	printf("%p",&a);   // error because a not in memory 
//	return 0;
//}





//******************************************* Files ****************************************************
//#include <stdio.h>
//int main(){
////	FILE *file1;    // creating pointer for file ???
////	file1=fopen("n1.txt","w");    // it will create a file if not exits
////	fclose(file1);
////	---------------------------------writing in file
//
////	file1=fopen("n1.txt","w");
////	fprintf(file1,"Hello Welcome of WINDOWS 100  @@@@");    
////  --------------------------------appending file
////	file1=fopen("n1.txt","a");
////	fprintf(file1,"\n hi this is Yogesh");   / escape sequence valid
////	fclose(file1);
//
////to read files
//	FILE *file2;
//	file2=fopen("n1.txt","r");
//	char read[50];
////	fgets(read,50,file2);  // to get data from file pointer but it take only single line
//	printf("%s",read);
//	// to print multiple line we use loop
////	printf("%s",fgets(read,50,file2));
//	while(fgets(read,50,file2)){
////		printf("%d",fgets(read,50,file2));     // ??????????????///
////		printf("%s",read);
//	}
//	
//	fclose(file2);
//	return 0; 
//}




////================================Preprocessors ========================


/*
    1. Macros
    2. File inclusion
        <> for search in standard directory
        "" for src file directory
    3. Conditional Compilation
    1. Other (like #pragma)

*/
//#include <stdio.h>   // preprocessor directives to include standard header file
//#define max 5       // Macros
//#define square(a) a*a

//---- file inclusion
// #include "file_name"    // include normal file
//int main(){
//	printf("%d \n",max);
//	int i;
//	for(i=0;i<max;i++){
//		printf("%d ",square(i));  // using MACROS
//	}
//	return 0;
//}

//--------- conditional compilation directives
//#include <stdio.h>
//#define num 5
//#ifdef num
//int main(){
//	printf("Yes Num is Defined");
//	return 0;
//}
//#endif
////--
//#ifndef num
//int main(){
//	printf("No Num is Defined");
//	return 0;
//}
//  ---- Hence We can use multiple main function
//#endif

//-------- if else with expression
// by this below method we can use multiple main function
//#define value 1
//#if value>0
//int main(){
//	printf("I'm If block main function'");
//	return 0;
//}
//#elif value<0
//int main(){
//	printf("I'm ElIf block main function'");
//	return 0;
//}
//#else
//int main(){
//	printf("I'm Else block main function'");
//	return 0;
//}
//#endif

//------------------------ Other directives
// #include <stdio.h>
// #define  num 10
// #undef num  // it willl destry the MACROS

//-- pragma directives
//-- in GCC this not worked
//void fun1();
//void fun2();
//#pragma startup fun1
//#pragma exit fun1
//void fun1(){
//	printf("Function 1 Called");
//}
//void fun2(){
//	printf("Function 2 Called");
//}
//int main(){
//	void fun1();
//	void fun2();
//	printf("Main function Executed");
//	return 0;
//}

 // alternative for GCC compiler
// #include <stdio.h>
// void fun1();
// void fun2();
// void __attribute__((constructur)) fun1();
// void __attribute__((destructur)) fun2();
//void fun1(){
//	printf("Function 1 Called");
//}
//void fun2(){
//	printf("Function 2 Called");
//}
// int main(){
// 	printf("Main Function Executed");
// 	return 0;
// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Lambda Function <<<<<<<<<<<<<<<
// [](){
//     cout<<"Lambda function expression "
// }();
// ---------- with return type and params
// int x=[](int a,int b){
//     return a+b;
// }(2,3);




