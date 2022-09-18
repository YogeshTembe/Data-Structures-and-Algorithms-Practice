#include<iostream>
#include<map>
#include <cmath>
using namespace std;

int majorityElement(int a[],int n){
    int res=0;
    int count=0;
    
    for(int i=1;i<n;i++){
        cout<<a[i]<<endl;
        if(a[i]==a[i-1]){
            count=0;
            for(int j=0;j<n;j++){
                if(a[i]==a[j]){
                    count++;
                }
            }
            cout<<"count-"<<count<<endl;
            if(count >(int(n/2))){
                return i;
            }
        }

    }
    return -1;
}

int majorityElement2(int a[],int n){
    map<int,int>count;
    for(int i=0;i<n;i++){
        if(count.find(a[i])!=count.end()){
            count[a[i]]++;
        }else{
            count[a[i]]=1;
        }
    }
    int ele=-1000;
    for(auto itr = count.begin(); itr != count.end(); ++itr){
        // cout<<itr->second<<endl;
        // cout<<int(n/2)<<endl;
        if(itr->second >= int(n/2)){
            ele=itr->first;
        }
    }

    if(ele!=-1000){
        for(int i=0;i<n;i++){
            if(a[i]==ele){
                return i;
            }
        }
    }
    return -1;
}

//Efficient solution
int majorityElement3(int a[],int n){
    int res=0;
    int count=1;
    //Phase1 -> get the majority element
    for(int i=1;i<n;i++){
        if(a[res]==a[i]){
            count++;
        }else{
            count--;
        }
        if(count==0){
            res=i;
            count=1;
        }
        cout<<a[i]<<" "<<count<<" "<<res<<endl;
    }
    //Phase2 -> check if its a majority element
    int count2=0;
    for(int i=0;i<n;i++){
        if(a[i]==a[res]){
            count2++;
        }
    }
    if(count2<=int(n/2)){
        res=-1;
    }
    return res;
}

int main(){
    //int a[]={3,7,4,7,7,7};
    int a[]={8,8,6,8,4};
    //int a[]={20,30,40,50,50,50,50};
    cout<<majorityElement3(a,5);
    return 0;
}