#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int buyMaxItems(vector<int>arr,int sum){
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
    int i=0;
    int res=0;
    cout<<"--"<<arr[0]<<endl;
    while(i<arr.size() && sum>0){
        if(pq.top()<=sum){
            sum=sum-pq.top();
            pq.pop();
            res++;
        }else{
            return res;
        }
        i++;
    }
    return res;
}

int main(){
    vector<int>arr{1,12,5,111,200};
    cout<<buyMaxItems(arr,10)<<endl;
    vector<int>arr2{20,10,5,30,100};
    cout<<buyMaxItems(arr2,35)<<endl;
    return 0;
}