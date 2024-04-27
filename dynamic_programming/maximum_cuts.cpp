#include<iostream>
using namespace std;

int maximumCuts(int n,int a,int b,int c){
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;
    }
    int res=max(max(maximumCuts(n-a,a,b,c),maximumCuts(n-b,a,b,c)),maximumCuts(n-c,a,b,c));
    if (res==-1)
    {
        return -1;
    }
    return 1+res;
}

int main(){
    cout<<maximumCuts(5,1,2,3)<<endl;
    cout<<maximumCuts(23,12,11,13)<<endl;
    cout<<maximumCuts(3,2,4,2)<<endl;
    return 0;
}