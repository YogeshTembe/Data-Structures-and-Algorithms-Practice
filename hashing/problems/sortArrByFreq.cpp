#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;

vector<int> sortByFreq(int arr[],int n)
{
    //Your code here
    unordered_map<int,int>mp;
    map<int,set<int>>mp2;
    vector<int>res;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto m:mp){
        if(mp2.find(m.second)==mp2.end()){
            mp2.insert({m.second,{m.first}});
        }else{
            mp2[m.second].insert(m.first);
        }
    }
    // for(auto m:mp2){
    //     cout<<m.first<<"-"<<m.second.size()<<endl;
    //     for(auto a:m.second){
    //         cout<<a<<" ";
    //     }
    //     cout<<endl;
    // }

    for(auto it=mp2.rbegin();it!=mp2.rend();it++){
        //cout<<(it->first)<<"--"<<(it->second.size())<<endl;
        for(auto e:it->second){
            int j=0;
            //cout<<e<<endl;
            while(j<(it->first)){
                res.push_back(e);
                j++;
            }
        }
    }
    return res;
}
int main(){
    int arr[]={5,5,4,6,4};
    auto res=sortByFreq(arr,5);
    cout<<"res-"<<endl;
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}