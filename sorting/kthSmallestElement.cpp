#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int lomutoPartition(int arr[],int l,int h){
    int pivot=arr[h];
    cout<<pivot<<endl;
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    print(arr,h+1);
    return i+1;
}

int hoarePartition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j){
            return j;
        }
        swap(arr[i],arr[j]);
    }
    return 0;
}

void quickSort(int arr[],int l,int h){
    if(l<h){
        int p=hoarePartition(arr,l,h);
        quickSort(arr,l,p);
        quickSort(arr,p+1,h);
    }
}

int kthSmallest(int arr[],int k,int n){
    quickSort(arr,0,n-1);
    return arr[k-1];
}

int kthSmallest2(int arr[],int k,int n){
    int l=0,h=n-1;
    while(l<=n-1 && h>=0){
        int p=lomutoPartition(arr,l,h);
        cout<<p<<endl;
        if(p==k-1){return arr[p];}
        else if(p>(k-1)){
            h=p-1;
        }else{
            l=p+1;
        }
    }
    return -1;
}

int main(){
    int arr[]{5,3,8,1,7};
    // int p=hoarePartition(arr,0,5);
    // cout<<p<<endl;
    // print(arr,5);
    cout<<kthSmallest2(arr,2,5);
    return 0;
}