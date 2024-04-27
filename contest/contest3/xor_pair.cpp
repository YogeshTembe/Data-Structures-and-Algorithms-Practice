#include<iostream>
#include<unordered_set>
using namespace std;

bool pairExists(int arr[], int n, int c)
{
    //Your code here
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(s.find(arr[i]^c)!=s.end()){
            cout<<arr[i]<<" "<<(arr[i]^c)<<endl;
            return true;
        }
    }
    return false;
}

int main(){
    int arr[]{2,1,10,3,4,9,5};
    int n=7;
    cout<<pairExists(arr,n,7)<<endl;

    int arr2[]{9,9,10,10,3};
    int n2=5;
    cout<<pairExists(arr2,n2,1)<<endl;
    return 0;
}