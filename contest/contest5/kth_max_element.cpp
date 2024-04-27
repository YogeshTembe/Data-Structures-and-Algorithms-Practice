#include<iostream>
#include<queue>
using namespace std;

int kthMaximumElement(int arr[], int n, int k)
{
    //Your code here
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    int arr[]={50,40,30,35,38,20,25};
    cout<<kthMaximumElement(arr,7,3)<<endl;
    int arr2[]={60,55,57,54,53,50,52,51,49};
    cout<<kthMaximumElement(arr2,9,6)<<endl;
    return 0;
}