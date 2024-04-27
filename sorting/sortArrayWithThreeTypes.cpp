#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//we are given range with 2 elements 
//all the elements lower than range[0] should be on the left, all the elements higher than the range[1] should be on the right
//all the elements between range[0] n range[1] should be in between
void sortArrayThreeWays(int arr[],int n,pair<int,int>range){
    int l=-1,h=n;
    int res=0;
    while(true){
        do{
            l++;
        }while(arr[l]<range.first);
        do{
            h--;
        }while(arr[h]>=range.first);
        if(l>=h){res=l;break;}
        swap(arr[l],arr[h]);
    }
    //cout<<res<<endl;
    print(arr,7);
    l=res-1;h=n;
    while(true){
        do{
            l++;
        }while(arr[l]<=range.second);
        do{
            h--;
        }while(arr[h]>range.second);
        if(l>=h){return;}
        //cout<<l<<" "<<h<<endl;
        swap(arr[l],arr[h]);
    }
    return;
}

int main(){
    int arr[]{10,5,6,3,20,9,40};
    pair<int,int>range{5,10};
    sortArrayThreeWays(arr,7,range);
    print(arr,7);
    return 0;
}