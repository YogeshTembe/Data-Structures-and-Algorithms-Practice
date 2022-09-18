#include<iostream>
using namespace std;

int countDigits(int n)
{
    //Your code here
    if(n/10==0){
        return 1;
    }
    return 1+countDigits(n/10);
}

int main(){
    cout<<countDigits(1)<<endl;
    cout<<countDigits(0)<<endl;
    cout<<countDigits(456)<<endl;
    return 0;
}