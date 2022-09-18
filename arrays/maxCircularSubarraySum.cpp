#include<iostream>
using namespace std;

int maximumCircularSubarraySum(int a[],int n){
    int res=a[0];
    int maxEnding=a[0];
    for(int i=1;i<n;i++){
        if((maxEnding+a[i])>a[i]){
            maxEnding=maxEnding+a[i];
        }
        if(a[i]>(maxEnding+a[i])){
            maxEnding=a[i];
        }
        res=(res>maxEnding)?res:maxEnding;
    }
    return res;
}

void leftRotateArray(int a[],int n){
    int temp=a[0];
    for(int i=1;i<n;i++){
        a[i-1]=a[i];
    }
    a[n-1]=temp;
}
//naive solution
int maximumCircularSubarraySum2(int a[],int n){
    int currSum=0;
    int currMax=0;
    int res=a[0];
    for(int i=0;i<n;i++){
        currSum=a[i];
        currMax=a[i];
        for(int j=i;j<n;j++){
            int index=(i+j)%n;
            currSum=currSum+a[index];
            currMax=(currMax>currSum)?currMax:currSum;
        }
        res=(currMax>res)?currMax:res;
    }
    return res;
}

//efficient solution 
int maximumCircularSubarraySum3(int a[],int n){
    int max=0;
    int res=0;
    for(int i=0;i<n;i++){
        res=(res+a[i])>a[i]?(res+a[i]):a[i];
        max=(res>max)?res:max;
    }
    cout<<max<<endl;
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=a[i];
    }
    cout<<totalSum<<endl;
    int min=a[0];
    res=0;
    for(int i=1;i<n-1;i++){
        res=res+a[i];
        min=(res<min)?res:min;
    }
    cout<<min<<endl;
    int temp=totalSum-min;
    return (temp>max)?temp:max;

}

int main(){
    //int a[]={10,5,-5};
    int a[]={5,-2,3,4};
    // int max=0;
    // int sum=0;
    // for(int i=0;i<4;i++){
    //     leftRotateArray(a,4);
    //     //cout<<a[i]<<" ";
    //     sum=maximumCircularSubarraySum(a,4);
    //     cout<<sum<<endl;
    //     if(sum>max){
    //         max=sum;
    //     }
    // }
    // cout<<max<<endl;
    
    //cout<<maximumCircularSubarraySum2(a,4);

    cout<<maximumCircularSubarraySum3(a,4);
    return 0;
}