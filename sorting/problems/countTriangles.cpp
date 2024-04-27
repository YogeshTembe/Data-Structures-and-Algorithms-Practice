#include<iostream>
#include<algorithm>
using namespace std;

int findNumberOfTriangles(int arr[], int n)
{
    // code here
    sort(arr,arr+n);
    int c1=0,c2=0;
    int res=0;
    
    while(c1<n-2){
        int i=1;
        while(i<n-1){
            c2=c1+i;
            int j=c2+1;
            cout<<arr[c1]<<" "<<arr[c2]<<" "<<j<<endl;
            int count=0;
            while(j<n && arr[j]<(arr[c1]+arr[c2])){
                count++;
                j++;
            }
            cout<<"c-"<<count<<endl;
            res=res+count;
            cout<<res<<endl;
            c2++;
            i++;
        }
        c1++;
    }
    return res;
}

int main(){
    //int arr[]={4,5,6,7,8,9,10};
    int arr[]={3, 5, 4};
    cout<<findNumberOfTriangles(arr,3);
    return 0;
}