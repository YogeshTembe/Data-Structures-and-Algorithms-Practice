#include<iostream>
using namespace std;

long long int floorSqrt(long long int x) 
{
    // Your code goes here  
    if(x==1){return 1;} 
    long long int left=1,right=x/2,mid=0,res=0;
    while(left<=right){
        mid=(left+right)/2;
        if(mid*mid==x){
            return mid;
        }else if(mid*mid<x){
            res=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return res;
}

int main(){
    cout<<floorSqrt(4);
    return 0;
}