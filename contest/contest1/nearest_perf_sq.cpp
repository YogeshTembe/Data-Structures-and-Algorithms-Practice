#include<iostream>
#include<cmath>
using namespace std;

long long nearestPerfectSquare(long long n)
{
    //Your code here
    if(n==1){return 0;}
    long long sq=sqrt(n);
    long long min=floor(sq);
    long long max=ceil(sq);
    if(sq*sq == n){
        min=sq-1;
        max=sq+1;
    }
    if((n-min*min) < (max*max-n)){
        return min*min;
    }else{
        return max*max;
    }
}

int main(){
    cout<<nearestPerfectSquare(100)<<endl;
    return 0;
}