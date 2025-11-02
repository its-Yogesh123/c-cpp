#include <stdio.h>    // header file library, stdio --> standard input output
// this header means we work on input (scanf)and output function (printf)   
//int main(){
//int a=5;
//printf("%i \n",a);   // -- format specfiers

// \n is newline character

//--- float precision
//float x=5.98798696;
//printf("%.2f \n",x);  // automatic precise value upto 2nd place (.2f)
//---
//int x=5/2;   // implicit conversion (2.5 ko 2 me apne app)
//printf("%i \n",x);  // output will 2 not 2.5 because dataype is  Int as we specify      ---- here d_type conversion comes into play
//
//float y=5/2; // here we store this division in float but ...
//printf("%f \n",y);  // here also ans. 2 not 2.5 because 5 and 2 are still int d_type

//float z=5.0/2.0;
//float z=(float)5/2;  //  --explicit conversion                                                          ++++(imp)
//printf("%f",z);  // 2.5 here


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Data_types^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//short int a; 
////unsigned short int b; // or
//short int b=55U;
//printf("%hu",b);
//int c;
//unsigned int d;
////long int e; // or
//int e=9875L;  //  means long int
//unsigned long int f;
//long long int g;
//unsigned long long int h;
//signed char i;
//unsigned char j;
//float k;
//double l;
//long double m;
//--------------------- ASCII Value and character
//char x='a';   // here a is converted into -> 97 and stores
//char y=97;    // 97 is ascii key of a
//printf("%c",x);
//printf("%d",x==y); // 1 in results 
//********************** const 
//#define Value 55    // way to declare constant 
//printf("%d",Value);


//const int x2=5;
////x2=5;           // error will come beacuse value cannot change
//printf("%i \n",x2);

//--
//--

//int a=1,b=2,c=3;
//printf("%i%i%i",a,b,c);   // multiple value assign



//***********************************************    print string and a sentence
//char ch;  // simple a charater
//scanf("%c",&ch); //  takes input a character
//char s[10];  // it takes a string of max_length 10 untill space comes (only word)
//scanf("%s",&s);
// ------            for sentence
//char sen[100]; 
//scanf("%[^\n]%*c",&sen);  // []  scanet characters , ^\n tells take input untill a new line not encountered , 
//printf("%s",sen);

//-----while loop
//int i=1;
//while(i<=10){
//	printf("%d \n ",i);
//	i++;
//int i;
//for(int i=0; i<=20;i++){  // we can't define here but can be in c99 comopiler
//for(i=0;i<=20;i++){     // no error
//	printf("Yogesh");
//}  
//return 0;
//}

//int main(){
// ################  Operators #######################
// and > or  prior
/*how && and || works ---> at first first_statem. check then proceed 
for && if first_stat. 0(wrong) then not execute/run second statement and direct the result 0
for || if first_stat. 1(right) then not execute/run second statement and direct the result 1
*/
//int x=-1,y=-1,z=-1;
//int a=++x&&++y||++z;   // here y will remain -1 as and direct toward results not 2nd state.
//printf("%d %d %d %d",x,y,z,a);
//int z=5&&9832478998;   // and or only return boolean value
//printf("%d",z);

//------- bitwise operator (low level programming operator)
// may vary output from system to system
// perform calculation on each bit
//printf("%d",6&4);   
//printf("%d",6|4);
// XOR (exclusive or)
//int a=5;
//char b='@';
// ^ on integer
//int b='@'; // same as above
//int x=a^b;
//printf("%d \n",x);   // encrypted / value change
//printf("%d",x^b); // decrypted / initial value
//---

//unsigned char ch='A';
//unsigned char ch2='@';
//printf("%c",ch^ch2);  // encrypted
//---------------
//----
//                     left shift operator






//return 0;
//}

//************************************* if else *****************************************
//int a=3;
//if (a!=2){
//	printf("Hello");
//}
//else if(a!=3){
//	printf("Hello You Wrong");
//}
//else{
//	printf("hi");
//}
//------------------------ ternary operator

//int a2= 2==3?printf("Yes right"):printf("Not Block");    // single line conditional statements
//
//


//int main(){
//------------------------------------ switch case statements ----------------------
//int x=12;
//switch(x){
//	case 12:{
//		printf("12");
//		break;
//	}
//	case 10:{
//		printf("HI");
//		printf("Yogesh");
//		break;
//	}
//	default:{
//		printf("Yogesh");
//		break;
//	}
//}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Arrays <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 
//int main(){
//int array1[]={1,2,3,4};   // simple array which contain 4 element   like in js 

// Declaration
//int array1[];
//char array2[12]; // max_length specified

// Initialisation :-  Assigning values to array
//int array1[]={1,2,3,4};
//array1[5]=5; // initialisation after declaration
//
//printf("Element at array1[2] is %d \n",array1[2]);
//array1[5]=10;
//printf("%d",array1[5]);    // array are mutable ??????

// Array Traversal :- The process to visit every element os an array
//1-D Array :-  // normal one dimensional array
// 2-d Array :- 
//int arr1[row_size][col_size]  
//int arr1[2][3]={1,2,3,4,5,6};  //  2-d array
//printf("%d",a[i][j]);  //i=row and j=clm index

//---- practice
//int a[4][4]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//int i,j;
//printf("2-D Array :_  \n");
//for(i=0;i<4;i++){
//	for(j=0;j<4;j++){
//		printf("%d",a[i][j]);
//	}
//	printf("\n");
//}
//*********************************************** string *******
// we can create string by 2 method ist -- normal array  and 2nd via Pointer(read-only)
//char str1[]="Hello";   // string is array/collection of character
//char str2[]={'H','e','l','l','o','\0'};   // \0 is null used to tell the end of string  (Compulsory)
//char *str_p="Yogesh Kumar";  // string using pointer
//// in first statement null is added by c itself proof :-
//printf("%d %d",sizeof(str1),sizeof(str2));  // 6,6 -- both same

//------- string function 
//in this we use  header file
// indexing and slicing like in python
// string iterable
//int i;
//for(i=0;i<=4;i++){
//	printf("%c \n",(str1[i])); // char because string is combination of char 
//}
//---------------------- printing special characters " ' /
//char spc[]="Hello this is \" Yogesh Kumar \"";  //  \" means " like as in python
//****************** 

//----------------------------- string function
//#include <string.h>  // it give some extra function
//char str[]="abcdefghijklmnopqrstuvwxyz";
//char str2[100]="abcdefghijklmnopqrstuvwxyz";
//printf("%d",strlen(str));   //26  function to get length 
//printf("%d \n",sizeof(str));  // 27 here \0 also count
//printf("%d",strlen(str2));  // 26 (in bytes) give actual size occupied
//printf("%d",sizeof(str2));   //100  give total memory allocation not actual


//----- concatination of 2 string        
//char s1[]="Hello";
//char s2[]="Friends";
//printf("%s",s1+s2);   // not work
//strcat(s1,s2);        // here s2 will add in s1
//char s3[]=s2;         // cannot assign like this
//char s3[20];          // size must specify
//strcpy(s3,s1);
//printf("%s",s3);      // HelloFriends -- output

//---- comparision b/w two string
//char s1[]="Hi";
//char s2[]="Hi";
//char s3[]="Hello";
///* We cannot compare two string diretly like as in python*/
//printf("%d",strcmp(s1,s2));    // 0 if equal
//printf("%d",strcmp(s1,s3));    // -1 if not equal
//--------------- Swaping of two string  
// 1 swap pointer   2nd swap data

//this will not work
//void swap(char* str1,char* str2){
//	char *temp=str1;
//	str1=str2;
//	str2=temp;	
//}
//int main(){
//char str1[]="Yogesh";
//char str2[]="kumar";
//swap(str1,str2);
//printf("%s\n",str1);     // this will not work only work inside only that function block
//printf("%s",str2);
//}   
//--- this will work
//#include <stdlib.h>
//#include <string.h>
//void swap(char **ptr1,char **ptr2){
//	char *temp=(char*)malloc(strlen(*ptr1)+1*sizeof(char));
//	temp=*ptr1;
//	*ptr1=*ptr2;
//	*ptr2=temp;
//	
//}
//int main(){
//char* str1_ptr="Yogesh";   // now it is pointer and can be change
//char* str2_ptr="kumar";
//printf("String 1- %s and %s \n",str1_ptr,str2_ptr);
//swap(&str1_ptr,&str2_ptr);
//printf("String 1 -%s and %s",str1_ptr,str2_ptr);
//}















//********************************************** User input as string*******************************
char inp[20];   // must specify size
//printf("Enter Your Name :- ");
//scanf("%s",inp); // no need for refrence operator(&) 
/*But it takes input untill size completed or space comes (after that no input)
There are two Ways
1). Using Built-in Function (fgets and puts)
syntax :- fgets(str_name,str_size,stdin);
2). Scanset Characters

*/
//fgets(inp,20,stdin);    // ist  way
//printf("Hello %s",inp);
//scanf("%[^\n]s",inp);  // take unput untill new line comes
//printf("Hello %s",inp);


//******************************************** Memory and pointers
//int x=43;
//printf("%p",&x);   // printing  memory address
//return 0;
//---    creating pointers
//int age=420;
//int* ptr=&age;
//printf("%p \n",ptr);
//printf("%d",* ptr); // * is derefrence opearator for get value
//return 0;
//}

//------------------------ arrays with pointers
//int arr[5]={11,12,13,14,15};
//int* ptr=&arr[0];
//// getting elements using pointer
//int i;
//for(i=0;i<5;i++){
//	printf("%d \n",*ptr++);
//}
// ******************** length of array
//printf("%d | %d",sizeof(arr),sizeof(arr[0])); // as it stores int which is of 4 bytes
//----- pointer arthemetics                                                                 (imporant)
//printf("%d",*(&arr+1)-arr);
//-----------------------------------------
//----------------------------------------
//*************** ****************** Multidimensional Array ***********
//int arr[][]={{1,2},{3,4}};  // show error
//int arr[][2]={1,2,3,4,5,6,7,8,9,10};  // Ist method
//int arr[][2]={{1,2},{3,4},{5,6},{7,8},{9,10}}; // 2nd way to initialise array.
///*  store as
//12
//34
//*/
//int i,j;
//for(i=0;i<5;i++){
//	for(j=0;j<2;j++){
//		printf(" %d",arr[i][j]);
//	}
//	printf("\n");
//}
//----- 3-d Array
//int arr3[2][3][2]={1,2,3,4,5,6,7,8,9,10,11,12};  // 1st way
//int arr3[2][3][2]={{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}};  // best way
//int i,j,k;
//for(i=0;i<2;i++){
//	for(j=0;j<3;j++){
//		for(k=0;k<2;k++){
//			printf(" %d",arr3[i][j][k]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

//=================================== jagged array           =========================


//*************************** Dynamic memory allocation in 1-d array **********************
// malloc clloc free reallocfunction
#include <stdlib.h>  // for dynamic memory allocation
//----------------------------------------------- in 2-D Array -------------------------------------
// 1st type using 1-d 
//int main(){
//	int r=3,c=5;
//	int *ptr=(int*)malloc((r*c)*sizeof(int));
//	int i,j;
//	for(i=0;i<r*c;i++){
//		ptr[i]=i+1;
//	}
//	for(i=0;i<r;i++){
//		for(j=0;j<c;j++){
//			printf(" %d",ptr[i*c+j]);
//		}printf("\n");
//	}
//return 0;
//}
//---------------------------------- using array of pointer
//#include <stdlib.h>
//int main(){
//int r=3,c=4,i,j,x=0;
//int* arr[r];      // an array of pointers of integer
//for(i=0;i<r;i++){
////	arr[i]=(int*)malloc(c*sizeof(int));  // creating size for row
//	*(arr+i)=(int*)malloc(c*sizeof(int));   // pointer arthematics to row
//}
//for(i=0;i<r;i++){
//	for(j=0;j<c;j++){
//		arr[i][j]=++x;
////		*(*(arr+i)+j)=++x;                                   (imp line)
////		*(arr[i]+j)=++x;
//	}
//}
//for(i=0;i<r;i++){
//	for(j=0;j<c;j++){
//		printf("%d ",arr[i][j]);
//	}
//}
//return 0;
//}


//--------------------------- 3rd  like 2nd but array bhi ab pointer    ( pointer to pointer )
//#include <stdlib.h>
//int main(){
//	int r=3,c=4,i,j;
//	int** arr=(int**)malloc(r*sizeof(int*));
//	for(i=0;i<r;i++){
//		arr[i]=(int*)malloc(c*sizeof(int));
//	}
//	for(i=0;i<r;i++){
//		for(j=0;j<c;j++){
//			arr[i][j]=i*c+j+1;
//		}
//	}
//	for(i=0;i<r;i++){
//		for(j=0;j<c;j++){
//			printf("%d ",arr[i][j]);
//		}
//	}
//} 

//================= 4th method double pointer and single malloc function
//#include <stdlib.h>
//int main(){
//int r=3,c=5,i,j,x=0;
//int len=sizeof(int*) * r + sizeof(int)*r*c;
//int** arr=(int**)malloc(len);
//int *ptr;
////ptr=(int*)(arr+r);
//ptr=(*arr+r);   // pointer arthematics
//for(i=0;i<r;i++){
//	arr[i]=ptr+i*c;
//}
//for(i=0;i<r;i++){
//	for(j=0;j<c;j++){
//		arr[i][j]=++x;
//	}
//}
//for(i=0;i<r;i++){
//	for(j=0;j<c;j++){
//		printf("%d ",arr[i][j]);
//	}printf("\n");
//}
//return 0;
//}

//====================== M-5 Pointer to VLA        (pending)
// ===================== M-6                       (pending)


//---- 
//return 0;
//}





















//return 0;	
//}

//---------------------------- arrays with functions
//void size(int arr[]){    // here parameter will be pointer only we can use -
////void size(int *arr){   
//	int s=sizeof(arr)/sizeof(arr[0]);  output -1 
/*According to the processor, size of pointer changes for  32 bit computer 
it assigns 4 bytes to pointer then output becomes 1.*/


////	printf("Size of Array inside size is :- %d ",s);  // not an array but its pointer so not use sizeof
//}
//int main(){
//	int arr1[]={1,2,3,4,5,6,7,8};
//	int s=sizeof(arr1)/sizeof(arr1[0]);
//	printf("Size of Array inside main is :- %d \n",s);
//	size(arr1);
//	
//	return 0;
//}
 
// length of array must be passed as parameter
//void print(int arr[],int n){ 
//	int i;
//	for(i=0;i<n;i++){
//		printf("%d",arr[i]);
////		printf("%d",*arr++);
//	}
//}
//int main(){
//	int arr[]={1,2,3,4,5,6};
//	print(arr,6);
//}


// string and character as parameter 
//void print(char arr[]){
////void print(char *arr){
////	printf("%s",arr);  // no error
////	printf("%s",*arr); // error
////	p rintf("%c",arr[0]);   // no error
//	printf("%c",*arr);     // no error
//}
//int main(){
////	char arr[]={'a','b','c','d'};  // will work normal like above with int array
//	char str[]="Hello this is Yogesh Kumar";
//	print(str);
//	return 0;
//}
//
//
//------------------ 2-d array with function
#include <stdio.h>
//const int a=3;
//const int b=3;
//void print(int arr[3][3]){
//	int i,j;
//	for(i=0;i<a;i++){
//		for(j=0;j<b;j++){
//			printf("%d",arr[i][j]);
//		}printf("\n");
//	}
//}
//void print(int arr[][a],int m){
//	int i,j;
//	for(i=0;i<a;i++){
//	for(j=0;j<m;j++){
//		printf("%d",arr[i][j]);
//	}printf("\n");
//	}
//}
//int main(){
////	int arr[][3]={{1,2,3},{1,1,1},{6,7,8}};
//	int arr[][3]={{1,2,3},{1,1,1},{6,7,8},{3,3,3}};
////	print(arr);
//	print(arr,4);
//	return 0;
//}
//3rd Method   if compiler is C99
//void print(int n,int m,int arr[n][m]){
//	int i,j;
//	for(i=0;i<n;i++){
//		for(j=0;j<m;j++){
//			printf("%d",arr[i][j]);
//		}printf("\n");
//	}
//}
//int main(){
//	int arr[][4]={{1,1,1,1},{2,2,2,2},{3,4,5,6},{8,7,6,7}};
//	print(4,4,arr);
//	return 0;
//}


//using pointer 
//int main(){
//	arr={{1,2},{3,5},{7,8}};
//	print
//}

/*                                   Notes 
1. Array can of any type except void and function
2). String made with 2nd type (pointer method) will save in read-only memory
     i) if string is allocated in head (dynamically) then we can change 
*/
