#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(auto a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
}

int findMedian(int arr[], int n, int brr[], int m)
{
    // code here
    int p1=0;
    int p2=0;
    vector<int>res;
    while(p1<n && p2<m){
        while(arr[p1]<=brr[p2] && p1<n){
            res.push_back(arr[p1]);
            p1++;
        }
        while(arr[p1]>brr[p2] && p2<m){
            res.push_back(brr[p2]);
            p2++;
        }
        
    }
    
    while(p1<n){
        res.push_back(arr[p1]);
        p1++;
    }
    while(p2<m){
        res.push_back(brr[p2]);
        p2++;
    }
    print(res);
    int len=res.size();
    if(len%2!=0){
        return res[int(len/2.0)];
    }
    return (res[int(len/2.0)]+res[int(len/2.0)+1])/2;

}

int main(){
    int arr[]{1,2,3,4};
    int brr[]{4};
    cout<<findMedian(arr,4,brr,1);
    return 0;
}