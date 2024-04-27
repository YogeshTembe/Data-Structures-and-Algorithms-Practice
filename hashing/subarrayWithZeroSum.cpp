#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool subarrayWithZeroSum(vector<int>arr){
    int prefSum=0;
    unordered_set<int>s;
    for(int i=0;i<arr.size();i++){
        prefSum+=arr[i];
        if(prefSum==0){return true;}
        s.insert(prefSum);
    }
    return s.size()!=arr.size();
}

int main(){
    vector<int>arr{-1,4,-3,5,1};
    cout<<subarrayWithZeroSum(arr);
    return 0;
}