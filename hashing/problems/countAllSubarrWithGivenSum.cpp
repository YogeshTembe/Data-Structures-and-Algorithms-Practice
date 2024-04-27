#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{
    //Your code here
    //Your code here
    int count=0;
    int prefSum=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        prefSum+=arr[i];
        if(prefSum==sum){
            count++;
        }
        if(mp.find(prefSum-sum)!=mp.end()){ // this is done before inserting curr prefsum into map because if sum==0 then it will cause problem if we do this after inserting curr prefsum into array
            count+=mp[prefSum-sum];
        }
        if(mp.find(prefSum)==mp.end()){
            mp.insert({prefSum,1});
        }else{
            mp[prefSum]++;
        }
    }
    return count;
}

int main(){
    int arr[]={18,-48,-31,41,-29,-22,-18,-31,41,5,-16,33,29,32,-15,-20,5,25,39,-2,32,-42,-7,-3,13,22,23,44,10,-46,32,30,-44,3,21,-22,-16,-46,-3,-25,-39,-17,10,40,-34,45,22,21,-28,-36,21,-46,24,-35,-47,-12,-11,27,-18,2,31,16,-18,37,22,6,17,-44,-38,16,33,-27,-50,-7,15,-34,40,40,-11,-37,-46,-39,-33,28,28,-29,18,-33};
    cout<<subArraySum(arr,88,0);
    return 0;
}