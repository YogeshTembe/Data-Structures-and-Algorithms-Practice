#include<iostream>
using namespace std;

auto sum(){
    return 0;
}

template<typename T,typename ...Args>
auto sum(T a,Args ...args){
    return a+sum(args...);
}

template<typename ...Args>
auto sum2(Args ...args){
    return (args+...);
}

int main(){
    cout<<sum(1,2,3,4)<<endl;
    cout<<sum2(1,2,3,4)<<endl;
    std::string name(R"(some text here "yes")");
    cout<<name<<endl;
    return 0;
}