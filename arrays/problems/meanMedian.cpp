#include<iostream>
using namespace std;

int median(int A[],int N)
{
    //If median is in fraction then convert it to integer and return
    int mid=0;
    if(N%2==0){
        //cout<<A[int(N/2)-1]<<" "<<A[int(N/2)]<<endl;
        return int((A[int(N/2)]+A[int(N/2)-1])/2);
    }else{
        mid=N/2;
        return A[mid];
    }
}
//Function to find mean of the array elements.
int mean(int A[],int N)
{
    //your code here
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    return int(sum/N);
}

int main(){
    //int a[]{1,2,5,19,28};
    int a[]{2, 3, 4, 8};
    cout<<mean(a,4)<<endl;
    cout<<median(a,4);
    return 0;
}