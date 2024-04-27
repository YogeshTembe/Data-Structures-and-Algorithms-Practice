#include<iostream>
#include<memory>
#include<vector>
using namespace std;

struct Free{
    void operator()(int *p){
        cout<<"called free"<<endl;
        delete p;
    }
};

void FreeFunc(int *p){
    cout<<"global func"<<endl;
    delete p;
}

int main(){
    unique_ptr<int,Free>ptr{new int(45),Free{}};
    cout<<*ptr<<endl;

    unique_ptr<int,void(*)(int*)>ptr2{new int(23),FreeFunc};
    cout<<*ptr2<<endl;

    //unique_ptr<int>uptr=new int(5);

    // std::vector<std::unique_ptr<int> > vecX;
    // vecX.push_back(new int(6));

    // std::unique_ptr<int> pX = vecX[0];  
    return 0;
}