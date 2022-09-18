#include<iostream>
using namespace std;

void frequencies(int arr[],int n){
    int currEle=arr[0];
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==currEle){count++;}
        else{
            cout<<currEle<<" "<<count<<endl;
            currEle=arr[i];
            count=1;
        }
    }
    cout<<currEle<<" "<<count<<endl;
    return;
}

int main(){
    int a[]={10,20,30,30,30};
    frequencies(a,5);
    return 0;
}