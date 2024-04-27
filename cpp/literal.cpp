#include <iostream>
using namespace std;

class Distance{
    public:
    unsigned long long val;
    Distance(unsigned long long v):val(v){
        cout<<"distance constructor"<<endl;
    }
};

Distance operator"" _miles(unsigned long long v){
    return {v*2};
}

int main(){
    Distance d{10_miles};
    cout<<d.val<<endl;
    return 0;
}