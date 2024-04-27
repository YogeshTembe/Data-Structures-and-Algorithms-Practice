#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n ) {
    //code here
    long long int res=0;
    unordered_map<long long int,long long int>mp;
    int prefSum=0;
    for(int i=0;i<n;i++){
        prefSum+=arr[i];
        if(prefSum==0){res++;}
        mp[prefSum]++;
        cout<<"i"<<res<<" ";
    }
    
    for(auto it:mp){
        long long int temp=it.second;
        res+=(temp*(temp-1))/2;
        cout<<temp<<"-"<<res<<" ";
    }
    cout<<endl;
    return res;
}

int main(){
    vector<long long int>arr{0,0,5,5,0,0};
    cout<<findSubarray(arr,6);
    return 0;
}