#include<iostream>
using namespace std;


long long minOperations(long long n)
{
    //Your code here
    //cout<<n<<endl;
    if(n==1){return 0;}
    if(n%2==0){
        return 1+minOperations(n/2);
    }
    return 1+min(minOperations(n-1),minOperations(n+1));
}

int main(){
    cout<<minOperations(1)<<endl;
    cout<<minOperations(2)<<endl;
    cout<<minOperations(3)<<endl;
    cout<<minOperations(4)<<endl;
    return 0;
}