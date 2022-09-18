#include <iostream>
#include <string> 
#include <cmath>


using namespace std;

int trailingZerosOfFactorial(int num){
    // int start=10;
    // int zerosCount=0;
    // while(num%10==0){
    //     num=int(num/10);
    //     zerosCount++;
    // }
    // return zerosCount;

    int start=5;
    int zerosCount=0;
    int res=1;
    int sum=0;
    while(1){
        res=floor(num/start);
        start=start*5;
        cout<<"res"<<res<<endl;
        if(res>0){
        sum=sum+res;}
        else{return sum;}
    }
    
}

int factorial(int num){
    if(num==0){
        return 1;
    }
    return num*factorial(num-1);
}

int main()
{
    cout<<trailingZerosOfFactorial(100)<<endl;
    return 0;
}
