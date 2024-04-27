#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int unionOfUnsorArr(vector<int>a,vector<int>b){
    unordered_set<int>arr;
    for(int i=0;i<a.size();i++){
        arr.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){
        arr.insert(b[i]);
    }
    return arr.size();
}

int main(){
    vector<int>a{15,20,5,15};
    vector<int>b{15,15,15,20,10};
    cout<<unionOfUnsorArr(a,b);
    return 0;
}