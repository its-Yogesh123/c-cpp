#include <bits/stdc++.h>
using namespace std;

int main(){
    int* ptr;
    char* ptr1 = (char*)ptr;
    ptr1 = new[ptr1]();
    cout<<*ptr<<" "<<*ptr1;
    return 0;
}