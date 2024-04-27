#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>res){
    for(auto r:res){
        cout<<r<<" ";
    }
    cout<<endl;
}

void naivePartition(int arr[],int n,int p){
    vector<int>left,right;
    for(int i=0;i<n;i++){
        if(arr[i]<arr[p]){left.push_back(arr[i]);}
        else if(arr[i]>arr[p]){right.push_back(arr[i]);}
    }
    //print(left);print(right);
    int i=0;
    while(i<left.size()){
        arr[i]=left[i];
        i++;
    }
    arr[i]=arr[p];
    i++;
    // for(int i=0;i<6;i++){
    //     cout<<arr[i]<<" ";
    // }
    while((i)<(left.size()+right.size()+1)){
        cout<<i<<endl;
        arr[i]=right[i-left.size()-1];
        i++;
    }
}

//Ideal solution
//Here we consider that the pivot element around which we want to partition is always end element
//Time complexity = o(n)
//Auxiliary space = o(n)
void naivePartition2(int arr[],int l,int h,int p){
    int temp[h-l+1];
    int index=0;
    for(int i=l;i<=h;i++){
        if(arr[i]<=arr[p]){
            temp[index]=arr[i];
            index++;
        }
    }

    for(int i=l;i<=h;i++){
        if(arr[i]>arr[p]){
            temp[index]=arr[i];
            index++;
        }
    }

    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
}

int main(){
    int arr[]{3,8,6,12,10,7};
    // naivePartition(arr,6,5);
    naivePartition2(arr,0,5,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}