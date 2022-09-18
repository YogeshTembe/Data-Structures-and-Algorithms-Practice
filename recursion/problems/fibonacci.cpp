#include<iostream>
using namespace std;

int fibonacci(int n)
{
    //Your code here
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    cout<<fibonacci(20);
    return 0;
}