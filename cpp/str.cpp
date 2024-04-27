#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    //std::cout<<"Hello World";
    char str[]={'g','f','g','\0'};
    cout<<sizeof(str)<<" "<<strlen(str)<<endl;
    return 0;
}
