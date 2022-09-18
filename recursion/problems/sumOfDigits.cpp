#include<iostream>
using namespace std;

 int sumOfDigits(int n)
{
    //Your code here
    if(n==0){return 0;}
    return (n%10)+sumOfDigits(n/10);
}

int main(){
    cout<<sumOfDigits(1);
    return 0;
}