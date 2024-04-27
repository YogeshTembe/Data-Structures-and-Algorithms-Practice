#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline
    Job(int i,int d,int p):id(i),dead(d),profit(p){} 
};

bool comp(Job a,Job b){
    return a.profit>b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr,arr+n,comp);
    vector<int>time(n,0);
    int count=0;
    int pro=0;
    for(int i=0;i<n;i++){
        //cout<<arr[i].dead<<" "<<time[arr[i].dead-1]<<endl;
        int j=arr[i].dead-1;
        while(j>=0){//include it
            if(time[j]==0){
                time[j]=arr[i].id;
                count++;
                pro+=arr[i].profit;
                break;
            }
            j--;
        }
    }
    return {count,pro};
} 

int main(){
    //(Jobid, Deadline, Profit)
    //{(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
    Job j1=Job(1,4,20);
    Job j2=Job(2,1,10);
    Job j3=Job(3,1,40);
    Job j4=Job(4,1,30);
    Job arr[]{j1,j2,j3,j4};
    auto res=JobScheduling(arr,4);
    cout<<res[0]<<" "<<res[1]<<endl;
    
    //1 2 100, 2 1 19, 3 2 27, 4 1 25, 5 1 15
    // Job j1=Job(1,2,100);
    // Job j2=Job(2,1,19);
    // Job j3=Job(3,2,27);
    // Job j4=Job(4,1,25);
    // Job j5=Job(5,1,15);
    // Job arr[]{j1,j2,j3,j4,j5};
    // auto res=JobScheduling(arr,5);
    // cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}