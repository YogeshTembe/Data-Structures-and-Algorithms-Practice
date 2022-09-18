#include<iostream>
using namespace std;

int maxParts(int n,int a,int b,int c){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 0;
    }
    cout<<n-a<<" "<<n-b<<" "<<n-c<<endl;
    int am=maxParts(n-a,a,b,c);
    int bm=maxParts(n-b,a,b,c);
    int cm=maxParts(n-c,a,b,c);
    cout<<"m- ";
    cout<<am<<" "<<bm<<" "<<cm<<endl;
    int res;
    if(am>=bm && am>=cm){
        res=am;
    }
    if(bm>=am && bm>=cm){
        res=bm;
    }
    if(cm>=am && cm>=bm){
        res=cm;
    }
    cout<<res<<endl;
    if(res==-1){return -1;}
    return res+1;
    
}

int main(){
    cout<<maxParts(9,2,2,2);
    return 0;
}