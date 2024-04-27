#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Naive solution
//Time complexity = O(n3)
vector<pair<int,int>> mergeOverlappingIntervals(vector<pair<int,int>>intervals){
    int i=0;
    int j=0;
    vector<pair<int,int>>res;
    //To get the overlapping intervals
    while(i<intervals.size()){
        j=i+1;
        //cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
        while(j<intervals.size()){
            //cout<<intervals[j].first<<"-"<<intervals[j].second<<endl;
            if(intervals[j].first!=-1){
                int minFirst=min(intervals[i].first,intervals[j].first);
                if((intervals[i].first>=intervals[j].first && intervals[i].first>=intervals[j].first && intervals[i].first<=intervals[j].second)
                ||(intervals[i].first<intervals[j].first && intervals[j].first>=intervals[i].first && intervals[j].first<=intervals[i].second))
                {
                    res.push_back(pair<int,int>{minFirst,max(intervals[i].second,intervals[j].second)});
                    intervals[j]=pair<int,int>{minFirst,max(intervals[i].second,intervals[j].second)};
                    intervals[j]=pair<int,int>{-1,-1};
                    intervals[i]=pair<int,int>{-1,-1};
                    //cout<<"here-"<<minFirst<<" "<<max(intervals[i].second,intervals[j].second);
                }
                // else{
                //     res.push_back(intervals[i]);
                //     res.push_back(intervals[j]);
                //     intervals[j]=pair<int,int>{-1,-1};
                // }
            }
            j++;
        }
        i++;
    }

    //To get all the non-overlapping intervals
    i=0;
    while(i<intervals.size()){
        if(intervals[i].first!=-1){
            res.push_back(intervals[i]);
        }
        i++;
    }
    return res;
}

//My solution
vector<pair<int,int>> mergeOverlappingIntervals2(vector<pair<int,int>>intervals){
    vector<int>bucket(30,0);
    vector<pair<int,int>>res;
    for(int i=0;i<intervals.size();i++){
        for(int j=intervals[i].first;j<=intervals[i].second;j++){
            bucket[j]+=1;
        }
    }

    for(int i=0;i<bucket.size()-1;i++){
        cout<<bucket[i]<<" ";
    }
    cout<<endl;
    int start=0;
    int i=0;
    while(i<bucket.size()){
        if(bucket[i]==1 && bucket[i+1]!=1){
            start=i;
            i++;
            while(bucket[i]!=1){
                i++;
            }
            res.push_back(pair<int,int>{start,i});
        }

        else if(bucket[i]==1 && bucket[i]==bucket[i+1]){
            start=i;
            while(bucket[i]==1){
                i++;
            }
            res.push_back(pair<int,int>{start,i-1});
        }
        i++;
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return res;
}

bool mycomp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
//Efficient solution
//Time complexity = O(nlogn)
//O(nlogn) because we need to sort the intervals based on startTime
void mergeOverlappingIntervals3(vector<pair<int,int>>intervals){
    sort(intervals.begin(),intervals.end(),mycomp);
    int res=0;
    for(int i=1;i<intervals.size();i++){
        if(intervals[res].second>=intervals[i].first){
            intervals[res].first=min(intervals[i].first,intervals[res].first);
            intervals[res].second=max(intervals[i].second,intervals[i].second);
        }
        else{
            res++;
            intervals[res]=intervals[i];
        }
    }
    
    for(int i=0;i<=res;i++){
        cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
    }
    return;
}


int main(){
    
    vector<pair<int,int>>intervals{{1,3},{2,4},{5,7},{6,8},{9,10}};
    //vector<pair<int,int>>intervals{{7,9},{6,10},{4,5},{1,3},{2,4}};
    // auto res=mergeOverlappingIntervals(intervals);
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i].first<<" "<<res[i].second<<endl;
    // }
    mergeOverlappingIntervals3(intervals);
    return 0;
}