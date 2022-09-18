#include<iostream>
using namespace std;

bool findInArray(int arr[],int n, int ele){
    bool found=false;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){return true;}
    }
    return false;
}

int missingNumber(int arr[], int n) 
{ 
    // Your code here
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>=0 && arr[i]<min){
            min=arr[i];
        }
        if(arr[0]>=0 && arr[i]>max){
            max=arr[i];
        }
    }
    for(int i=min;i<max;i++){
        if(!findInArray(arr,n,i)){
            return i;
        }
    }
    return max+1;
} 

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Efficient solution, to solve this problem in O(n) time and O(1) space
//we can use the array as a hashmap
//we use array indexes
//https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
int missingNumber2(int arr[],int n){
    //we need to ignore 0 and all negative numbers so seperate them in an array
    int temp=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=0){
            temp=arr[count];
            arr[count]=arr[i];
            arr[i]=temp;
            count++;
        }
    }
    //now we have all the positive numbers at the end of array
    //use the array as hashmap and make arr[i]th element negative
    for(int i=count;i<n;i++){
        if((arr[i]-1)<n && (arr[count+arr[i]-1])>0){
            arr[count+arr[i]-1]=-arr[count+arr[i]-1];
        }
    }

    //now check which element among the positives is still positive
    for(int i=count;i<n;i++){
        if(arr[i]>0){
            return i-count+1;
        }
    }
    printArray(arr,n);
    return n-count+1;
}

int main(){
    int arr[]{0,-10,1,3,-20};
    cout<<missingNumber2(arr,5);
    return 0;
}