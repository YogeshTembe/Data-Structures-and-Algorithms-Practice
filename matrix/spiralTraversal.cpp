#include<iostream>
#include<vector>
using namespace std;

void spiralTraversal(vector<vector<int>>&arr,int top,int bottom,int left,int right){
    if(left>right || top>bottom){
        return;
    }

    int i=left;
    cout<<"top ";
    while(i<=(right)){
        cout<<arr[top][i]<<" ";
        i++;
    }
    top++;
    
    i=top;
    cout<<"right ";
    while(i<=(bottom)){
        cout<<arr[i][right]<<" ";
        i++;
    }
    right--;
    

    if(top<=bottom){
        i=(right);
        cout<<"bottom ";
        while(i>=left){
            cout<<arr[bottom][i]<<" ";
            i--;
        }
        bottom--;
    }

    if(left<=right){
        i=bottom;
        cout<<"left ";
        while(i>=(top)){
            cout<<arr[i][left]<<" ";
            i--;
        }
        left++;
    }
    
    cout<<endl;
    spiralTraversal(arr,top,bottom,left,right);
}

int main(){
    //vector<vector<int>>arr{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    vector<vector<int>>arr{{1,2,3,4,5}};
    spiralTraversal(arr,0,arr.size()-1,0,arr[0].size()-1);
    return 0;
}