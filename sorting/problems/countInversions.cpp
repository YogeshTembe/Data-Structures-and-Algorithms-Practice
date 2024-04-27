#include<iostream>
#include<vector>
using namespace std;

long long merge(long long arr[],long long left,long long right,long long mid){
    //cout<<"merge with-"<<left<<" "<<right<<" "<<mid<<endl;
    long long n1=mid-left+1;
    long long n2=right-mid;
    vector<long long>leftarr;
    vector<long long>rightarr;
    for(int i=0;i<n1;i++){
        //cout<<"l-"<<arr[left+i]<<" ";
        leftarr.push_back(arr[left+i]);
    }
    cout<<endl;
    for(int i=0;i<n2;i++){
        //cout<<"r-"<<arr[mid+1+i]<<" ";
        rightarr.push_back(arr[mid+1+i]);
    }
    cout<<endl;
    long long i=0,j=0,k=left;
    long long res=0;
    while(i<n1 && j<n2){
        if(leftarr[i]<=rightarr[j]){
            arr[k]=leftarr[i];
            i++;
            k++;
        }else{
            //cout<<"here-"<<leftarr[i]<<" "<<rightarr[j]<<" "<<(n1-i)<<endl;
            res=res+(n1-i);
            arr[k]=rightarr[j];
            j++;
            k++;
        }
    }
    while(i<n1){arr[k]=leftarr[i];i++;k++;}
    while(j<n2){arr[k]=rightarr[j];j++;k++;}
    return res;
}

long long mergeSort(long long arr[],long long l,long long r){
    long long res=0;
    if(r>l){
        //cout<<l<<" "<<r<<endl;
        long long m=l+(r-l)/2;
        //cout<<"mid-"<<m<<endl;
        res=res+mergeSort(arr,l,m);
        res=res+mergeSort(arr,m+1,r);
        res=res+merge(arr,l,r,m);
    }
    return res;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr,0,N-1);

}

int main(){
    long long arr[]={2, 4, 1, 3, 5};
    cout<<inversionCount(arr,5)<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}