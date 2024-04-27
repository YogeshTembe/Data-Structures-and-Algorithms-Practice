#include<iostream>
using namespace std;

int maxWater(int height[], int n) 
{ 
    //Your code here
    int max=INT_MIN;
    int left=0;
    int right=n-1;
    while(left<right){
        int curr=min(height[left],height[right])*(right-left-1);
        max=curr>max?curr:max;
        if(height[left]<height[right]){
            left=left+1;
        }else{
            right=right-1;
        }
    }
    return max;
} 

int main(){
    int height[]{2,1,3,4,6,5};
    cout<<maxWater(height,6);
    return 0;
}