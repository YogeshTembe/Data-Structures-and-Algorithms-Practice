#include<iostream>
#include<vector>
using namespace std;

pair<int,int> searchInSortedMatrix(vector<vector<int>>&arr,int x){
    int r=0;
    int c=arr[0].size()-1;
    while(r>=0 && c<arr[0].size()){
        cout<<arr[r][c]<<endl;
        if(arr[r][c]==x){
            return pair<int,int>{r,c};
        }
        else if(arr[r][c]<x){
            //cout<<"here1"<<endl;
            r++;
        }
        else if(arr[r][c]>x){
            //cout<<"here"<<endl;
            c--;
        } 
    }
    return pair<int,int>{-1,-1};
}

int main(){
    vector<vector<int>>arr{{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    auto res=searchInSortedMatrix(arr,29);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}