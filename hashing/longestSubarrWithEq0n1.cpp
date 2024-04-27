#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubarrayWithEqOnZ(vector<int>arr){
    int res=0;
    int countO=0;
    int countZ=0;
    unordered_map<int,int>m;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            countO++;
        }
        if(arr[i]==0){
            countZ++;
        }
        if(countO==countZ){res=i+1;}
        int diff=countO-countZ;
        if(m.find(diff)!=m.end()){
            res=max(res,i-m[diff]);
        }else{
            m.insert({diff,i});
        }
    }
    return res;
}

int main(){
    vector<int>arr{0,0,1,1,1,1,1,0};
    cout<<longestSubarrayWithEqOnZ(arr);
    return 0;
}