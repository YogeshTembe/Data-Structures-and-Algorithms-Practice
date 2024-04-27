#include<iostream>
#include<vector>
using namespace std;

bool search(string pat, string txt) 
{ 
    // Your code here
    for(int i=0;i<txt.length();i++){
        int k=i;
        int j=0;
        for(j=0;j<pat.length();j++){
            if(pat[j]!=txt[k]){
                break;
            }
            k++;
        }
        if(j==pat.length()){return true;}
    }
    return false;
} 

int main(){
    cout<<search("abed","abceabcdabceabcd")<<endl;
    return 0;
}