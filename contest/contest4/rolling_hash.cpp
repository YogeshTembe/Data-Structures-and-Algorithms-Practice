#include<iostream>
using namespace std;

void rollingHash(string s, string p)
{
    int phash = 0;
    int shash = 0;
    for(int i=0;i<p.length();i++){
        phash = phash + int(p[i]) - int('a') + 1;
        shash = shash + int(s[i]) - int('a') + 1;
    }
    bool found = false;
    if(phash == shash){
        found = true;
        cout<<s.substr(0,p.length())<<" "<<0<<endl;
    }
    //cout<<shash<<" "<<phash<<endl;
    for(int i=p.length();i<s.length();i++){
        shash = shash - (int(s[i-p.length()]) - int('a') +1) + (int(s[i]) - int('a')+1);
        
        if(phash == shash){
            found=true;
            //cout<<s[i]<<" "<<shash<<" "<<phash<<endl;
            cout<<s.substr(i-p.length()+1,p.length())<<" "<<i-p.length()+1<<endl;
        }
    }
    if(!found){cout<<"-1"<<endl;}
}

int main(){
    rollingHash("bbaa","aab");
    return 0;
}