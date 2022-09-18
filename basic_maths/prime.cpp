#include<iostream>
#include <cmath>
using namespace std;

//naive solution
bool isPrime1(int num){
    int a=2;
    if(num==0 || num ==1){
        return false;
    }
    while(a<num){
        if(num%a==0){
            return false;
        }
        a++;
    }
    return true;
}

//efficient solution
bool isPrime2(int num){
    if((num+1)%6==0 || (num-1)%6==0){
        return true;
    }
    return false;
}

//efficient solution
//just check till square root of n 
bool isPrime3(int num){
    int a=2;
    if(num==0 || num ==1){
        return false;
    }
    while(a<sqrt(num)){
        if(num%a==0){
            return false;
        }
        a++;
    }
    return true;
}

//efficient solution
//check for divisibility by 2 and 3 because 2 is the only even prime number and if we check for divisibility by 2 then we can skip checking 
//divisibility by all other even numbers so iterations are reduced to half
bool isPrime4(int num){
    if(num==0 || num ==1){
        return false;
    }
    if(num==2 || num==3){
        return true;
    }
    if(num%2==0 || num%3==0){
        return false;
    }
    int a=5;//because we are already checking divisibility by 2 and 3
    while(a<sqrt(num)){
        if(num%a==0 || num%(a+2)==0){ //because we are already checking divisibility by 2 and 3
            return false;
        }
        a=a+6;//because we are already checking divisibility by 2 and 3
    }
    return true;
}
 

int main(){
    cout<<isPrime1(121)<<endl;
    cout<<isPrime2(1031)<<endl;
    cout<<isPrime3(1031)<<endl;
    cout<<isPrime4(1031)<<endl;
    return 0;
}