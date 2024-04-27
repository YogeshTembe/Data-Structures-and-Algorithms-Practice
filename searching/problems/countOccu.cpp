#include<iostream>
#include<unordered_map>
using namespace std;

void print(unordered_map<int,int>num){
    for(auto itr=num.begin();itr!=num.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    return;
}

int countOccurence(int arr[], int n, int k) {
    // Your code here
    int c=n/k;
    unordered_map<int,int>num;
    for(int i=0;i<n;i++){
        if(num.find(arr[i])!=num.end()){
            num[arr[i]]++;
        }else{
            num[arr[i]]=1;
        }
    }
    //print(num);
    int count=0;
    for(auto itr=num.begin();itr!=num.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
        if(itr->second > c){count++;}
    }
    return count;
}

int main(){
    int arr[]{3,1,2,2,1,2,3,3};
    cout<<countOccurence(arr,8,4);
    return 0;
}