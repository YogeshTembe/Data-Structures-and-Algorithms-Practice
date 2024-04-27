#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//hoare partition technique
//sort negatives and positives
void sortArrayWithTwoTypes(int arr[],int n){
    int l=-1,h=n;
    while(true){
        do{
            l++;
        }while(arr[l]<0);
        do{
            h--;
        }while(arr[h]>=0);
        if(l>=h){return;}
        swap(arr[l],arr[h]);
    }
    return;
}

int main(){
    int arr[]{15,-3,-2,18};
    sortArrayWithTwoTypes(arr,4);
    print(arr,4);
    return 0;
}