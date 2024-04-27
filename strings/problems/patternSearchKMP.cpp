#include<iostream>
#include<vector>
using namespace std;

//Function to fill lps[] for given patttern pat[0..M-1].
void computeLPSArray(string pat, int M, int* lps) 
{ 
	// Your code here
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len==0){lps[i]=0; i++;}
            else{len=lps[len-1];}
        }
    }
} 

//Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) 
{
    // Your code here
    int n=txt.length();
    const int m=pat.length();
    int* lps=new int[m];
    computeLPSArray(pat,pat.length(),lps);
    int i=0,j=0;
    while(i<n){
        if(pat[j]==txt[i]){i++;j++;}
        if(j==m){return true;}
        else if(i<n && pat[j]!=txt[i]){
            if(j==0){i++;}
            else{j=lps[j-1];}
        }
    }
    return false;
}

int main(){
    cout<<KMPSearch("aaaab","aabaacaadaabaaba")<<endl;
    /*S = aabaacaadaabaaba
P = caada*/
    cout<<KMPSearch("caada","aabaacaadaabaaba")<<endl;
    return 0;
}