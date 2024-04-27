#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubarrWithGivenSum(vector<int>arr,int sum){
    unordered_map<int,int>m;
    int prefSum=0;
    int res=0;
    for(int i=0;i<arr.size();i++){
        prefSum+=arr[i];
        if(prefSum==sum){
            res=i+1;
        }
        if(m.find(prefSum-sum)==m.end()){
            m.insert({prefSum,i});
        }else{
            res=max(res,m[prefSum-sum]);
        }
    }
    return res;
}

int main(){
    vector<int>arr{5,8,-4,-4,9,-2,2};
    cout<<longestSubarrWithGivenSum(arr,0);
    // vector<int>arr{3,1,0,1,8,2,3,6};
    // cout<<longestSubarrWithGivenSum(arr,5);
    return 0;
}