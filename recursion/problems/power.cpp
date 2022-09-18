#include<iostream>
#include <cmath>
using namespace std;

/*
39907139
752962679
*/

int RecursivePower(int n,int p)
{
    //Your code here
    if(p==0){
        return 1;
    }
    return n*RecursivePower(n,p-1);
}

long long power(int N,int R)
{
    //Your code here
    if(R==0){
        return 1;
    }
    //cout<<N<<" "<<R<<endl;
    if(R%2==0){
        long long y=power(N,R/2);
        return (y*y)%1000000007;
    }
    if(R%2==1)
        return (N*power(N,R-1))%1000000007;
}

int main(){
    //cout<<power(12,21)<<endl;
    cout<<power(39907139,93170993)<<endl;
    //cout<<RecursivePower(12,21);
    return 0;
}