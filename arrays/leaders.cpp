#include<iostream>
#include<vector>
using namespace std;

vector<int> leaders(int *a,int n){
    vector<int> res;
    for(int i=0;i<n;i++){
        bool isLeader=true;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                isLeader=false;
                break;
            }
        }
        if(isLeader){
            res.push_back(a[i]);
        }
    }
    return res;
}

int main(){
    int a[]={6,2,10,5,2};
    auto res=leaders(a,5);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}