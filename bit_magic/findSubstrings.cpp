#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

//naive solution
//time complexity - O((2^n)*n)
//we find all the substrings by generating all the binary numbers till 2^n, if n is the length of string
//if the binary is 001 then output is a , if its 011 then ab, if its 101 then output is ac
void findSubsetsOfString(std::string str){
    int n=str.length();
    //cout<<"asln "<<n<<endl;
    int counter=0;
    for(int i=0;i<(pow(2,n));i++){
        cout<<i<<endl;
        for(int j=0;j<n;j++){
            //cout<<j<<endl;
            if((i & (1<<j))!=0){
                cout<<str[j];
            }
        }
        cout<<endl;
    }
}

//my solution
void findSubsetsOfString2(std::string str){
    int n=str.length();
    for(int i=0;i<(pow(2,n));i++){
        std::string binary = std::bitset<8>(i).to_string().substr(8-n,n);; //to binary
        //std::cout<<binary<<"\n";
        for(int j=0;j<n;j++){
            //cout<<binary.at(j)<<endl;
            if(binary.at(j)=='1'){
                cout<<str.at(j);
            }
        }
        cout<<endl;
    }
}

int main()
{
    findSubsetsOfString("abc");
    findSubsetsOfString2("abc");
    return 0;
}
