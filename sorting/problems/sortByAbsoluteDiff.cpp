#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortABS(int arr[],int N, int k)
{
    //Your code here
    vector<pair<int,int>>diff;
    for(int i=0;i<N;i++){
        diff.push_back(pair<int,int>{abs(k-arr[i]),i});
    }
    sort(diff.begin(),diff.end());
    int B[N];
    for(int i=0;i<N;i++)
    {
    B[i]=arr[diff[i].second];
    }
    for(int i=0;i<N;i++)
    {
    arr[i]=B[i];
    }
}

int main(){
    int arr[]={10, 5, 3, 9, 2};
    sortABS(arr,5,7);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}