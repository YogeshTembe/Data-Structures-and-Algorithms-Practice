#include<iostream>
using namespace std;

int majorityElement(int a[], int size)
{
    // your code here
    int res=0,count=1;
    for(int i=1;i<size;i++){
        if(a[res]==a[i]){count++;}
        else{count--;}
        if(count==0){res=i;count=1;}
    }
    int count2=0;
    for(int i=0;i<size;i++){
        if(a[res]==a[i]){
            count2++;
        }
    }
    if(count2<=(size/2)){
        return -1;
    }
    return a[res];
}

int main(){
    int a[]{3,1,3,3,2};
    cout<<majorityElement(a,5);
    return 0;
}