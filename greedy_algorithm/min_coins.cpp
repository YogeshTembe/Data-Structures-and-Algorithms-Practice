#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mincoins(int amount,vector<int>& coins){
    int num=0;
    sort(coins.begin(),coins.end());
    for(int i=coins.size()-1;i>=0;i--){
        int c=amount/coins[i];
        num+=c;
        amount=amount-(c*coins[i]);
        if(amount<=0){
            break;
        }
    }
    return num;
}

int main(){
    vector<int>coins{18,10,1};
    cout<<mincoins(20,coins);
    return 0;
}