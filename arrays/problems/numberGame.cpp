#include<iostream>
using namespace std;

long long gcd(long long a,long long b){
    if(b==0){return a;}
    else{
        return gcd(b,a%b);
    }
}

long long numGame(long long n) {
    // code here
    int res=1;
    for(int i=2;i<n;i++){
        long long gcdvar=gcd(res,i);
        res=(res*(i/gcdvar)) % 1000000007;
    }
    return res;
}

int main(){
    cout<<numGame(4);
    return 0;
}