#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int countDistinctElements(vector<int>arr){
    unordered_set<int>eles;
    for(int i=0;i<arr.size();i++){
        eles.insert(arr[i]);
    }
    return eles.size();
}

int main(){
    vector<int>arr{15,12,13,12,13,13,18};
    cout<<countDistinctElements(arr);
    return 0;
}