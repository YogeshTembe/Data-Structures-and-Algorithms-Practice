#include<iostream>
#include<vector>
using namespace std;

void boundaryTraversal(vector<vector<int>>arr){
    int r=arr.size();
    int c=arr[0].size();
    int i=0;
    while(i<c){
        cout<<arr[0][i]<<" ";
        i++;
    }
    i=1;
    while(i<r){
        cout<<arr[i][c-1]<<" ";
        i++;
    }
    i=c-2;
    //cout<<i<<endl;
    while(i>=0 && r>1){
        cout<<arr[r-1][i]<<" ";
        i--;
    }
    i=r-2;
    //cout<<r<<" "<<i<<endl;
    while(i>0 && c>1){
        cout<<arr[i][0]<<" ";
        i--;
    }
    return;
}

int main(){
    //vector<vector<int>>arr{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    //vector<vector<int>>arr{{1,2,3,4}};
    vector<vector<int>>arr{{1},{2},{3},{4}};
    //vector<vector<int>>arr{{1,2},{3,4},{5,6}};
    boundaryTraversal(arr);
    return 0;
}