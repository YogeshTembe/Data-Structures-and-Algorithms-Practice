#include<iostream>
using namespace std;

pair<int, int> findRepeating(int *arr, int n){
    //code here
    pair<int,int>res;
    res.first=0;
    res.second=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            res.second=res.second+1;
            res.first=arr[i];
        }
    }
    if(res.first == 0){res.first=-1;res.second=-1;}
    return res;
}

int main(){
    int arr[]{1,2,3};
    auto p=findRepeating(arr,3);
    cout<<p.first<<endl;
    cout<<"here-"<<p.second<<endl;
    return 0;
}