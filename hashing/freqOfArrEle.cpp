#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void printFreq(vector<int>arr){
    unordered_map<int,int>freq;
    for(int i=0;i<arr.size();i++){
        freq[arr[i]]+=1;
    }
    for(auto a:freq){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return;
}

int main(){
    vector<int>arr{10,12,10,15,10,20,12,12};
    printFreq(arr);
    return 0;
}