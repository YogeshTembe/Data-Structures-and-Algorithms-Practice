#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//naive solution
vector<int> allDivisors1(int num){
    vector<int> res;
    res.push_back(1);
    for(int i=2;i<num;i++){
        if(num%i==0){
            res.push_back(i);
        }
    }
    return res;
}

//not sure if this solution is efficient
vector<int> allDivisors2(int num){
    vector<int> res;
    res.push_back(1);
    if(num%2==0){
        for(int i=2;i<=num/2;i=i+2){
            if(num%i==0){
            res.push_back(i);}
        }
    }
    if(num%3==0){
        cout<<"here";
        for(int i=3;i<=num/3;i=i+3){
            if(num%i==0 && i%2!=0){
            res.push_back(i);}
        }
    }
    for(int i=5;i<num;i=i+6){
        if(num%i==0){
            res.push_back(i);
        }
        if(num%(i+2)==0){
            res.push_back(i+2);
        }
    }
    return res;
}

//efficient solution
//divisors always appear in pairs so find the divisors till sqrt(n) and then divide n with each divisor to get the divisors higher than sqrt(n)
vector<int> allDivisors3(int num){
    vector<int> res;
    vector<int> newres;
    for(int i=1;i<=sqrt(num);i++){
        if(num%i==0){
            res.push_back(i);
            if(i!=num/i){
                newres.push_back(num/i);
            }
        }
    }
    for(auto i = newres.end()-1; i != newres.begin(); --i){
        res.push_back(*i);
    }
    return res;
}

int main(){
    vector<int> res=allDivisors1(36);
    for (auto i = res.begin(); i != res.end(); ++i){
        cout << *i << " ";
    }
    cout<<endl;
    vector<int> res2=allDivisors2(36);
    for (auto i = res2.begin(); i != res2.end(); ++i){
        cout << *i << " ";
    }
    cout<<endl;
    vector<int> res3=allDivisors3(36);
    for (auto i = res3.begin(); i != res3.end(); ++i){
        cout << *i << " ";
    }
    return 0;
}