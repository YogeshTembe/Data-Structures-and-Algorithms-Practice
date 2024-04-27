#include<iostream>
using namespace std;

long binarySubstring(int n, string a){
        
    // Your code here
    long sum=0;
    long c=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]=='1'){
            sum+=c;
            c+=1;
        }
    }
    return sum;
}

int main(){
    cout<<binarySubstring(4,"1111");
    return 0;
}