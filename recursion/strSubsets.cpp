#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

set<string> subsets;

void generateSubsets(string s){
    if(s.length()==0){subsets.insert("");return;}
   cout<<s<<" ";
   subsets.insert(s);
   for(int i=0;i<s.length();i++){
        string temp=s;
        temp.erase(i, 1);
        generateSubsets(temp);
   }
}

void generateSubsets2(string s,string curr,int index){
    if(index==s.length()){
        cout<<curr<<" ";
        return;
    }
    generateSubsets2(s,curr+s[index],index+1);
    generateSubsets2(s,curr,index+1);
}

int main(){
    generateSubsets("ABCD");
    cout<<endl;
    for(auto a:subsets){
        cout<<a<<" ";
    }
    cout<<endl;
    generateSubsets2("ABC","",0);
    return 0;
}