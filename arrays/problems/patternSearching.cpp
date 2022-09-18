#include<iostream>
using namespace std;

bool searchPattern(string str, string pat)
{
    // your code here
    int p=0;
    int i=0;
    int temp=0;
    //cout<<str.length()<<" "<<pat.length()<<endl;
    while(i<str.length() && p<pat.length()){

        if(str[i]==pat[p]){
            temp=i;
            while(i<str.length() && p<pat.length() && str[i]==pat[p]){
                //cout<<i<<str[i]<<" "<<p<<pat[p]<<endl;
                p++;
                i++;
            }
            //cout<<"done-"<<i<<str[i]<<" "<<p<<pat[p]<<endl;
            if(p-1==pat.length()-1){return true;}
        }else{
            p=0;
            temp++;
            i=temp;
        }
    }
    //cout<<p<<endl;
    return (p-1==pat.length()-1);
}

int main(){
    cout<<searchPattern("abcxabcdabxabcdabcdabcy","abcdabcy")<<endl;
    cout<<searchPattern("ldvgylwgbusbmborxtlhcsmpxohgmg","yw")<<endl;
    cout<<searchPattern("hq","q");
    return 0;
}