#include<iostream>
#include<vector>
using namespace std;

void sortArr(vector<int>&a,vector<int>&b){
    int i=0;
    int j=0;
    vector<int>temp;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            temp.push_back(a[i]);
            i++;
        }else if(a[i]>b[j]){
            temp.push_back(b[j]);
            j++;
        }else if(a[i]==b[j]){
            temp.push_back(a[i]);
            temp.push_back(b[j]);
            i++;
            j++;
        }
    }
    while(i<a.size()){
        temp.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        temp.push_back(b[j]);
        j++;
    }
    a.clear();
    for(auto i:temp){
        a.push_back(i);
    }
}

int medianOfRowSortedMat(vector<vector<int>>arr){
    vector<int>temp=arr[0];
    int i=1;
    while(i<arr.size()){
        sortArr(temp,arr[i]);
        i++;
    }

    for(auto a:temp){
        cout<<a<<" ";
    }
    cout<<endl;
    return temp[temp.size()/2];
}

int main(){
    vector<vector<int>>arr{{1,10,20},{15,25,35},{5,30,40}};
    cout<<medianOfRowSortedMat(arr);
    return 0;
}