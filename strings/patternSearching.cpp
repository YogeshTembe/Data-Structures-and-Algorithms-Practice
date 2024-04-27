#include<iostream>
#include<vector>
using namespace std;

vector<int> patternSearching(string txt,string pat){
    vector<int>res;
    int j=0;

    for(int i=0;i<txt.length();i++){
        int k=i;
        int j=0;
        //cout<<txt[k]<<" "<<pat[j]<<endl;
        while(txt[k]==pat[j] && k<txt.length()){
            j++;
            k++;
        }
        //cout<<"j-"<<j<<endl;
        if(j==pat.length()){
            //cout<<"found"<<endl;
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    auto res=patternSearching("AAAAA","AAA");
    for(auto r:res){cout<<r<<" ";}
    return 0;
}