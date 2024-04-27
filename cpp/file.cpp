#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
using namespace std;

int main(){
    std::ofstream out;
    out.open("example.txt");
    out<<"hello world!"<<endl;
    out.close();

    std::ifstream in;
    in.open("example.txt");
    string msg;
    std::getline(in,msg);
    cout<<msg<<endl;
    return 0;
}