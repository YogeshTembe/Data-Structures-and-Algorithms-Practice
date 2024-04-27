#include<iostream>
using namespace std;

bool isSubSequence(string A, string B)
{
    //code here
    int j=0;
    for(int i=0;i<B.length() && j<A.length();i++){
        if(B[i]==A[j]){
            j++;
        }
    }
    if(j==A.length()){
        return true;
    }
    return false;
}

int main(){
    cout<<isSubSequence("gksrek","geeksforgee")<<endl;
    return 0;
}