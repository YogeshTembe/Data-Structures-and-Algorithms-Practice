#include<iostream>
using namespace std;

void rearrange(long long *arr, int n) 
{ 
    // Your code here
    // long long rev[n];
    // for(int i=n-1;i>=0;i--){
    //     rev[n-i+1]=arr[i];
    // }
    if(n==1){return;}
    long long res[n];
    int left=0;
    int right=n-1;
    int check=0;
    int j=0;
    while(left<=right){
        if(check==1){
            res[j]=arr[left];
            j++;
            left++;
            check=0;
        }else{
            res[j]=arr[right];
            j++;
            right--;
            check=1;
        }
    }
    if(j<n-1 && check==1){
        res[j]=arr[left];
    }else if(j<n-1 && check==0){
        res[j]=arr[right];
    }
    
    for(int i=0;i<n;i++){
        arr[i]=res[i];
    }
    // cout<<endl;
    return;
}

int main(){
    long long arr[]{12,12,12,111,111};
    rearrange(arr, 5); 
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}