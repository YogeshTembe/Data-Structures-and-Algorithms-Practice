#include <iostream>
using namespace std;

//naive solution

int gcdMethod1(int a,int b){
    int res=min(a,b);
    while(true){
        if(a%res==0 && b%res==0){
            return res;
        }
        res--;
    }
}

//two efficient solutions 
/*
Basic Euclidean Algorithm for GCD 
The algorithm is based on the below facts. 

If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.
*/

//subtraction
int gcdMethod2(int a,int b){
    if(a==0){return b;}
    if(b==0){return a;}

    if(a==b){return a;}
    if(a>b){
        return gcdMethod1(a-b,b);
    }
    return gcdMethod1(b-a,a);
}

//remainder
int gcdMethod3(int a,int b){
    if(a==0){
        return b;
    }
    return gcdMethod3(b%a,a);
}

int main()
{
    cout<<gcdMethod1(90,36)<<endl;
    cout<<gcdMethod2(90,36)<<endl;
    cout<<gcdMethod3(90,36)<<endl;
    return 0;
}