#include<iostream>
#include<vector>
using namespace std;

//only for k=2
//Not a good solution
int allocateMinimumPages(int arr[],int n){
    vector<int>leftSum;
    vector<int>rightSum;
    int lsum=0,rsum=0;
    for(int i=0;i<n;i++){
        lsum+=arr[i];
        leftSum.push_back(lsum);
    }

    for(int i=n-1;i>=0;i--){
        rsum+=arr[i];
        rightSum.push_back(rsum);
    }
    int minDiff=INT_MAX;
    int minIndex=0;
    for(int i=0;i<leftSum.size()-1;i++){
        if(abs(leftSum[i]-rightSum[rightSum.size()-2-i])<minDiff){
            minDiff=abs(leftSum[i]-rightSum[rightSum.size()-2-i]);
            minIndex=i;
        }
    }
    cout<<minDiff<<" "<<minIndex<<endl;
    if(leftSum[minIndex]>rightSum[rightSum.size()-2-minIndex]){
        return leftSum[minIndex];
    }
    return rightSum[rightSum.size()-2-minIndex];
}

int studentsRequired(int arr[],int n,int pages){
    int s=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if((sum+arr[i])>pages){
            sum=0;
            s++;
        }
        sum+=arr[i];
    }
    return s;
}

int allocateMinimumPages2(int arr[],int n,int k){
    int sum=0;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(arr[i]>max){max=arr[i];}
    }
    int left=max;
    int right=sum;
    int min=INT_MAX;
    while(left<=right){
        int mid=(left+right)/2;
        int res=studentsRequired(arr,n,mid);
        if(res==k && mid<min){
            min=mid;
            right=mid-1;// if feasible go to left half to minimise the pages read by each student
        }
        else{
            left=mid+1;
        }
        cout<<res<<" "<<mid<<endl;
    }
    return min;
}

int main(){
    //int arr[]{30,1,2,5,10,10};
    int arr[]{10,20,10,30};
    cout<<allocateMinimumPages2(arr,4,2);
    return 0;
}