#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int,int>>meetings;
    for(int i=0;i<n;i++){
        meetings.push_back({start[i],end[i]});
    }
    sort(meetings.begin(),meetings.end(),comp);
    int prev=0;
    int res=1;
    for(int curr=1;curr<n;curr++){
        if(meetings[curr].first>meetings[prev].second){
            res++;
            prev=curr;
        }
    }
    return res;
}

int main(){
    int start[]{1,3,0,5,8,5};
    int end[]{2,4,6,7,9,9};
    cout<<maxMeetings(start,end,6);
    return 0;
}