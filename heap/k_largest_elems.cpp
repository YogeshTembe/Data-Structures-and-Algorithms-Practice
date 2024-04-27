#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void kLargestElements(vector<int>arr,int k){
    priority_queue<int>pq(arr.begin(),arr.end());
    for(int j=0;j<k && j<arr.size();j++){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

int main(){
    vector<int>arr{5,15,10,20,8};
    kLargestElements(arr,2);
    return 0;
}