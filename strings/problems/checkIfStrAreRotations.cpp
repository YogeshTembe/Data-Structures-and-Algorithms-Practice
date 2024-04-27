#include<iostream>
using namespace std;

bool areRotations(string s1,string s2)
{
    // Your code here
    if(s1.length()!=s2.length()){return false;}
    return (s1+s1).find(s2)!=string::npos;
}

int main(){
    /*mightandmagic
andmagicmigth*/
    cout<<areRotations("mightandmagic","andmagicmigth")<<endl;
    return 0;
}

