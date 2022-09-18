#include<iostream>
using namespace std;

int circularSubarraySum(int arr[], int num){      
    // your code here
    int sum=0;
    for(int i=0;i<num;i++){
        sum+=arr[i];
    }
    int curr_max=arr[0];
    int curr_min=arr[0];
    int max_so_far=arr[0];
    int min_so_far=arr[0];

    for(int i=1;i<num;i++){
        curr_max=((curr_max+arr[i])>arr[i])?(curr_max+arr[i]):arr[i];
        max_so_far=(curr_max>max_so_far)?curr_max:max_so_far;

        curr_min=((curr_min+arr[i])<arr[i])?(curr_min+arr[i]):arr[i];
        min_so_far=(curr_min<min_so_far)?curr_min:min_so_far;
    }

    //if all the numbers are negative
    if(min_so_far==sum){return sum;}

    return (max_so_far>(sum-min_so_far))?max_so_far:(sum-min_so_far);
}

int main(){
    int a[]{8,-8,9,-9,10,-11,12};
    cout<<circularSubarraySum(a,7);
    return 0;
}