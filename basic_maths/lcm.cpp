#include <iostream>
using namespace std;

//naive solution
int lcmMethod1(int a,int b){
    int res=max(a,b);
    while(true){
        if(res%a==0 && res%b==0){
            return res;
        }
        res++;
    }
}

//efficient solution
int gcdMethod3(int a,int b){
    if(a==0){
        return b;
    }
    return gcdMethod3(b%a,a);
}

int lcmMethod2(int a,int b){
    return (a*b)/gcdMethod3(a,b);
}

int main(){
    cout<<lcmMethod1(6,4)<<endl;
    cout<<lcmMethod2(6,4);
    return 0;
}