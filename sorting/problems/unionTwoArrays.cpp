#include<iostream>
#include<vector>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    //return vector with correct order of elements
    int i=0,j=0;
    vector<int>res;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            if(res.empty() || (!res.empty() && res[res.size()-1]!=arr1[i])){res.push_back(arr1[i]);}
            i++;
        }else if(arr1[i]>arr2[j]){
            if(res.empty() || (!res.empty() && res[res.size()-1]!=arr2[j])){res.push_back(arr2[j]);}
            j++;
        }else{
            if(res.empty() || (!res.empty() && res[res.size()-1]!=arr1[i])){res.push_back(arr1[i]);}
            i++;
            j++;
        }
    }
    while(i<n){
        if(res.empty() || (!res.empty() && res[res.size()-1]!=arr1[i])){res.push_back(arr1[i]);}
        i++;
    }
    while(j<m){
        if(res.empty() || (!res.empty() && res[res.size()-1]!=arr2[j])){res.push_back(arr2[j]);}
        j++;
    }
    return res;
}

int main(){
    /*
    17 2
1 4 18 19 19 28 29 32 35 35 39 39 44 49 49 50 50
8 34*/
    int arr1[]={1,4,18,19,19,28,29,32,35,35,39,39,44,49,49,50,50};
    int arr2[]={8,34};
    auto res=findUnion(arr1,arr2,17,2);
    for(auto r:res){cout<<r<<" ";}
    return 0;
}