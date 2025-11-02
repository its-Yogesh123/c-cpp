//// problem to get max output among all bitwise operator
//// where operand are  1<a<n and  a<b<=n
//
//
////#include <stdio.h>
//////Complete the following function.
////
////void calculate_the_maximum(int n, int k) {
////  //Write your code here.
////  int i,j;
////  int a=0,b=0,c=0;
////  for(i=1;i<n;i++){
////      for(j=i+1;j<=n;j++){
////          a=(i&j)>a &&(i&j)<k?i&j:a;
////          
////      }
////      for(j=i+1;j<=n;j++){
////          b=(i|j)>b &&(i|j)<k?i|j:b;
////      }
////      for(j=i+1;j<=n;j++){
////          c=(i^j)>c &&(i^j)<k?i^j:c;
////      }
////  }
////  printf("%d \n",a);
////  printf("%d \n",b);
////  printf("%d \n",c);
////}
////
////int main() {
////    int n, k;
////  
////    scanf("%d %d", &n, &k);
////    calculate_the_maximum(n, k);
//// 
////    return 0;
////}
//#include <stdio.h>
//
//int main() 
//{
//
//    int n;
//    int i,j,x;
//    scanf("%d", &n);
//  	// Complete the code to print the pattern.
//    if(n>=1 && n<=1000){
//    	for(i=0;i<n;i++){
//    		for(j=0;j<n;j++){ 
//    			if(j<=i){printf("%d",n-j);}
//    			else{
//    				printf("%d",n-i);
//				}
//			}
//			x=n-i;
//			for(j=1;j<n;j++){
//				if(j>=n-i){
//					x++;
//					printf("%d",x);
//				}
//				else{
//					printf("%d",n-i);
//				}
//			}
//		printf("\n");
//		}
//		// second half portion
//    	for(i=0;i<n-1;i++){
//    		for(j=1;j<=n;j++){
//    			if(j>=n-i){
//    				printf("%d",i+2);
//				}
//    			else{
//    				printf("%d",n-j+1);
//				}
//			}
//			for(j=0;j<n-1;j++){
//    			if(j<=i){
//    				printf("%d",i+2);
//				}
//    			else{
//    				printf("%d",j+2);
//				}
//			}
//		printf("\n");
//		}
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include <stdio.h>
//int find_nth_term(int n, int a, int b, int c) {
//  //Write your code here.
//  int x;
//  if(n>3){
//  	n--;
//  	x=a+b+c;
//    a=b;
//    b=c;
//    c=x;
//    find_nth_term(n,a,b,c);
//}
//else
//return c;
//}
////
//int main() {
//    int n, a, b, c;
//    scanf("%d\n%d %d %d",&n,&a,&b,&c);
//    int ans = find_nth_term(n, a, b, c);
//    printf("%d", ans); 
//    return 0;
//}
//
//#include<stdio.h>
//void main(){
//	short x=32770;
//	printf("%hd",x);
//}
// ------------------------------------------------- practice
//#include <stdio.h>
//int main(){
//	int arry[]={1,2,3,4};
////	arry[5]=5;
//	int i;
//	printf("%d \n",(arry));
//	for(i=0;i<sizeof(arry);i++){
//		printf("%d",arry[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main(){
//FILE *file1;
//file1=fopen("x1.txt","r");
//char stg[100];
//fgets(stg,100,file1);
//printf("%s",stg);
//fclose(file1);
//}


//----- reverse an array
//#include <stdio.h>
//#include <stdlib.h>
//int main() {
//
//    /* Enter your code here.n Read input from STDIN. Print output to STDOUT */ 
//    int n,i,sum=0;
//    scanf("%d",&n);
//    int *arr=(int*)malloc(n*sizeof(int));
//    do{
//        scanf("%d",arr++);
//    }while(getchar() != '\n');
//    for(i=0;i<n;i++){
//        sum+= *--arr;
//        printf("%d \n",arr);
//    }
//    printf("%d",sum);
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int num, *arr, i;
//    scanf("%d", &num);
//    arr = (int*) malloc(num * sizeof(int));
//    for(i = 0; i < num; i++) {
//        scanf("%d", arr + i);
//    }
//
//
//    /* Write the logic to reverse the array. */
//    int* arr1 = (int*) malloc(num * sizeof(int));
//    for(i = 0; i < num; i++) {
//        *(arr1+i)=*(arr+num-i-1);
//    }
//    for(i = 0; i < num; i++) {
//        *(arr+i)=*(arr1+i);
//    }
//    for(i = 0; i < num; i++)
//        printf("%d ", *(arr + i));
//    return 0;
//}

//#include <stdio.h>
//int main(){
//int arr[20];
//int i=0;
//do{
//	scanf("%d",&arr[i]);
//	i++;
//}while(getchar()!= '\n');
//printf("%d 	%d %d %d %d",arr[0],arr[1],arr[2],arr[3],arr[4]);
//}
//---> 
//#include <stdio.h>
//#include <stdlib.h>
//
///*
// * This stores the total number of books in each shelf.
// */
//int* total_number_of_books;
//
///*
// * This stores the total number of pages in each book of each shelf.
// * The rows represent the shelves and the columns represent the books.
// */
//int** total_number_of_pages;
//
//int main()
//{
//    int total_number_of_shelves;
//    scanf("%d", &total_number_of_shelves);
//    
//    int total_number_of_queries;
//    scanf("%d", &total_number_of_queries);
////    --
//    int i;
//    total_number_of_books=(int*)calloc(total_number_of_shelves,sizeof(int));
//    while (total_number_of_queries--) {
//        int type_of_query;
//        scanf("%d", &type_of_query);
//        if (type_of_query == 1) {
//            /*
//             * Process the query of first type here.
//             */
//            total_number_of_books=(int*)calloc(1,sizeof(int));
//            int x, y,a=0;
//            scanf("%d %d", &x, &y);
//            total_number_of_books[x]+=1;
//            total
//            while(total_number_of_pages[x][a]!=0){
//                a++;
//            }
//            total_number_of_pages[x][a]=y;
//    
//        } else if (type_of_query == 2) {
//            int x, y;
//            scanf("%d %d", &x, &y);
//            printf("%d\n", *(*(total_number_of_pages + x) + y));
//        } else {
//            int x;
//            scanf("%d", &x);
//            printf("%d\n", *(total_number_of_books + x));
//        }
//    }
//
//    if (total_number_of_books) {
//        free(total_number_of_books);
//    }
//    for (i = 0; i < total_number_of_shelves; i++) {
//        if (*(total_number_of_pages + i)) {
//            free(*(total_number_of_pages + i));
//        }
//    }
//    
//    if (total_number_of_pages) {
//        free(total_number_of_pages);
//    }
//    
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int lexicographic_sort(const char* a, const char* b) {
//int i;
//for(i=0;i<strlen(a);i++){
//	int x=a[i],y=b[i];
//    if(a[i]<b[i]){
//        return 0;
//    }
//    else if(a[i]==b[i]){
//        continue;
//    }
//    else{
//        const char* temp=a;
//        a=b;
//        b=temp;
//        return 0;
//    }
//    if(strlen(a)<strlen(b)){
//        return 0;
//    }
//    else{
//        const char* temp;
//        temp=a;
//        a=b;
//        b=temp;
//        return 0;
//    }
//}
//return 0;
//}
//int lexicographic_sort_reverse(const char* a, const char* b) {
//int i;
//for(i=0;i<strlen(a);i++){
//    if(a[i]>b[i]){
//        return 0;
//    }
//    else if(a[i]==b[i]){
//        continue;
//    }
//    else{
//        const char* temp=a;
//        a=b;
//        b=temp;
//        return 0;
//    }
//    if(strlen(a)>strlen(b)){
//        return 0;
//    }
//    else{
//        const char* temp;
//        temp=a;
//        a=b;
//        b=temp;
//        return 0;
//    }
//}
//return 0;
//}
//
//int sort_by_number_of_distinct_characters(const char* a, const char* b) {
//    int x=0,y=0,i,j;
//    for(i=0;i<strlen(a);i++){
//        for(j=i+1;j<strlen(a)-1;j++){
//            if(a[i]!=a[j]){
//                x++;
//            }
//        }
//    }
//    for(i=0;i<strlen(b);i++){
//        for(j=i+1;j<strlen(b)-1;j++){
//            if(b[i]!=b[j]){
//                y++;
//            }
//        }
//    }
//    if(x<y){
//        return 0;
//    }
//    else if(x==y){
//        lexicographic_sort(a,b);
//        return 0;
//    }
//    else{
//        const char* temp;
//        temp=a;
//        a=b;
//        b=temp;
//        return 0;
//    }
//}
//
//int sort_by_length(const char* a, const char* b) {
//    if(strlen(a)<strlen(b)){
//        return 0;
//    }
//    else if(strlen(a)==strlen(b)){
//        lexicographic_sort_reverse(a,b);
//        return 0;
//    }
//    else{
//        const char* temp;
//        temp=a;
//        a=b;
//        b=temp;
//        return 0;
//    }
//}
//
//void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
//    int i,j;
//    for(i=0;i<len;i++){
//        for(j=i+1;j<len;j++){
//            (*cmp_func)(arr[i],arr[j]);
//        }
//    }
//
//}
//
//
//int main() 
//{
//    int n;
//    scanf("%d", &n);
//  
//    char** arr;
//	arr = (char**)malloc(n * sizeof(char*));
//	int i;
//    for( i = 0; i < n; i++){
//        *(arr + i) = malloc(1024 * sizeof(char));
//        scanf("%s", *(arr + i));
//        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
//    }
//  
//    string_sort(arr, n, lexicographic_sort);
//    for(i = 0; i < n; i++)
//        printf("%s\n", arr[i]);
//    printf("\n");
//
//    string_sort(arr, n, lexicographic_sort_reverse);
//    for( i = 0; i < n; i++)
//        printf("%s\n", arr[i]); 
//    printf("\n");
//
//    string_sort(arr, n, sort_by_length);
//    for( i = 0; i < n; i++)
//        printf("%s\n", arr[i]);    
//    printf("\n");
//
//    string_sort(arr, n, sort_by_number_of_distinct_characters);
//    for( i = 0; i < n; i++)
//        printf("%s\n", arr[i]); 
//    printf("\n");
//    return 0;
//}


////===================== hacker rank prb.
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//struct triangle
//{
//	int a;
//	int b;
//	int c;
//};
//
//typedef struct triangle triangle;
//void sort_by_area(triangle* tr, int n) {
//	/**
//	* Sort an array a of the length n
//	*/
//    int i,j;
//    double* ptr=(double*)calloc(n, sizeof(double));
//    for(i=0;i<n;i++){
//        double p;
//        p=(double)(tr[i].a+tr[i].b+tr[i].c)/2;
//        ptr[i]=sqrt((double)p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
//    }
//    for(i=0;i<n;i++){
//        for(j=i+1;j<n;j++){
//            if(ptr[i]>ptr[j]){
//                double temp1=ptr[i];
//                ptr[i]=ptr[j];
//                ptr[j]=temp1;
//                triangle temp=tr[i];
//                tr[i]=tr[j];
//                tr[j]=temp;
//                
//            }
//        }
//    }
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	triangle *tr = malloc(n * sizeof(triangle));
//	for (int i = 0; i < n; i++) {
//		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
//	}
//	sort_by_area(tr, n);
//	for (int i = 0; i < n; i++) {
//		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
//	}
//	return 0;
//}
 
// ------------------ --------- method-1

//#include <stdio.h>
//#include <string.h>
//void swap(char **a,char **b){
//	char *temp=*a;
//	*a=*b;
//	*b=temp;
//}
//int nest_permutation(int n,char **s){                                                                                                                                                                                                       
//	int k=n-2;
//	while(k>=0){
//		if(strcmp(s[k],s[k+1])<0){break;} // if string is lexographically sorted then leave
//		k--;
//	}
//	if(k==-1){return 0;}
//	int l=n-1;
//	if(l>k){
//		if(strcmp(s[k],s[l])<0){break;}
//		l--;
//	}
//	swap(&s[k],&s[l]);
//	int i=k+1;
//	int j=n-1;
//	while(j>i){
//		swap(&s[i],&s[j]);
//		i++;
//		j--;
//	}
//	return 0;
//}
//int main(){
//	
//	return 0;
//}










//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//#define MAX_CHARACTERS 1005
//#define MAX_PARAGRAPHS 5
//
//struct word {
//    char* data;
//};
//
//struct sentence {
//    struct word* data;
//    int word_count;//denotes number of words in a sentence
//};
//
//struct paragraph {
//    struct sentence* data  ;
//    int sentence_count;//denotes number of sentences in a paragraph
//};
//
//struct document {
//    struct paragraph* data;
//    int paragraph_count;//denotes number of paragraphs in a document
//};
//struct document get_document(char* text) {
//    // Initialise variables.
//    struct document Doc;
//    int P = 1;
//    int p, s, w, c;
//    // Count the number of paragraphs.
//    for (int i=0; i < strlen(text); i++) {
//        if (text[i] == '\n') {
//            P++;
//        }
//    }
//    Doc.data = calloc(P, sizeof(struct paragraph));
//    Doc.paragraph_count = P;
//    // Count the number of sentences in each paragraph.
//    p = 0;
//    s = 0;
//    for (int i=0; i < strlen(text); i++) {
//        if (text[i] == '\n') {
//            Doc.data[p].data = calloc(s, sizeof(struct sentence));
//            Doc.data[p].sentence_count = s;
//            p++;
//            s = 0;
//        } else if (text[i] == '.') {
//            s++;
//        }
//    }
//    Doc.data[p].data = calloc(s, sizeof(struct sentence));
//    Doc.data[p].sentence_count = s;
//    // Count the number of words in each sentence in each paragraph.
//    p = 0;
//    s = 0;
//    w = 0;
//    for (int i=0; i < strlen(text); i++) {
//        if (text[i] == '\n') {
//            p++;
//            s = 0;
//        } else if (text[i] == '.') {
//            w++;
//            // printf("%d %d %d\n", p, s, w);
//            Doc.data[p].data[s].data = calloc(w, sizeof(struct word));
//            Doc.data[p].data[s].word_count = w;
//            s++;
//            w = 0;
//        } else if (text[i] == ' ') {
//            w++;
//        }
//    }
//    // Count the number of characters in each word in each ... .
//    p = 0;
//    s = 0;
//    w = 0;
//    c = 0;
//    for (int i=0; i < strlen(text); i++) {
//        if (text[i] == '\n') {
//            p++;
//            s = 0;
//        } else if (text[i] == '.') {
//            Doc.data[p].data[s].data[w].data = calloc(c, sizeof(char));
//            s++;
//            w = 0;
//            c = 0;
//        } else if (text[i] == ' ') {
//            Doc.data[p].data[s].data[w].data = calloc(c, sizeof(char));
//            w++;
//            c = 0;
//        } else {
//            c++;
//        }
//    }
//    // Populate document.
//    p = 0;
//    s = 0;
//    w = 0;
//    c = 0;
//    for (int i=0; i < strlen(text); i++) {
//        if (text[i] == '\n') {
//            p++;
//            s = 0;
//        } else if (text[i] == '.') {
//            s++;
//            w = 0;
//            c = 0;
//        } else if (text[i] == ' ') {
//            w++;
//            c = 0;
//        } else {
//            Doc.data[p].data[s].data[w].data[c] = text[i];
//            c++;
//        }
//    }
//    return Doc;
//}
//
//struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
//    return Doc.data[n-1].data[m-1].data[k-1];
//}
//
//struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
//    return Doc.data[m-1].data[k-1];
//}
//
//struct paragraph kth_paragraph(struct document Doc, int k) {
//    return Doc.data[k-1];
//}
//
//
//void print_word(struct word w) {
//    printf("%s", w.data);
//}
//
//void print_sentence(struct sentence sen) {
//    for(int i = 0; i < sen.word_count; i++) {
//        print_word(sen.data[i]);
//        if (i != sen.word_count - 1) {
//            printf(" ");
//        }
//    }
//}
//
//void print_paragraph(struct paragraph para) {
//    for(int i = 0; i < para.sentence_count; i++){
//        print_sentence(para.data[i]);
//        printf(".");
//    }
//}
//
//void print_document(struct document doc) {
//    for(int i = 0; i < doc.paragraph_count; i++) {
//        print_paragraph(doc.data[i]);
//        if (i != doc.paragraph_count - 1)
//            printf("\n");
//    }
//}
//
//char* get_input_text() {	
//    int paragraph_count;
//    scanf("%d", &paragraph_count);
//
//    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
//    memset(doc, 0, sizeof(doc));
//    getchar();
//    for (int i = 0; i < paragraph_count; i++) {
//        scanf("%[^\n]%*c", p[i]);
//        strcat(doc, p[i]);
//        if (i != paragraph_count - 1)
//            strcat(doc, "\n");
//    }
//
//    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
//    strcpy(returnDoc, doc);
//    return returnDoc;
//}
//
//int main() 
//{
//    char* text = get_input_text();
//    struct document Doc = get_document(text);
//
//    int q;
//    scanf("%d", &q);
//
//    while (q--) {
//        int type;
//        scanf("%d", &type);
//
//        if (type == 3){
//            int k, m, n;
//            scanf("%d %d %d", &k, &m, &n);
//            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
//            print_word(w);
//        }
//
//        else if (type == 2) {
//            int k, m;
//            scanf("%d %d", &k, &m);
//            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
//            print_sentence(sen);
//        }
//
//        else{
//            int k;
//            scanf("%d", &k);
//            struct paragraph para = kth_paragraph(Doc, k);
//            print_paragraph(para);
//        }
//        printf("\n");
//    }     
//}



//=========================================== Pascal's Triangle
//#include <stdio.h>
//int main(){
//	int n;
//	scanf("%d",&n);
//	int i,j;
//	for(i=0;i<n;i++){
//		for(j=0;j<n-i;j++){
//			printf(" ");
//		}
//		int a=1,b=1;
//		for(j=0;j<=2*i;j++){
//			
//			if(j%2==0 && (j==0 ||j==2*i)){
//				printf("%d",1);
//			}
//			else if(j%2==0 ){
//				printf("*");
//			}
//			else{
//				printf(" ");
//			}
//		}
//	printf("\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	int n;
//	printf("Enter NUm");
//	scanf("%d",&n);
//	int i,j;
//	for(i=1;i<n+1;i++){
//		for(j=1;j<n+1-i;j++){
//			printf("  ");
//		}
//		int res=1; 
//		for(j=1;j<=i;j++){
//			printf("%4d",res);
//			res=(res*(i-j))/j;
////			printf("\n %d \n",eval);
//		}	
//		printf("\n");
//	}
//	
//	return 0;
//}


//
//#include <stdio.h>
//int main(){
//	int n;
//	scanf("%d",&n);
//	if( (n%100==0 && n%400==0) || (n%4==0 && n%100!=0)){
//	    printf("Yes");
//	}
//	else{
//		printf("No");
//	}
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	 
//	return 0;
//}

//#include  <stdio.h>
//int main(){
//	float a=(int)22.0/7;
//	int b=6.25/2.5;
//	printf("%d",b);
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	int i,j;
//	int n;
//	scanf("%d",&n);
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n-i;j++){
//			printf(" ");
//		}
//		for(j=1;j<=2*i-1;j++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	for(i=1;i<n;i++){
//		for(j=1;j<=i;j++){
//			printf("  ");
//		}
//		for(j=1;j<=2*(n-i)-1;j++){
//			printf("*");
//		}
//		
//		printf("\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	int n;
//	scanf("%d",&n);
//	int i,j;
//	for(i=0;i<n;i++){
//		for(j=0;j<i;j++){
//			printf("  ");
//		}
//		int per=(n-i)*(n-1-i)/2;
//		for(j=0;j<n-i;j++){
//			per++;
//			printf("%4d",per);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//decimal to binary 
//#include <stdio.h>
//void bin(int n){
//	if(n>0){
//		if(n%2==0){
//			bin(n/2);
//			printf("0");
//		}
//		else if(n==1){
//	 
//			bin(n/2);
//			printf("1");
//		}
//	}
//	
//}
//int main(){
//	int n;
//	scanf("%d",&n);
//	bin(n);
//	return 0;
//}
//
//#include <stdio.h>
//int main(){ ;
//	int i,j;
//	char c='A';
//	for(i=0;i<n;i++){
//		for(j=0;j<i;j++){
//			printf(" ");
//		}
//		c='A';
//		c=c+i;
//		for(j=0;j<n-i;j++){
//			printf("%c ",c++);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//-------------------     swap using bitwise operator
//#include <stdio.h>
//int main(){
//	int a=5;
//	int b=7;
//	printf(" Before %d %d",a,b);
//	int c=b^a;
//	b=c^b;
//	a=c^a;
//	printf("After %d %d",a,b);
//	return 0;
//}

//
//#include <stdio.h>
//
//int main(){
//	int arr[]={221,234,53,466,56,66,667,86,69,66,1,2,3,4,5,6,7,8,9,0,55,66,77,888,12123,23434};
//	int i,j,k;
//	int ask;
//	scanf("%d",&ask);
//	int n=sizeof(arr)/4;
//	int max=arr[0];
//	for(i=0;i<n;i++){
//		for(j=i;j<n;j++){
//			if(arr[i]>arr[j]){
//				int temp=arr[j];
//				arr[j]=arr[i];
//				arr[i]=temp;
//			}
//		}
//	}
//	int start=0,end=n,mid=n/2;
//	while(start!=end){
//		if(ask<arr[mid]){
//			end=mid;
//			mid=(start+end)/2;
//		}
//		else if(ask==arr[mid]){
//			printf("yes");
//			break;
//		}
//		else{
//			start=mid+1;
//			mid=(start+end)/2;
//		}
//	}
//	if(start==end){
//		printf("no");
//	}
//	return 0;
//}

