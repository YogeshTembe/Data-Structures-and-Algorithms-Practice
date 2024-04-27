#include<iostream>
#define d 256
using namespace std;

bool search(string pat, string txt, int q) 
{ 
	// Your code here
    //precompute d^(m-1)
    int m=pat.length();
    int h=1;
    for(int i=1;i<=m-1;i++){
        h=(h*d)%q;
    }
    //precompute p and t0
    int p=0;
    int t=0;
    for(int i=0;i<m;i++){
        p=(p*d+(pat[i]))%q;
        t=(t*d+(txt[i]))%q;
    }
    //loop over txt to match hash values
    for(int i=0;i<txt.length()-m+1;i++){
        cout<<p<<" "<<t<<endl;
        if(p==t){
            bool flag=true;
            for(int j=0;j<pat.length();j++){
                if(pat[j]!=txt[i+j]){
                    flag=false;
                    break;
                }
            }
            if(flag){return true;}
        }
        if(i<txt.length()-m){
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            if(t<0){t=t+q;}
        }
    }
    return false;
} 

int main(){
    cout<<search("ahf","lkjsdfhaiuehaoewiuraoikdehjakdsfhlsjdkihalieushralkehfailuewhfaklfjsdhfliuewahf",10*9+7);
    return 0;
}