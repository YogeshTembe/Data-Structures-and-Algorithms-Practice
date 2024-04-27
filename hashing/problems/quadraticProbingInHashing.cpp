#include<iostream>
#include<vector>
using namespace std;

void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
{
    //Your code here
    for(int i=0;i<hashSize;i++){
        hash.push_back(-1);
    }
    for(int i=0;i<N;i++){
        int index=arr[i]%hashSize;
        if(hash[index]==-1 || hash[index]==arr[i]){
            hash[index]=arr[i];
        }else{
            int j=1;
            int ptr=(arr[i]+j*j)%hashSize;
            while(ptr!=index){
                if(hash[ptr]==-1 || hash[ptr]==arr[i]){
                    hash[ptr]=arr[i];
                    break;
                }
                j++;
                ptr=(arr[i]+j*j)%hashSize;
            }
        }
    }
}

int main(){
    return 0;
}
