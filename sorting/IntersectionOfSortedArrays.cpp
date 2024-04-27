#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> intersection(vector<int>a1,vector<int>a2){
    vector<int>res;
    int p1=0;
    int p2=0;
    while(p1<a1.size() && p2<a2.size()){
        if(a1[p1]==a2[p2]){
            if(find(res.begin(),res.end(),a1[p1])==res.end()){
                res.push_back(a1[p1]);
            }
            p1++;p2++;
        }
        else if(a1[p1]>a2[p2]){
            p2++;
        }
        else{
            p1++;
        }
    }
    return res;
}

int main(){
    // vector<int>a1{3,5,10,10,10,15,15,20};
    // vector<int>a2{5,10,10,15,30};
    vector<int>a1{1,1,1,1,3,5,7};
    vector<int>a2{1,1,3,3,3};
    auto res=intersection(a1,a2);
    for(auto r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}