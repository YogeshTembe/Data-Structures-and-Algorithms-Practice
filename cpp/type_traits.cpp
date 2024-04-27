#include<iostream>
using namespace std;

template<typename T>
T func(T a){
    cout<<std::is_floating_point<T>::value<<endl;
    cout<<typeid(a).name()<<endl;
    static_assert(std::is_floating_point<T>::value,"only floating point supported");
    return a;
}

int main(){
    //func(2);
    func(3.4f);
    return 0;
}