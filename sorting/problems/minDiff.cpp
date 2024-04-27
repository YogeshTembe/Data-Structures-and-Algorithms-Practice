#include<iostream>
#include<algorithm>
using namespace std;

int MinimumDifference(int arr[], int n)
{
    //code here
    std::sort(arr,arr+n);
    int mindiff=INT_MAX;
    for(int i=0;i<n-1;i++){
        if((arr[i+1]-arr[i])<mindiff){
            mindiff=arr[i+1]-arr[i];
        }
    }
    return mindiff;
}

int main(){
    int arr[5]={2, 4, 5, 9, 7};
    cout<<MinimumDifference(arr,5);
    return 0;
}