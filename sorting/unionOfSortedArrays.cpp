#include<iostream>
#include<vector>
using namespace std;

vector<int> unionOfArrays(vector<int>a1,vector<int>a2){
    vector<int>res;
    int p1=0;
    int p2=0;
    while(p1<a1.size() && p2<a2.size()){
        cout<<p1<<" "<<p2<<endl;
        if(p1>0 && a1[p1]==a1[p1-1]){p1++;continue;}
        if(p2>0 && a2[p2]==a1[p2-1]){p2++;continue;}
        if(a1[p1]>a2[p2]){
            res.push_back(a2[p2]);
            p2++;
        }
        else if(a1[p1]<a2[p2]){
            res.push_back(a1[p1]);
            p1++;
        }
        else{
            res.push_back(a1[p1]);
            p1++;p2++;
        }
        
    }
    while(p1<a1.size()){
        if(p1>0 && a1[p1]==a1[p1-1]){p1++;continue;}
        res.push_back(a1[p1]);
        p1++;
    }
    while(p2<a2.size()){
        if(p2>0 && a2[p2]==a2[p2-1]){p2++;continue;}
        res.push_back(a2[p2]);
        p2++;
    }
    return res;
}

int main(){
    // vector<int>a1{3,5,8};
    // vector<int>a2{2,8,9,10,15};
    vector<int>a1{2,3,3,3,4,4};
    vector<int>a2{4,4};
    auto res=unionOfArrays(a1,a2);
    for(auto r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}