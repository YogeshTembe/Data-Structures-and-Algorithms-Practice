#include<iostream>
#include<unordered_map>
using namespace std;

long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    //Your code here
    int prefSum=0;
    unordered_map<int,long long int>mp;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            prefSum-=1;
        }else{
            prefSum+=1;
        }
        mp[prefSum]++;
    }
    
    long long int res=0;
    if(mp.find(0)!=mp.end()){
        res+=mp[0];
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        res=res+((it->second-1)*(it->second))/2;
    }
    return res;
}

int main(){
    return 0;
}