#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int firstRepeated(int arr[], int n) {
    // code here
    int minIdx=INT_MAX;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end()){
            minIdx=min(minIdx,mp[arr[i]]);
            mp[arr[i]]=min(mp[arr[i]],i+1);
        }else{
            mp[arr[i]]=i+1;
        }
    }
    // for(auto it=mp.begin();it!=mp.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    if(minIdx==INT_MAX){
        return -1;
    }
    return minIdx;
}

int main(){
    int arr[]={1, 2, 3, 4};
    cout<<firstRepeated(arr,4);
    return 0;
}