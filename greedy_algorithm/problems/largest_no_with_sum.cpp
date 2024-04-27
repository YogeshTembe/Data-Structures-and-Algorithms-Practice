#include<iostream>
#include<string>
using namespace std;

string largestNumber(int n, int sum)
{
    // Your code here
    string res="";
    for(int i=0;i<n;i++){
        int j=(sum<=9)?sum:9;
        while(j>sum){
            j--;
        }
        if(j<0){break;}
        sum-=j;
        res=res+to_string(j);
    }
    if(sum>0){return "-1";}
    while(res.length()<n){
        res=res+"0";
    }
    return res;
}

int main(){
    cout<<largestNumber(5,8)<<endl;
    cout<<largestNumber(3,29);
    return 0;
}