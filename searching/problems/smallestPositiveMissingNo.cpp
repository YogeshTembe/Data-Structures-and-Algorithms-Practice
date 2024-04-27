#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int missingNumber(int arr[], int n) 
{ 
    // Your code here
    vector<int>num;
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
                min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
        num.push_back(arr[i]);
    }
    if(min<0){min=1;}
    if(max<0){max=0;}
    cout<<min<<" "<<max<<endl;
    for(int i=min;i<=max+1;i++){
        if(count(num.begin(),num.end(),i)==0){
            return i;
        }
    }
    return 0;
} 

int main(){
    int arr[]{28,7,-36,21,-21,-50,9,-32};
    cout<<missingNumber(arr,8);
    return 0;
}