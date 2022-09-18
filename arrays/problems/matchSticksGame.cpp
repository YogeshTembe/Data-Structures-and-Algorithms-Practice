#include<iostream>
using namespace std;

int matchGame(long long N) {
    // code here
    if(N<=4){return N;}
    if(N%5==0){return -1;}
    return N%5;
    return 0;
}

int main(){
    cout<<matchGame(10);
    return 0;
}