#include<iostream>
#include<vector>
using namespace std;

bool checkPangram (string str) {
    // your code here
    vector<int>table(26,0);
    for(int i=0;i<str.length();i++){
        if(str[i]>=97 && str[i]<=122){
            table[int(str[i]-'a')]++;
        }else{
            table[int(str[i]-'A')]++;
        }
    }
    for(int i=0;i<26;i++){
        if(table[i]==0){return false;}
    }
    return true;
}

int main(){
    cout<<checkPangram("Bawds jog, flick quartz, vex nymph")<<endl;
    cout<<checkPangram("abc")<<endl;
    return 0;
}