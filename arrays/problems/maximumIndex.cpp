#include<iostream>
using namespace std;
//time limit exceeded error 
int maxIndexDiff(int A[], int N) 
{ 
    // Your code here
    if(N==1){return 0;}
    int max=-1;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(A[i]<=A[j] && (j-i)>max){
                max=j-i;
            }
        }
    }
    return max;
}

void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//efficient solution
//time complexity-O(N) space complexity-O(N)
int maxIndexDiff2(int A[],int N){
    //to store all the mins and maxs
    int arr1[N],arr2[N];
    //get mins
    arr1[0]=A[0];
    for(int i=1;i<N;i++){
        arr1[i]=(arr1[i-1]<A[i])?arr1[i-1]:A[i];
    }
    //printArray(arr1,N);
    //get maxs
    arr2[N-1]=A[N-1];
    for(int i=N-2;i>=0;i--){
        arr2[i]=(arr2[i+1]>A[i])?arr2[i+1]:A[i];
    }
    //printArray(arr2,N);
    int i=0;
    int j=0;
    int max=-1;
    while(i<N && j<N){
        if(arr1[i]<=arr2[j]){
            max=(j-i)>max?(j-i):max;
            j++;
        }else{
            i++;
        }
    }
    return max;
}

int main(){
    int a[]{34, 8, 10, 3, 2, 80, 30, 33, 1};
    cout<<maxIndexDiff2(a,9);
    return 0;
}