#include<iostream>
#include<vector>
using namespace std;

//equilibrium point is where the all the left elements sum is equal to all the right elemenets sum 

bool hasEquilibriumPoint(int a[],int n){
    vector<int>sum;
    sum.push_back(a[0]);
    for(int i=1;i<n;i++){
        sum.push_back(sum[i-1]+a[i]);
    }
    if((sum[n-1]-sum[0])==0 || (sum[n-2]==0)){
        return true;
    }
    for(int i=1;i<n-1;i++){
        if(sum[i-1]==(sum[i+1]-sum[i])){
            return true;
        }
    }
    return false;
}

//Efficient in terms of auxiliary space, here auxiliary space is O(1) and earlier it was O(n)
bool hasEquilibriumPoint2(int a[],int n){
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=a[i];
    }
    int currSum=0;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<totalSum<<" "<<currSum<<endl;
        if((totalSum-2*currSum)==a[i]){
            return true;
        }
        currSum=currSum+a[i];
    }
    return false;
}

int main(){
    int a[]{3,4,8,-9,20,6};
    //int a[]{2,-2,4};
    cout<<hasEquilibriumPoint2(a,6);
    return 0;
}