#include<iostream>
#include<vector>
#include<unordered_map>
#include <cmath>
using namespace std;

vector<int> moreThanNbyKOccu(vector<int>arr,int k){
    unordered_map<int,int>m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    int comp=ceil(arr.size()/k);
    vector<int>res;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second > comp){
            res.push_back(it->first);
        }
    }
    return res;
}

int main(){
    vector<int>arr{30,10,20,20,10,20,30,30};
    auto res=moreThanNbyKOccu(arr,4);
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}