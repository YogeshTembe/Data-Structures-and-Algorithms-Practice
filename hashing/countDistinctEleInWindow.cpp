#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> countDistinctElementsInEveryWindow(vector<int>arr,int k){
    unordered_map<int,int>m;
    vector<int>res;
    for(int i=0;i<k;i++){
        m[arr[i]]+=1;
    }
    res.push_back(m.size());
    for(int i=k;i<arr.size();i++){
        m[arr[i-k]]--;
        if(m[arr[i-k]]==0){
            m.erase(arr[i-k]);
        }
        if(m.find(arr[i])!=m.end()){
            m[arr[i]]++;
        }else{
            m.insert({arr[i],1});
        }
        res.push_back(m.size());
    }
    return res;
}

int main(){
    vector<int>arr{10,20,20,10,30,40,10};
    auto res=countDistinctElementsInEveryWindow(arr,4);
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}