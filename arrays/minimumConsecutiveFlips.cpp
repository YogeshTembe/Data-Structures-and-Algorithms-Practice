#include<iostream>
#include<vector>
using namespace std;

void print(vector<pair<int,int>>grp){
    for(int i=0;i<grp.size();i++){
        cout<<"From "<<grp[i].first<<" to "<<grp[i].second<<endl;
    }
}

void minimumConsecutiveFlips(int a[],int n){
    vector<pair<int,int>>ogrp;
    vector<pair<int,int>>ngrp;

    pair<int,int> opair;
    pair<int,int>npair;

    for(int i=1;i<n;i++){
        if(a[i]==0 && a[i-1]==1){
            opair.first=i;
            npair.second=i-1;
            ngrp.push_back(npair);
        }
        if(a[i]==1 && a[i-1]==0){
            opair.second=i-1;
            npair.first=i;
            ogrp.push_back(opair);
        }
    }
    if(a[n-1]==1){
        npair.second=n-1;
        ngrp.push_back(npair);
    }
    if(a[n-1]==0){
        opair.second=n-1;
        ogrp.push_back(opair);
    }

    for(int i=0;i<ogrp.size();i++){
        cout<<ogrp[i].first<<" "<<ogrp[i].second<<endl;
    }
    for(int i=0;i<ngrp.size();i++){
        cout<<ngrp[i].first<<" "<<ngrp[i].second<<endl;
    }
    
    if(ogrp.size()<=ngrp.size()){
        print(ogrp);
    }else{
        print(ngrp);
    }
}

//Efficient solution
void minimumConsecutiveFlips2(int a[],int n){
    int bitToFlip=-1;
    if(a[0]==0){
        bitToFlip=1;
    }
    else{
        bitToFlip=0;
    }
    for(int i=1;i<n;i++){
        if(a[i]==bitToFlip && a[i-1]!=bitToFlip){
            cout<<"From "<<i;
        }
        if(a[i]!=bitToFlip && a[i-1]==bitToFlip){
            cout<<" to "<<i-1<<endl;
        }
    }
}

int main(){
    //int a[]={1,0,0,0,1,0,0,1,1,1,1};
    //int a[]={0,1};
    int a[]={0,1};
    minimumConsecutiveFlips2(a,3);
    return 0;
}