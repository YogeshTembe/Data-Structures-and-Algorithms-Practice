#include<iostream>
using namespace std;

class test{
    public:
    test(){cout<<"test constructor"<<endl;}
    ~test(){cout<<"test destructor"<<endl;}
};

void func() noexcept(false){
    test *t=new test();
    test t2;
    cout<<"here"<<endl;
    //throw std::runtime_error("this");
    float a=0.0f;
    float b=4.0f/0.0f;
}

int main(){
    // try{
    //     throw std::runtime_error("some error");
    // }catch(std::runtime_error &er){
    //     cout<<"--"<<er.what()<<endl;
    // }
    //try{
        func();
    // }catch(std::runtime_error &er){
    //      cout<<"--"<<er.what()<<endl;
    // }
    return 0;
}