#include<iostream>
#include<algorithm>
using namespace std;

bool find3Numbers(int arr[], int n, int X)
{
    //Your Code Here
    sort(arr,arr+n);
    int sum=0,left=0,mid=1,right=n-1;
    int c=0;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        left=i+1;right=n-1;
        while(left<right){
            sum=arr[i]+arr[left]+arr[right];
            if(sum==X){
                cout<<arr[left]<<" "<<arr[mid]<<" "<<arr[right]<<endl;
                return true;
            }
            if(sum>X){
                right--;
            }else{
                left++;
            }
        }
    }
    // while(mid<right){
    //     sum=arr[left]+arr[mid]+arr[right];
    //     cout<<sum<<endl;
    //     if(sum==X){
    //         cout<<arr[left]<<" "<<arr[mid]<<" "<<arr[right]<<endl;
    //         return true;
    //     }
    //     if(sum<X && c%2==0){
    //         mid++;
    //     }else if(sum<X && c%c!=0){
    //         left++;
    //     }else if(sum>X){
    //         right--;
    //     }
    // }
    return false;
}

int main(){
    // int arr[]{1,4,45,6,10,8};
    // cout<<find3Numbers(arr,6,13);
    /*24 986
557 217 627 358 527 358 338 272 870 362 897 23 618 113 718 697 586 42 424 130 230 566 560 933*/
    int arr[]{557,217,627,358,527,358,338,272,870,362,897,23,618,113,718,697,586,42,424,130,230,566,560,933};
    cout<<find3Numbers(arr,24,986);
    return 0;
}