#include<iostream>
#include<cmath>
using namespace std;

int getMid(int ss,int se){
    return ss+(se-ss)/2;
}

struct node{
    int sum=INT_MIN;
    int prefixsum=INT_MIN;
    int suffixsum=INT_MIN;
    int maxsum=INT_MIN;
};

node tree[4 * 1000];

node merge(node left,node right){
    node res;
    res.sum=left.sum+right.sum;
    res.prefixsum=max(left.prefixsum,left.sum+right.prefixsum);
    res.suffixsum=max(right.suffixsum,left.suffixsum+right.sum);
    res.maxsum=max(res.suffixsum,max(res.prefixsum,max(left.maxsum,max(right.maxsum,left.suffixsum+right.prefixsum))));
    return res;
}

node constructSTHelper(int *arr,int n,int ss,int se,int si){
    if(ss==se){
        tree[si].sum=arr[ss];
        tree[si].prefixsum=arr[ss];
        tree[si].suffixsum=arr[ss];
        tree[si].maxsum=arr[ss];
        return tree[si];
    }
    int mid=getMid(ss,se);
    node left=constructSTHelper(arr,n,ss,mid,2*si+1);
    node right=constructSTHelper(arr,n,mid+1,se,2*si+2);
    tree[si]=merge(left,right);
    return tree[si];
}

void constructST(int *arr,int n){
    int height = (int) (ceil(log2(n)));
    int size = 2 * (int) pow(2, height) - 1;
    constructSTHelper(arr,n,0,n-1,0);
}

void updateHelper(int arr[],int n,int index,int ss,int se,int si,int new_val){
    if(index<ss || index>se){
        return;
    }
    if(index==ss && index==se){
        tree[si].maxsum=new_val;
        tree[si].sum=new_val;
        tree[si].prefixsum=new_val;
        tree[si].suffixsum=new_val;
        return;
    }
    if(se>ss){
        int mid=getMid(ss,se);
        updateHelper(arr,n,index,ss,mid,2*si+1,new_val);
        updateHelper(arr,n,index,mid+1,se,2*si+2,new_val);
        node left=tree[2*si+1];
        node right=tree[2*si+2];
        tree[si]=merge(left,right);
    }
}
// //Function to update a value in input array and segment tree.
void update(int arr[], int arrSize, int index, int value)
{
    // code here
    arr[index-1]=value;
    updateHelper(arr,arrSize,index-1,0,arrSize-1,0,value);
}

node queryHelper(int arr[],int n,int qs,int qe,int ss,int se,int si){
    //cout<<ss<<" "<<se<<endl;
    if(qs>se || qe<ss){//outside
        node empty;
        return empty;
    }
    if(qs<=ss && se<=qe){//inside
        //cout<<si<<" "<<tree[si].maxsum<<endl;
        return tree[si];
    }
    int mid=getMid(ss,se);
    node left=queryHelper(arr,n,qs,qe,ss,mid,2*si+1);
    node right=queryHelper(arr,n,qs,qe,mid+1,se,2*si+2);
    node res;
    if(left.maxsum==INT_MIN){res=right;}
    else if(right.maxsum==INT_MIN){res=left;}
    else{
        res=merge(left,right);
    }
    //cout<<"si end-"<<si<<endl;
    return res;
}

// //Funciton to return the Maximum-Sum in the range.
int query(int arr[], int n, int l, int r) 
{
    // code here
    return queryHelper(arr,n,l-1,r-1,0,n-1,0).maxsum;
}

int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n=8;
    constructST(arr,n);
    cout<<query(arr,n,8,8)<<endl;
    cout<<query(arr,n,1,3)<<endl;
    // int height = (int) (ceil(log2(n)));
    // int size = 2 * (int) pow(2, height) - 1;
    // cout<<"size-"<<size<<endl;
    // for(int i=0;i<size;i++){
    //     cout<<"**"<<tree[i].maxsum<<endl;
    // }
    
    update(arr,n,1,11);
    cout<<query(arr,n,1,3)<<endl;
    return 0;
}