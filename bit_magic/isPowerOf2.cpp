#include <iostream>
#include <cmath>
using namespace std;

//naive solution
//divide n continuously by 0, and if it turns odd in the middle then return false else if it turns 1 then return true
bool isPowerOfTwo1(int n){
    if(n==0){
        return false;
    }
    while(n!=1){
        if(n%2!=0){
            return false;
        }
        n=n/2;
    }
    return true;
}

//efficient solution 
//checking if only 1 bit is set in the binary no.
int countSetBits2(int n){
    int setBits=0;
    while(n>0){
        n=(n & (n-1));
        setBits++;
    }
    return setBits;
}

bool isPowerOfTwo2(int n){
    if(countSetBits2(n)==1){
        return true;
    }
    return false;
}

//most efficient solution
//simple solution just turn off the only set bit and check if the number becomes 0
//because all the numbers which are power of 2 have only 1 set bit
bool isPowerOfTwo3(int n){
    if(n==0){return false;}
    return ((n&(n-1))==0);
}

int main(){
    cout<<isPowerOfTwo1(35)<<endl;
    cout<<isPowerOfTwo2(32)<<endl;
    cout<<isPowerOfTwo3(35)<<endl;
    return 0;
}