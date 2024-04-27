#include<iostream>
using namespace std;

long long findNthFibonacci(int n)
{
    // Your Code Here
    if(n==1 || n==2){
        return n-1;
    }
    long long num1=0;
    long long num2=1;
    long long res;
    for(int i=2;i<=n;i++){
        res=num1+num2;
        num1=num2;
        num2=res;
    }   
    return res;
}

int main(){
    cout<<findNthFibonacci(6);
    return 0;
}