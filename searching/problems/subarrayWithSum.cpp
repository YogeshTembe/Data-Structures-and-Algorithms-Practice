#include<iostream>
#include<vector>
using namespace std;

//sliding window technique
vector<int> subarraySum(int arr[], int n, long long s)
{
    // Your code here
    long long curr=0;
    int left=0;
    vector<int>res;
    for(int right=0;right<n;right++){
        curr=curr+arr[right];
        while(curr>s){
            curr=curr-arr[left];
            left++;
        }
        if(s==curr && left<=right){
            res.push_back(left+1);
            res.push_back(right+1);
            return res;
        }
    }
    cout<<curr<<endl;
    res.push_back(-1);
    return res;
}

int main(){
    int arr[]{1,2,3,4};
    auto a=subarraySum(arr,4,0);
    cout<<a[0]<<" "<<a[1]<<endl;
    return 0;
}