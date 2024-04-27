#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void printMap(unordered_map<char,int>m){
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}

bool anagramSearch(string txt,string pat){
    int p=0;
    int t=0;
    for(int i=0;i<pat.length();i++){
        p=(p+int(pat[i]-'a'));
        //cout<<p<<" "<<int(pat[i]-'a')<<" "<<pat[i]<<" ";
        t=(t+int(txt[i]-'a'));
    }
    cout<<endl;
    unordered_map<char,int>patc;
    for(int i=0;i<pat.length();i++){
        patc[pat[i]]++;
    }
    printMap(patc);
    unordered_map<char,int>txtc;
    for(int i=0;i<=txt.length()-pat.length();i++){
        cout<<p<<" "<<t<<endl;
        if(p==t){
            txtc.clear();
            cout<<txt[i]<<endl;
            for(int j=i-pat.length()+1;j<=i;j++){
                cout<<"-"<<txt[j]<<endl;
                txtc[txt[j]]++;
            }
            printMap(txtc);
            if(txtc==patc){
                return true;
            }
        }else if(i>0 && i<(txt.length()-pat.length())){
            cout<<txt[i-1]<<" "<<txt[i+pat.length()-1]<<endl;
            t=t-int(txt[i-1]-'a')+int(txt[i+pat.length()-1]-'a');
        }
    }
    return false;
}

int main(){
    cout<<anagramSearch("geeksforgeeks","rseek");
    return 0;
}