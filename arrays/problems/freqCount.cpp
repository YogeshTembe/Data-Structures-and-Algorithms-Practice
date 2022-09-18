#include<iostream>
#include<vector>
#include<map>
using namespace std;

void frequencyCount(vector<int>& arr,int N, int P)
{ 
    // code here
    vector<int>freq;
    for(int i=0;i<N;i++){
        freq.push_back(0);
    }
    for(int i=0;i<N;i++){
        if((arr[i]-1)<N){
            freq[arr[i]-1]+=1;
        }
    }
    arr=freq;
    return;
}

void frequencyCount2(vector<int>& arr,int N, int P){

}

int main(){
    // vector<int>arr{2, 3, 2, 3, 5};
    // frequencyCount(arr,5,5);
    vector<int>arr{3,3,3,3};
    frequencyCount(arr,4,3);
    // 10
    // 20 7 14 10 10 9 15 4 19 13
    // 40000
    // vector<int>arr{20,7,14,10,10,9,15,4,19,13};
    // frequencyCount(arr,10,40000);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}