#include<iostream>
#include<vector>
using namespace std;

int modified (string a){
    // Your code here
    char ch;
    int count=0;
    int res=0;
    for(int i=0;i<a.length();i++){
        if(ch==a[i]){
            count++;
        }else{
            ch=a[i];
            count=1;
        }
        if(count>=3){
            res++;
            count=1;
            ch=a[i];
        }
    }
    
    return res;
}

int main(){
    cout<<modified("aabbbcc")<<endl;
    cout<<modified("aaaaa")<<endl;
    return 0;
}