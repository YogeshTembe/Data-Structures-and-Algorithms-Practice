#include<iostream>
using namespace std;

int josephus1(int n,int k){
    if(n==1){
        return 0;
    }
    return (k+josephus1(n-1,k))%n;
}

int josephus(int n, int k)
{
    //Your code here
    return 1+josephus1(n,k);
}

int main(){
    cout<<josephus(7,3);
    return 0;
}