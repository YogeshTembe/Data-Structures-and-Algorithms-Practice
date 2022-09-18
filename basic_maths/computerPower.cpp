#include <iostream>
using namespace std;

//naive solution
int computePower1(int x, int n){
    int res=1;
    for(int i=0;i<n;i++){
        res=res*x;
    }
    return res;
}

//efficient solution
int computePower2(int x, int n){
    int res=1;
    if(n%2==0){
        for(int i=0;i<n/2;i++){
            res=res*x;
        }
        return res*res;
    }else{
        return computePower2(x,n-1)*x;
    }
}

//efficient solution(iterative)
int computePower3(int x,int n){
    if(n==0){
        return 1;
    }
    int temp=computePower3(x,n/2);
    temp=temp*temp;
    if(n%2==0){
        return temp;
    }else{
        return temp*x;
    }
}

//more efficient solution
//Iterative power (binary exponentiation)
//3^19 = 3^16 + 3^2 + 3^1  --> 19=10011 --> binary = 1(3^16)0(3^8)0(3^4)1(3^2)1(3^1)
//3^10 = 3^8 + 3^2 --> 10=1010 --> binary=1(3^8)0(3^4)1(3^2)0(3^1)
int computePower4(int x,int n){
    int res=1;
    while(n>0){
        //cout<<res<<endl;
        if(n%2!=0){
            //bit=1
            res=res*x;
        }
        x=x*x;
        n=n/2;
    }
    return res;
}

int main(){
    cout<<computePower1(3,2)<<endl;
    cout<<computePower2(11,2)<<endl;
    cout<<computePower3(4,5)<<endl;
    cout<<computePower4(4,5)<<endl;
    return 0;
}