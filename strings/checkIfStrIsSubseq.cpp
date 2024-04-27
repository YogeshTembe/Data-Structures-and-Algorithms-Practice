#include<iostream>
using namespace std;

//Recursive solution
bool check(string str1,string str2,string curr,int idx){
    //cout<<idx<<" "<<curr<<endl;
    if(idx>str1.length()){
        return curr==str2;
    }
    string n=curr+str1[idx];
    return check(str1,str2,curr,idx+1) || check(str1,str2,n,idx+1);
}

bool isSubseq(string str1,string str2){
    string curr="";
    return check(str1,str2,curr,0);
}

//Efficient iterative solution
bool isSubseq2(string str1,string str2){
    int j=0;
    for(int i=0;i<str1.length() && j<str2.length();i++){
        if(str1[i]==str2[j]){
            j++;
        }
    }
    if(j==str2.length()){
        return true;
    }
    return false;
}

int main(){
    cout<<isSubseq("ABCD","BC");
    return 0;
}