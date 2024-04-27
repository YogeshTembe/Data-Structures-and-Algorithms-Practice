#include<iostream>
#include<any>
using namespace std;

int main(){
    std::any num=7;
    cout<<num.has_value()<<endl;
    cout<<num.type().name()<<endl;
    num=std::string("strtest");
    cout<<std::any_cast<string>(num)<<endl;
    cout<<num.type().name()<<endl;

    std::string msg(R"(here some str - "abc")");
    cout<<msg<<endl;
    return 0;
}