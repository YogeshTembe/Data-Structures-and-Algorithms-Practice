#include<iostream>
#include<cmath>
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
vector<int> primeFactors1(int num){
    vector<int> res;
    for(int i=2;i<num;i++){
        cout<<"primeFactors1 "<<i<<endl;
        if(isPrime4(i)){
            int x=i;
            while(num%x==0){
                res.push_back(i);
                x=x*i;
            }
        }
    }
    return res;
}

//efficient solution
//no need to check for prime
//divide the number with the prime factor that we found just now and it saves iterations as number reduces 
vector<int> primeFactors2(int num){
    vector<int> res;
    for(int i=2;i<=sqrt(num);i++){
        cout<<"primeFactors2 "<<i<<endl;
        while(num%i==0){
            res.push_back(i);
            num=num/i;
        }
    }
    if(num>1){res.push_back(num);}//to get the last reminaing prime factor
    return res;
}

//more efficient solution, handle 2 and 3 seperately and avoid checking all the multiples of 2 and 3
//saves iterations
vector<int> primeFactors3(int num){
    vector<int> res;
    while(num%2==0){
        res.push_back(2);
        num=num/2;
    }
    while(num%3==0){
        res.push_back(3);
        num=num/3;
    }
    for(int i=5;i<=sqrt(num);i=i+6){
        cout<<"primeFactors2 "<<i<<endl;
        while(num%i==0){
            res.push_back(i);
            num=num/i;
        }
        while(num%(i+2)==0){
            res.push_back(i+2);
            num=num/(i+2);
        }
    }
    if(num>3){res.push_back(num);}//to get the last reminaing prime factor, here we have 3 because 2 n 3 are already handled and remaining prime factor will be >3
    return res;
}


int main(){
    vector<int> res=primeFactors1(12);
    for (auto i = res.begin(); i != res.end(); ++i){
        cout << *i << " ";
    }
    cout<<endl;
    vector<int> res2=primeFactors2(12);
    for (auto i = res2.begin(); i != res2.end(); ++i){
        cout << *i << " ";
    }
    cout<<endl;
    vector<int> res3=primeFactors3(12);
    for (auto i = res3.begin(); i != res3.end(); ++i){
        cout << *i << " ";
    }
    return 0;
}