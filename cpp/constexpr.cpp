#include<iostream>
using namespace std;

constexpr int add(int a,int b){
    return a+b;
}

int main(){
    int a=4;
    constexpr int c=add(56,5);
    cout<<c<<endl;
    return 0;
}