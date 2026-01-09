#include <bits/stdc++.h>
using namespace std;


class A{
    int x(){
        return 10;
    }
    public:
    int x(){
        return this->x();
    }
};
int main(){
    A obj;
    cout<<obj.x();
    return 0;
}