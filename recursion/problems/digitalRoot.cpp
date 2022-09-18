#include<iostream>
using namespace std;

int digitalRoot(int n)
{
    //Your code here
    if(n<=9){
        return n;
    }
    int sum=0;
    int temp=n;
    while(temp!=0){
        sum=sum+temp%10;
        temp=temp/10;
    }
    return digitalRoot(sum);
}

int main(){
    cout<<digitalRoot(1);
    return 0;
}