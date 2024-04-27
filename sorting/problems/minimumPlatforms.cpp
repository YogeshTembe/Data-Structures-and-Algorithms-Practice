#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    vector<pair<int,char>>temp;
    for(int i=0;i<n;i++){
        temp.push_back({arr[i],'a'});
    }
    for(int i=0;i<n;i++){
        temp.push_back({dep[i],'d'});
    }
    sort(temp.begin(),temp.end());
    int maxplatforms=INT_MIN;
    int curr=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i].second=='a'){
            curr++;
        }else{
            curr--;
        }
        if(curr>maxplatforms){maxplatforms=curr;}
    }
    return maxplatforms;
}

int main(){
    // int arr[] = {900, 940, 950, 1100, 1500, 1800};
    // int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int arr[] = {900, 1100, 1235};
    int dep[] = {1000, 1200, 1240};
    cout<<findPlatform(arr,dep,3);
    return 0;
}