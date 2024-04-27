#include<iostream>
#include<vector>
using namespace std;

void transposeOfMatrix(vector<vector<int>>&arr){
    int c=0;
    for(int i=0;i<arr.size();i++){
        for(int j=c;j<arr.size();j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
        c++;
    }
    return;
}

void rotate90Degree(vector<vector<int>>&arr){
    transposeOfMatrix(arr);
    for(int i=0;i<arr.size()/2;i++){
        for(int j=0;j<arr.size();j++){
            int temp=arr[i][j];
            arr[i][j]=arr[arr.size()-1-i][j];
            arr[arr.size()-1-i][j]=temp;
        }
    }
    return;
}

int main(){
    vector<vector<int>>arr{{1,2,3},{4,5,6},{7,8,9}};
    rotate90Degree(arr);
    for(auto a:arr){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}