#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//this solution fails for textcase "aba" and "xxy"
bool areIsomorphic(string str1, string str2)
{   
    // Your code here
    if(str1.length()!=str2.length()){return false;}
    unordered_map<char,int>t1;
    unordered_map<char,int>t2;
    for(int i=0;i<str1.length();i++){
        t1[str1[i]]++;
        t2[str2[i]]++;
    }
    for(int i=0;i<str1.length();i++){
        if(t1[str1[i]]!=t2[str2[i]]){
            return false;
        }
        t1[str1[i]]--;
        t2[str2[i]]--;
    }
    return true;
}


//Efficient solution
bool areIsomorphic2(string str1,string str2){
    if(str1.length()!=str2.length()){return false;}
    unordered_map<char,int>t1,t2;
    for(int i=0;i<str1.length();i++){
        if(t1.find(str1[i])!=t1.end()){
            if(t1[str1[i]]!=str2[i]){
                return false;
            }
        }else{
            t1[str1[i]]=str2[i];
        }

        if(t2.find(str2[i])!=t1.end()){
            if(t2[str2[i]]!=str1[i]){
                return false;
            }
        }else{
            t2[str2[i]]=str1[i];
        }
    }
    return true;
}

int main(){
    cout<<areIsomorphic2("aab","xxy")<<endl;
    return 0;
}