#include <iostream>

using namespace std;

int factorial(int num){
    if(num==0){
        return 1;
    }
    return num*factorial(num-1);
}

int main()
{
    int a=6;
    int result=factorial(a);
    cout<<result;
    return 0;
}
