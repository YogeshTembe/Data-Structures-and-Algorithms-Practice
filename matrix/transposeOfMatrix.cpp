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

int main(){
    vector<vector<int>>arr{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    transposeOfMatrix(arr);
    for(auto a:arr){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}