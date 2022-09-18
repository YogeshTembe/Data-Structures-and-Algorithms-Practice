#include<iostream>
#include<cmath>
using namespace std;

//this solution fails for few cases
bool checkRotatedAndSorted(int arr[], int num){
    // Your code here
    // int inc=0;
    // int dec=0;
    // for(int i=1;i<num;i++){
    //     //cout<<arr[i]<<" "<<arr[i-1]<<endl;
    //     if(arr[i]>arr[i-1]){inc++;}
    //     if(arr[i]<arr[i-1]){dec++;}
    // }
    // //cout<<inc<<" "<<dec<<endl;
    // if(arr[0]>arr[num-1]){inc++;}
    // if(arr[0]<arr[num-1]){dec++;}
    // return (abs(inc-dec)==1);

    if(num==1){return false;}
    if(num==2){return arr[0]!=arr[1];}

    int minIndex=0;
    int maxIndex=0;

    for(int i=1;i<num;i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;
        }
        if(arr[i]>arr[maxIndex]){
            maxIndex=i;
        }
    }
    cout<<maxIndex<<" "<<minIndex<<endl;
    return abs(maxIndex-minIndex)==1;
}

//Efficient solution, time complexity-O(N) and space Complexity-O(1)
bool checkRotatedAndSorted2(int arr[], int num){
    if(num==1){return false;}
    if(num==2){return arr[0]!=arr[1];}

    int minIndex=0;
    int maxIndex=0;
    for(int i=1;i<num;i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;
        }
        if(arr[i]>arr[maxIndex]){
            maxIndex=i;
        }
    }

    //if(minIndex==0 || minIndex==num-1){return false;}
    //cout<<minIndex<<" "<<maxIndex<<endl;
    if(minIndex>maxIndex){
        for(int i=minIndex;i<num-1;i++){
            cout<<i<<" "<<arr[i]<<" "<<arr[i+1]<<endl;
            if(arr[i]>arr[i+1]){return false;}
        }
        //cout<<"////"<<endl;
        for(int i=0;i<minIndex-1;i++){
            //cout<<i<<" "<<arr[i]<<" "<<arr[i+1]<<endl;
            if(arr[i]>arr[i+1]){return false;}
        }
        if(arr[0]<arr[num-1]){return false;}
    }
    else if(maxIndex>minIndex){
        for(int i=maxIndex;i<num-1;i++){
            //cout<<i<<arr[i]<<" "<<arr[i+1]<<endl;
            if(arr[i]<arr[i+1]){return false;}
        }

        for(int i=0;i<maxIndex-1;i++){
            //cout<<i<<arr[i]<<" "<<arr[i+1]<<endl;
            if(arr[i]<arr[i+1]){return false;}
        }
        if(arr[0]>arr[num-1]){return false;}
    }
    return true;
}

int main(){
    //int a[]{2,1,4,3};
    //int a[]{20,10,14};
    int a[]{1,2,3};
    //int a[]{30,20,10,50,25};
    //int a[]{3,4,1,2};
    cout<<checkRotatedAndSorted2(a,5);
    return 0;
}