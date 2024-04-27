#include<iostream>
#include<vector>
#include<map>
using namespace std;

void bucketSort(vector<int>arr,int buckets){
    int mx=0;
    for(int i=0;i<arr.size();i++){
        mx=max(mx,arr[i]);
    }
    map<int,vector<int>>buc;
    int limit=int(mx/float(buckets))+1;
    cout<<limit<<endl;
    for(int i=1;i<=buckets;i++){
        buc[limit*i]=vector<int>{0};
    }
    int start=limit;
    for(int i=0;i<arr.size();i++){
        bool notdone=true;
        start=limit;
        cout<<"l-"<<limit<<endl;
        while(notdone){
            if(arr[i]<start && arr[i]>(start+limit)){
                cout<<"h-"<<start<<endl;
                buc[start].push_back(arr[i]);
                notdone=false;
            }else{
                start=start+limit;
            }
        }
    }

    for(auto it=buc.begin();it!=buc.end();it++){
        cout<<it->first<<endl;
        for(auto r:it->second){
            cout<<r<<" ";
        }
        cout<<endl;
    }

}

int main(){
    vector<int>arr{20,80,10,85,75,99,18};
    bucketSort(arr,5);
    return 0;
}