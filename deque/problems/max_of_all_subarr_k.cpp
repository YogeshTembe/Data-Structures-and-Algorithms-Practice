#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    deque<int>dq;
    for(int i=0;i<k;i++){
        cout<<arr[i]<<endl;
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    vector<int>res;
    for(int i=k;i<n;i++){
        res.push_back(arr[dq.front()]);
        //remove ele not there in subarray
        while(!dq.empty() && dq.front()<=(i-k)){
            dq.pop_front();
        }
        //now check for max ele
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    return res;
}

int main(){
    int arr[]={1,2,3,1,4,5,2,3,6};
    auto res=max_of_subarrays(arr,9,3);
    for(auto r:res){cout<<r<<" ";}
    return 0;
}