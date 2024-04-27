#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
    // Your code here
    vector<pair<int,int>>tasks;
    for(int i=0;i<start.size();i++){
        tasks.push_back({start[i],end[i]});
    }
    sort(tasks.begin(),tasks.end(),comp);
    int prev=0;
    int res=1;
    for(int curr=1;curr<tasks.size();curr++){
        if(tasks[curr].first>=tasks[prev].second){
            res++;
            prev=curr;
        }
    }
    return res;
}

int main(){
    // vector<int>start{7,6,2,7,3};
    // vector<int>end{10,6,10,9,5};
    // cout<<activitySelection(start,end,5);
    vector<int>start{1,3,2,5};
    vector<int>end{2,4,3,6};
    cout<<activitySelection(start,end,4);
    return 0;
}