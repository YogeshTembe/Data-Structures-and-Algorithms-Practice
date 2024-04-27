#include<iostream>
using namespace std;

int countWays(int n)
{
    // your code here
    if(n==0){return 0;}
    return countWays()+countWays();
}

int main(){
    return 0;
}