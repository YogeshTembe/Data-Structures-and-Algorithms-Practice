#include<iostream>
#include<vector>
using namespace std;

vector<int> twoRepeated (int arr[], int N) {
    // Your code here
    vector<int>res{};
    for(int i=0;i<N+2;i++){
        //cout<<arr[arr[i]-1]<<endl;
        if(arr[arr[i]-1]<0){
            res.push_back(arr[i]);
        }
        else{
            arr[arr[i]-1]=0-arr[arr[i]-1];
        }
        //cout<<arr[arr[i]-1]<<endl;
    }
    return res;
}

int main(){
    int arr[]{1,2,6,3,4,5,6,4};
    auto res=twoRepeated(arr,6);
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}