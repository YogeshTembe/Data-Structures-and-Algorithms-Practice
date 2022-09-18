#include <iostream>
#include <cmath>
using namespace std;

bool IsKthBitSet1(int n,int k){
    int a=pow(2,k-1);
    //cout<<(n & a);
    return n & a;
}

//using left shift operator
bool IsKthBitSet2(int n,int k){
    return n & (1<<(k-1));
}

//using right shift operator
bool IsKthBitSet3(int n,int k){
    return (n>>(k-1)) & 1;
}

int main(){
    cout<<IsKthBitSet1(8,4);
    cout<<IsKthBitSet2(8,4);
    cout<<IsKthBitSet3(8,4);
    return 0;
}