#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool PairWithSumInArr(vector<int>arr,int sum){
    unordered_set<int>uarr;
    for(auto a:arr){
        uarr.insert(a);
    }
    for(auto a:arr){
        if(uarr.find(sum-a)!=uarr.end()){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int>arr{11,5,6};
    cout<<PairWithSumInArr(arr,10);
    return 0;
}