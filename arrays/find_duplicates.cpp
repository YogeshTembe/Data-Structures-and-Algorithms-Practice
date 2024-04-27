#include<iostream>
#include<vector>
using namespace std;

void findDuplicates(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<arr.size();i++){
        arr[arr[i]%n]=arr[arr[i]%n]+n;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]/n > 1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    vector<int>arr{1,3,2,6,3,6,1};
    findDuplicates(arr);
    return 0;
}