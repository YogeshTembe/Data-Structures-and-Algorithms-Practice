#include<iostream>
using namespace std;

bool subarrayWithSum(int a[],int n,int sum){
    int curr=0;
    for(int i=0;i<n;i++){
        curr=0;
        for(int j=i;j<n;j++){
            curr+=a[j];
            if(curr==sum){return true;}
        }
    }
    return false;
}

//Efficient solution
bool subarrayWithSum2(int a[],int n,int sum){
    int start=0;
    int end=0;
    int curr=0;
    while(curr<sum && end<n){
        curr=curr+a[end];
        end++;
    }
    cout<<curr<<endl;
    while(start<=end){
        if(curr>sum){
            curr=curr-a[start];
        }
        if(curr==sum){
            return true;
        }
        start++;
    }
    return false;
}



int main(){
    int a[]={1,4,20,3,10,5};
    //int a[]={1,4,0,0,3,10,5};
    //int a[]={2,4};
    if(subarrayWithSum2(a,6,33)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no";
    }
    return 0;
}