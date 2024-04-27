#include<iostream>
#include<vector>
using namespace std;

vector<int> printIntersection(int arr1[], int arr2[], int N, int M) 
{ 
    //Your code here
    vector<int>res;
    int i=0,j=0;
    while(i<N && j<M){
        if(arr1[i]<arr2[j]){
            i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }else if(arr1[i]==arr2[j]){
            if(res.empty() || (!res.empty() && res[res.size()-1]!=arr1[i])){res.push_back(arr1[i]);}
            i++;
            j++;
        }
    }
    return res;
}

int main(){
    int arr1[]={1, 2, 2, 3, 4};
    int arr2[]={2, 2, 4, 6, 7, 8};
    auto res=printIntersection(arr1,arr2,5,6);
    for(auto r:res){cout<<r<<" ";}
    return 0;
}