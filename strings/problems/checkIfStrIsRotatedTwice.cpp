#include<iostream>
#include<string>
using namespace std;

bool isRotated(string str1, string str2)
{
    // Your code here
    if(str1.length()!=str2.length()){return false;}
    size_t idx=(str1+str1).find(str2);
    return (idx!=string::npos) && (idx==2 || idx==str1.length()-2);//to handle both clockwise and anticlockwise
}

int main(){
    cout<<isRotated("amazon","azonam")<<endl;
    return 0;
}