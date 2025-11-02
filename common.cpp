
//-- quick sort
//#include <iostream>
//using namespace std;
//void swap(int* a,int* b){
//	int temp=*a;
//	*a=*b;
//	*b=temp;
//}
//int partition(int* array,int start,int end){
//	int pivot=array[end];
//	int i;
//	int j=start-1;
//	for(i=start;i<end;i++){
//		if(array[i]<pivot){
//			j++;
//			swap(&array[i],&array[j]);
//		}
//	}
//	swap(&array[i],&array[j+1]);
//	return j+1;
//}
//void quickSort(int* array,int start,int end){
//	if(start>=end){
//		return;
//	}
//	int num=partition(array,start,end);
//	quickSort(array,start,num-1);
//	quickSort(array,num+1,end);
//}
//void print(int* array,int n){
//	int i;
//	for(i=0;i<n;i++){
//		cout<<array[i]<<" ";
//	}
//}
//int main(){
//	int n=10;
//	int array[n]={1,4,77,43,21,89,99,22,11,100};
//	cout<<"Before Sorted ";
//	print(array,n);
//	cout<<endl;
//	quickSort(array,0,n-1);
//	cout<<"after Sorted ";
//	print(array,n);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void sort(int* array,int n){
//	int i,j=0;
//	for(i=1;i<=n;i++){
//		int temp=array[i];
//		j=i;
//		while(j>0 && array[j-1]>temp){
//			array[j]=array[j-1];
//			j--;
//		}
//		array[j]=temp;
//	}
//}
//void print(int* array,int n){
//	int i;
//	for(i=0;i<n;i++){
//		cout<<array[i]<<" ";
//	}
//}
//int main(){
//	int n=5;
//	int array[n]={5,3,88,1,54};
//	sort(array,n-1);
//	print(array,n);
//	return 0;
//}
//----------------------------------------- Sliding Window Approach ------------
// create a desired size window and traverse it 
//  P-1 given a array find the subarray of three number such that sum is max
//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//    vector<int> vec={1,2,32,5,6,21,33,0,7,8};
//    int sum=vec[0]+vec[1]+vec[2];
//    vector<int> subVec={vec[0],vec[1],vec[2]};
//    map<int,vector<int>> map1;
//    map1[sum]=subVec;
//    int i=2,j=0;
//    while(i<vec.size()){
//        int temp=0;
//        for(int x=j;x<=i;x++){
//            temp+=vec[x];
//        }
//        if(temp>map1.begin()->first){     
//            // map1.begin()->first=temp;
//            map1.clear();
//            vector<int> tempVec={vec[j],vec[j+1],vec[i]};
//            map1.insert(pair<int,vector<int>>(temp,tempVec));
//        }
//        i++;
//        j++;
//    }
//    vector<int> vec1111=map1.begin()->second;
//    cout<<"The sum is : "<<map1.begin()->first<<endl;
//    cout<<vec1111[0]<<" "<<vec1111[1]<<" "<<vec1111[2];
//    return 0;
//}




//---------------------------- Permutation of String -------------------------
// using backtracking/recursion
//void swap(char& a,char& b){
//    char temp=a;
//    a=b;
//    b=temp;
//}
//void permute(string a,int l,int r){    // recursion 
//    if(l==r){
//        cout<<a<<endl;
//        return ;
//    }
//    for(int i=l;i<=r;i++){
//        swap(a[l],a[i]);
//        permute(a,l+1,r);
//        swap(a[l],a[i]);
//    }
//}
//-------------------- permutation usign STL ---------------
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;
// int main(){
//     string s1="cba";
//     sort(s1.begin(),s1.end());
//     do{
//         cout<<s1<<"\n";
//     }while(next_permutation(s1.begin(),s1.end()));
//     return 0;
// }