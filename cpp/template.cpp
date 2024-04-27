#include<iostream>
using namespace std;

template<typename T>
T Max(T a, T b){
    cout<<typeid(T).name()<<endl;
    return a>b?a:b;
}

template<typename T,int size>
void sum(T (&parr)[size]){
    cout<<"--"<<size<<endl;
}

// template<>
// char Max<char>(char a,char b){
//     cout<<typeid(char).name()<<endl;
//     cout<<a<<" "<<b<<endl;
//     return int(a)>int(b)?a:b;
// }

template<typename T,int size>
void print(T arg){
    cout<<arg<<" "<<size<<endl;
}

int main(){
    cout<<Max(3,4)<<endl;
    cout<<Max(4.5,3.2)<<endl;
    cout<<Max<int>(4.5,7)<<endl;
    cout<<Max("A","B")<<endl;
    //cout<<typeid(const char*).name()<<endl;
    print<char,5>('i');

    int arr[4]{2,3,5,6};
    sum(arr);
    return 0;
}