#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}

int maxGuests(vector<int>arr,vector<int>dep){
    vector<pair<int,int>>guests;
    for(int i=0;i<arr.size();i++){
        guests.push_back(pair<int,int>{arr[i],dep[i]});
    }
    sort(guests.begin(),guests.end(),mycomp);
    int res=0;
    int maxCount=1;
    int count=1;
    for(int i=1;i<guests.size();i++){
        if(guests[i].first<guests[res].second){
            guests[res].first=max(guests[i].first,guests[res].first);
            guests[res].second=min(guests[i].second,guests[res].second);
            count++;
        }else{
            cout<<count<<endl;
            if(count>maxCount){maxCount=count;}
            count=1;
            res++;
            guests[res]=guests[i];
        }
    }
    cout<<count<<endl;
    if(count>maxCount){maxCount=count;}

    for(int i=0;i<=res;i++){
        cout<<guests[i].first<<" "<<guests[i].second<<endl;
    }
    return maxCount;
}

int main(){
    // vector<int>arr{900,940,950,1100,1500,1800};
    // vector<int>dep{910,1120,1130,1200,1900,2000};
    vector<int>arr{800,700,600,500};
    vector<int>dep{840,820,830,530};
    cout<<maxGuests(arr,dep);
    return 0;
}