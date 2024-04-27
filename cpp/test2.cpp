#include<iostream>
using namespace std;

int main(){
    int a=89;
    int *p=&a;
    int *mem=new(p) int(100);
    cout<<a<<" "<<*p<<" "<<*mem<<endl;
    return 0;
}