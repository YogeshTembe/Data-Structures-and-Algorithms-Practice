#include<iostream>
#include<vector>
using namespace std;

//Naive solution
//Time complexity = O(n^2)
int countInversions(vector<int> arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){count++;}
        }
    }
    return count;
}

int merge(int arr[],int low,int mid,int high){
    int count=0;
    int n1=mid-low+1,n2=high-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){left[i]=arr[low+i];}
    for(int i=0;i<n2;i++){right[i]=arr[mid+i+1];}
    
    int p1=0,p2=0,k=low;
    while(p1<n1 && p2<n2){
        if(left[p1]<=right[p2]){
            arr[k]=left[p1];k++;p1++;
        }
        else if(left[p1]>right[p2]){
            cout<<left[p1]<<" "<<right[p2]<<endl;
            count+=(n1-p1);
            arr[k]=right[p2];k++;p2++;
        }
    }
    while(p1<n1){
        arr[k]=left[p1];
        k++;p1++;
    }
    while(p2<n2){
        arr[k]=right[p2];
        k++;p2++;
    }
    return count;
}

//Efficient solution
int mergeSort(int arr[],int left,int right){
    int count=0;
    if(right>left){
        int mid=left+(right-left)/2;
        count+=mergeSort(arr,left,mid);
        count+=mergeSort(arr,mid+1,right);
        count+=merge(arr,left,mid,right);
    }
    return count;
}

int main(){
    //vector<int>arr{2,4,1,3,5};
    //cout<<countInversions(arr);
    int arr[]{40,30,20,10};
    cout<<mergeSort(arr,0,3)<<endl;
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}