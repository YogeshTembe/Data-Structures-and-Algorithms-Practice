#include<iostream>
using namespace std;

int main(){
    cout<<sizeof(int)<<" "<<sizeof(double)<<endl;
    int *p=(int*)malloc(sizeof(int));
    //cout<<p[0]<<" "<<*p<<endl;
    cout<<sizeof(p)<<" "<<p<<" "<<(p+1)<<endl;

    double *p2=(double*)malloc(sizeof(double));
    cout<<sizeof(p2)<<" "<<p2<<" "<<(p2+1)<<endl;
    return 0;
}