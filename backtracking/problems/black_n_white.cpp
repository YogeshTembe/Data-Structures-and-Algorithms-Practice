#include<iostream>
#include<vector>
using namespace std;

// void solve(int i,int j){
    
// }

const long long mod=1e9+7;

long long numOfWays(int N, int M){
    // write code here
    long long count=0;
    long long res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            //cout<<i<<" "<<j<<endl;
            count=0;
            //cout<<"--"<<(i+2)<<" "<<(j+1)<<endl;
            if((i+2)<N && (j+1)<M){//
                //cout<<"here"<<endl;
                count++;
            }
            //() || ((j-2)>=0 && (i-1)>=0) || 
            if((j+2)<M && (i+1)<N){//
                count++;
            }
            if((j+2)<M && (i-1)>=0){//
                count++;
            }
            if((i+2)<N && (j-1)>=0){//
                count++;
            }
            if((j-2)>=0 && (i-1)>=0){//
                count++;
            }
            if((j-2)>=0 && (i+1)<N){//
                count++;
            }
            if((i-2)>=0 && (j+1)<M){//
                count++;
            }
            if((i-2)>=0 && (j-1)>=0){//
                count++;
            }
            //cout<<count<<endl;
            res=res+((N*M-1)-count)%mod;
        }
    }
    return res%mod;
}

int main(){
    //419 134
    cout<<numOfWays(2,3)<<endl;
    cout<<numOfWays(419,134)<<endl; //151874601
    return 0;
}