#include<iostream>
#include<vector>
using namespace std;

void printSnakePattern(vector<vector<int>>&arr){
    int i=0;
    int j=0;
    while(i<arr.size()){
        if(i%2==0){
            j=0;
            while(j<arr[i].size()){
                cout<<arr[i][j]<<" ";
                j++;
            }
        }else{
            j=arr[i].size()-1;
            while(j>=0){
                cout<<arr[i][j]<<" ";
                j--;
            }
        }
        i++;
    }
    return;
}

int main(){
    vector<vector<int>>arr{{1},{2},{3},{4}};
    printSnakePattern(arr);
    return 0;
}