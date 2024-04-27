#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
{
    //Your code here
    vector<int>res;
    unordered_map<int,int>mp;
    for(int i=0;i<M;i++){
        mp[A2[i]]=0;
    }
    vector<int>other;
    for(int i=0;i<N;i++){
        if(mp.find(A1[i])!=mp.end()){
            mp[A1[i]]++;
        }else{
            other.push_back(A1[i]);
        }
    }
    for(int i=0;i<M;i++){
        if(mp[A2[i]]>0){
            int j=0;
            while(j<mp[A2[i]]){
                res.push_back(A2[i]);
                j++;
            }
            mp[A2[i]]=-1;
        }
    }
    std::sort(other.begin(),other.end());
    for(int i=0;i<other.size();i++){
        res.push_back(other[i]);
    }
    // for(auto it:mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // for(auto o:other){
    //     cout<<o<<" ";
    // }
    return res; 
} 

int main(){
    vector<int>A1{2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    vector<int>A2{2, 1, 8, 3};
    auto res=sortA1ByA2(A1,11,A2,4);
    cout<<"res-"<<endl;
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}
