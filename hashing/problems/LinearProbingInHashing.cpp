#include<iostream>
#include<vector>
using namespace std;

/*
Linear probing is a collision handling technique in hashing. Linear probing says that whenever a collision occurs, search for the immediate next position.
Given an array of integers and a hash table size. Fill the array elements into a hash table using Linear Probing to handle collisions. Duplicate elements must be mapped to the same position in the hash table while colliding elements must be mapped to the [(value+1)%hashSise]
*/

vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
{
    //Your code here
    vector<int> hashTable(hashSize,-1);
    for(int i=0;i<sizeOfArray;i++){
        int index=arr[i]%hashSize;
        if(hashTable[index]==-1 || hashTable[index]==arr[i]){
            hashTable[index]=arr[i];
        }else{
            int ptr=(index+1)%hashSize;
            while(ptr!=index){
                if(hashTable[ptr]==-1 || hashTable[ptr]==arr[i]){
                    hashTable[ptr]=arr[i];
                    break;
                }
                ptr=(ptr+1)%hashSize;
            }
        }
    }
    return hashTable;
}

int main(){
    int hashSize = 10;
    int sizeOfArray = 4;
    int Array[] = {4,14,24,44};
    auto res=linearProbing(hashSize,Array,sizeOfArray);
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}