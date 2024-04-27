#include<iostream>
using namespace std;

//naive solution
//Time complexity=O(sqrt(n))
int squareRoot(int n){
    for(int i=0;i<(n/2);i++){
        if(i*i == n){
            return i;
        }
        if(i*i >n){
            return i-1;
        }
    }
    return -1;
}

//Efficient solution
//Time complexity=O(logn)
int squareRoot2(int n){
    int low=0;
    int high=n;
    int mid=(low+high)/2;
    int sq=0;
    int ans=0;
    while(low<=high){
        sq=mid*mid;
        if(sq>n){
            high=mid-1;
        }
        else if(sq==n){
            return mid;
        }
        else{
            low=mid+1;
            ans=mid;
        }
        mid=(low+high)/2;
    }
    return ans;    
}


int main(){
    cout<<squareRoot2(14);
    return 0;
}