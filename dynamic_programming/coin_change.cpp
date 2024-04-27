#include<iostream>
#include<vector>
using namespace std;

int totalWays(int sum,int idx,vector<int>& coins){
    cout<<idx<<" "<<sum<<endl;
    if(sum<=0){return 0;}
    for(int i=idx;i<coins.size();i++){
        if(sum==coins[i]){return 1;}
        else if(sum>coins[i]){ return 1+totalWays(sum-coins[i],idx,coins)+totalWays(sum-coins[i],idx+1,coins);}
        else{
            return 0;
        }
    }
    return 0;
}

int totalWays2(int idx,int sum,vector<int>& coins){
    cout<<idx<<" "<<sum<<endl;
    if(sum==0){return 1;}
    if(sum<0){return 0;}
    if(idx<0){return 0;}
    
    int res=0;
    res+=totalWays2(idx,sum-coins[idx],coins);
    res+=totalWays2(idx-1,sum,coins);
    return res;
}

int main(){
    vector<int>coins{2,3,5,6};
    // cout<<totalWays(10,0,coins);
    cout<<totalWays2(3,10,coins);
    return 0;
}