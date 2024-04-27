#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestCommonSpanSum(vector<int>a,vector<int>b){
    unordered_map<int,int>m;
    int prefa=0;
    int prefb=0;
    int res=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            prefa-=1;
        }else{
            prefa+=1;
        }
        if(b[i]==0){
            prefb-=1;
        }else{
            prefb+=1;
        }
        if(prefa-prefb==0){res=i+1;}
        if(m.find(prefa-prefb)!=m.end()){
            res=max(res,i-m[prefa-prefb]);
        }else{
            m.insert({prefa-prefb,i});
        }
    }
    return res;
}

int main(){
    // vector<int>a{0,1,0,1,1,1,1};
    // vector<int>b{1,1,1,1,1,0,1};
    vector<int>a{0,1,0,0,0,0};
    vector<int>b{1,0,1,0,0,1};
    cout<<longestCommonSpanSum(a,b);
    return 0;
}