#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

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

//naive solution
//time complexity- O(n sqrt(n))
void printPrimesTill1(int num){
    for(int i=2;i<=num;i++){
        if(isPrime4(i)){
            cout<<i<<" ";
        }
    }
}

//efficient solution
//sieve of era
void printPrimesTill2(int num){
    vector<bool> res;
    //cout<<num<<endl;
    for(int i=0;i<=num;i++){
        res.push_back(true);
    }
    for(int i=2;i<=sqrt(num);i++){//because all the divisors will be covered till sqrt of n
        //cout<<i<<" "<<res.at(i)<<endl;
        if(res.at(i)){
            for(int j=i*2;j<=num;j=j+i){//because first multiple of i is i*2 and we move j by i steps 
              if(j%i==0){
                  res[j]=false;
                  //cout<<"false- "<<j<<" "<<res[j]<<" ";
              }  
            }
            //cout<<endl;
        }
    }
    for(int i = 2; i<=num; i++){
        if(res.at(i)){
            cout<<i<<" ";
        }
    }
}

//more efficient solution 
//here the inner for loop starts with i*i because
//eg if i=5 and j=i*2, we go from 10,15,20,25,30,35..
//if i=5 and j=i*i, we go from 25,30,35... we avoid 10,15 and 20 as these numbers are already marked as false by i=2 and i=3
//the logic here is the values of j lower that i*i will be in form i*(i-1) or i*(i-2) or i*(i-3) so these numbers will be definitely be covered by lower numbers
//time complexity- O(n loglogn)
void printPrimesTill3(int num){
    vector<bool> res;
    //cout<<num<<endl;
    for(int i=0;i<=num;i++){
        res.push_back(true);
    }
    for(int i=2;i<=sqrt(num);i++){//because all the divisors will be covered till sqrt of n
        //cout<<i<<" "<<res.at(i)<<endl;
        if(res.at(i)){
            for(int j=i*i;j<=num;j=j+i){ 
              if(j%i==0){
                  res[j]=false;
                  //cout<<"false- "<<j<<" "<<res[j]<<" ";
              }  
            }
            //cout<<endl;
        }
    }
    for(int i = 2; i<=num; i++){
        if(res.at(i)){
            cout<<i<<" ";
        }
    }
}

int main(){
    printPrimesTill2(50);
    cout<<endl;
    printPrimesTill3(50);
    return 0;
}