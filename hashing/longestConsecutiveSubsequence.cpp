#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutiveSubsq(vector<int>arr){
    unordered_set<int>s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    int res=0;
    int curr=0;
    for(auto it=s.begin();it!=s.end();it++){
        if(s.find(*it-1)==s.end()){
            res=max(res,curr);
            curr=1;
        }else{
            curr++;
        }
    }
    res=max(res,curr);
    return res;
}

int main(){
    vector<int>arr{1,3,4,3,3,2,9,10};
    cout<<longestConsecutiveSubsq(arr);
    return 0;
}