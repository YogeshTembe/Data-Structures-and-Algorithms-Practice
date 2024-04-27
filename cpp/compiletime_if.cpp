#include<iostream>
#include<array>
using namespace std;

template<typename T>
void func(T t){
    cout<<"called func"<<endl;
    if constexpr(is_array_v<T>){
        cout<<"its array"<<endl;
        for(auto a:t){
            cout<<a<<endl;
        }
    } 
    // else if constexpr(is_pointer_v<T>){
    //     cout<<*t<<endl;
    // }
    // else{
    //     cout<<t<<endl;
    // }
}


int main(){
    int num=34;
    func(num);
    int *ptr=&num;
    func(ptr);
    int arr[]={3,5,7};
    func(arr);
    return 0;
}