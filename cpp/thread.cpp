#include<iostream>
#include<thread>
using namespace std;

void func1(int num){
    for(int i=0;i<num;i++){
        cout<<"a"<<endl;
    }
}

void func2(int num){
    for(int i=0;i<num;i++){
        cout<<i<<endl;
    }
}

int main(){
    cout<<"main start"<<endl;
    std::thread t1(func1,10);
    std::thread t2(func2,10);
    t2.join();
    t1.join();
    int cores = std::thread::hardware_concurrency();
    cout<<"cores-"<<cores<<endl;
    cout<<"main end"<<endl;
    return 0;
}