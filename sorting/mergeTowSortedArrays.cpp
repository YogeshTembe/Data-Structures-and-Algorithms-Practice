#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeTwo(vector<int>v1,vector<int>v2){
    int p1=0;
    int p2=0;
    vector<int>res;
    while(p1<v1.size() && p2<v2.size()){
        while(p1<v1.size() && v1[p1]<=v2[p2]){
            res.push_back(v1[p1]);
            p1++;
        }
        while(p2<v2.size() && v1[p1]>v2[p2]){
            res.push_back(v2[p2]);
            p2++;
        }
    }
    cout<<p1<<" "<<p2<<endl;
    while(p1<v1.size()){
        res.push_back(v1[p1]);
    }
    while(p2<v2.size()){
        res.push_back(v2[p2]);
    }
    return res;
}

int main(){
    vector<int>v1{5,6,7};
    vector<int>v2{1,2,3,8};
    auto res=mergeTwo(v1,v2);
    for(auto r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}