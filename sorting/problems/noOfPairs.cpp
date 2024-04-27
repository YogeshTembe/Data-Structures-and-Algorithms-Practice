#include<iostream>
#include<algorithm>
using namespace std;

long long countPairs(int X[], int Y[], int M, int N)
{
    //Your code here
    sort(X,X+M);
    sort(Y,Y+N);
    long long ans=0;
    //int min=M>N?M:N;
    bool firstOne=false;
    if(Y[0]==1){
        ans=M;
        firstOne=true;
    }
    for(int i=0;i<M;i++){
        int start=firstOne?1:0;
        int curr=0;
        for(int j=start;j<N;j++){
          if(Y[j]<X[i]){
            curr++;
          }else{
            break;
          }
        }
    }
}

int main(){
    return 0;
}