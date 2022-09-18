#include <iostream>
#include <map>
using namespace std;

int maxAppearingElement(int l[],int r[],int n){
    map<int,int>nums;
    int lmin=0;
    int rmax=0;
    for(int i=0;i<n;i++){
        if(r[i]>rmax){
            rmax=r[i];
        }
        if(lmin<l[i]){
            lmin=l[i];
        }
    }

    for(int i=lmin;i<rmax;i++){
        nums.insert(pair<int, int>(i,0));
    }

    for(int i=0;i<n;i++){
        for(int j=l[i];j<=r[i];j++){
            nums[j]=nums[j]+1;
        }
    }
    int max=-1;
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        if(itr->second > max){
            max=itr->first;
        }
    }
    return max;
}

int main(){
    int l[]{1,2,5,15};
    int r[]{5,8,7,18};
    cout<<maxAppearingElement(l,r,4);
    return 0;
}