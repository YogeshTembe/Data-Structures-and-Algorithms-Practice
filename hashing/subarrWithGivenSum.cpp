#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool subarrayWithGivenSum(vector<int>arr,int sum){
    int prefSum=0;
    unordered_set<int>s;
    for(int i=0;i<arr.size();i++){
        prefSum+=arr[i];
        if(prefSum==sum){
            return true;
        }
        if(s.find(prefSum-sum)!=s.end()){
            return true;
        }
        s.insert(prefSum);
    }
    return false;
}

int main(){
    vector<int>arr{3,2,5,6};
    cout<<subarrayWithGivenSum(arr,9);
    return 0;
}