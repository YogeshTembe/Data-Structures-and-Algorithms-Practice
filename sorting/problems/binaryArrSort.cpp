#include<iostream>
using namespace std;

void binSort(int A[], int N)
{
    //Your code here
    
    /**************
    * No need to print the array
    * ************/
    int i=-1;
    int j=N;
    while(true){
        do{
            i++;
        }while(A[i]==0);
        do{
            j--;
        }while(A[j]==1);
        if(i>=j){
            return;
        }
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
}

int main(){
    int arr[5]={1,0,1,1,0};
    binSort(arr,5);
    for(auto r:arr){
        cout<<r<<" ";
    }
    return 0;
}