#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(a[i]);
        }
        int res=0;
        for(int i=0;i<m;i++){
            auto it=s.find(b[i]);
            if(it!=s.end()){
                res++;
                s.erase(it);
            }
        }
        return res;
    }

int intersectionOfArr(vector<int>a,vector<int>b){
    unordered_map<int,int>freq;
    for(int i=0;i<a.size();i++){
        freq[a[i]]++;
    }
    int res=0;
    for(int i=0;i<b.size();i++){
        if(freq[b[i]]>0){
            cout<<b[i]<<" "<<freq[b[i]]<<endl;
            res++;
            freq[b[i]]=-1;
        }
    }
    return res;
}

int main(){
    vector<int>a{10,15,20,15,30,30,5};
    vector<int>b{30,5,30,80};
    cout<<intersectionOfArr(a,b);
    return 0;
}