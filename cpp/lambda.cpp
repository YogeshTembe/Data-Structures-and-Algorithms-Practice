#include<iostream>
using namespace std;

int main(){  
    int z=56;
    auto sum=[&z,k=z+2](auto x,auto y){
        z++;
        cout<<z<<" "<<k<<endl;
        return x+y;
    };
    cout<<sum(4,6)<<endl;
    cout<<sum(string("s"),string("d"))<<endl;
    cout<<sum(3.4f,5.6f)<<endl;
    cout<<z<<endl;
    return 0;
}