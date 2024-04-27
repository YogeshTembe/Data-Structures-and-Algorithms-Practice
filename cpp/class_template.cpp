#include<iostream>
#include<vector>
using namespace std;

template<typename T,int size>
class test{
    public:
    T random;
    int len;
    test(T random){
        cout<<"test constructor"<<endl;
        this->random=random;
        len=size;
    }
};

template<typename T>
class test<T,34>{
    public:
    T random;
    int len;
    test(T random){
        cout<<"test 34 constructor"<<endl;
        len=34;
    }
};

template<typename T>
// typedef vector<vector<T>> teams;
using teams=vector<vector<T>>;

int main(){
    test<int,45>tobj(67);
    test<char,34>tobj2('a');
    return 0;
}