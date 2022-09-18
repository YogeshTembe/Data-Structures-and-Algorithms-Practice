#include<iostream>
using namespace std;

int maxDiff(int a[],int n){
    int diff=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if((a[i]-a[j])>diff){
                diff=a[i]-a[j];
            }
        }
    }
    return diff;
}

//efficient solution
int maxDiff2(int a[],int n){
    int minVal=a[0];
    int diff=a[1]-a[0];
    for(int i=1;i<n;i++){
        if((a[i]-minVal)>diff){
            diff=a[i]-minVal;
        }
        if(a[i]<minVal){minVal=a[i];}
    }
    return diff;
}

int main(){
    int a[]={2,3,10,6,4,8,1};
    cout<<maxDiff2(a,7);
    return 0;
}