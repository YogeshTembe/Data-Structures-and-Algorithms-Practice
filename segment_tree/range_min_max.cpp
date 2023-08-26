#include<iostream>
#include<cmath>
using namespace std;
typedef pair<int, int> PII;

int getMid(int s, int e) {  return s + (e -s)/2;  }

void constructSTUtil(int *arr, int ss, int se, PII *st, int si)
{
    if (ss == se)
    {
        st[si].first = st[si].second = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si*2+1);
    constructSTUtil(arr, mid+1, se, st, si*2+2);
    
    st[si].first = min(st[si*2+1].first, st[si*2+2].first);
    st[si].second = max(st[si*2+1].second, st[si*2+2].second);
    
    return;
}

PII *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    PII *st = new PII[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

// arr : given array arr
// st : segment tree of the given array arr
// n :  size of arr array
// qs and qe : index range to find Min and Max value between these indexes.
// PII :  return pair denoting min,max respectively.
// index : given index to update with new_val
PII getMinMax2(PII *st,int *arr,int n, int qs,int qe,int ss,int se,int si){
    if(ss>qe || se<qs){//outside
        return {INT_MAX,INT_MIN};
    }
    if(ss>=qs && se<=qe){
        return st[si];
    }
    int mid=getMid(ss,se);
    PII temp1=getMinMax2(st,arr,n,qs,qe,ss,mid,2*si+1);
    PII temp2=getMinMax2(st,arr,n,qs,qe,mid+1,se,2*si+2);
    PII res={min(temp1.first,temp2.first),max(temp1.second,temp2.second)};
    return res;
}

PII getMinMax(PII *st, int *arr, int n, int qs, int qe)
{
    //add code here 
    return getMinMax2(st,arr,n,qs,qe,0,n-1,0);
}

void updateValue2(PII* st, int n, int ss, int se, int si,int index, int new_val){
    if(index>se || index<ss){
        return;
    }
    if(index==ss && index==se){
        st[si].first=new_val;
        st[si].second=new_val;
        return;
    }
    //this logic is same as constructing a segment tree
    if(se>ss){
        int mid=getMid(ss,se);
        updateValue2(st,n,ss,mid,2*si+1,index,new_val);
        updateValue2(st,n,mid+1,se,2*si+2,index,new_val);
        st[si].first=min(st[2*si+1].first,st[2*si+2].first);
        st[si].second=max(st[2*si+1].second,st[2*si+2].second);
    }
}

void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
   // add code here
   updateValue2(st,n,0,n-1,0,index,new_val);

}

int main(){
    int arr[]={11,3,7,5,9,1};
    int n=6;
    PII* st=constructST(arr,n);
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    // for(int i=0;i<max_size;i++){
    //     cout<<st[i].first<<" "<<st[i].second<<endl;
    // }
    // cout<<"--------------"<<endl;
    PII res=getMinMax(st,arr,n,0,2);
    cout<<res.first<<" "<<res.second<<endl;
    updateValue(arr,st,n,3,17);
    PII res2=getMinMax(st,arr,n,0,5);
    cout<<res2.first<<" "<<res2.second<<endl;
    return 0;
}