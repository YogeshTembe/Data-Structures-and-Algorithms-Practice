#include<iostream>
using namespace std;

//Naive solution 
//time complexity = O(logn+k) where k is number of times the element occurs
//but we want O(logn) solution
int countOccu(int arr[],int n,int ele){
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int count=0;
    while(low<=high){
        if(arr[mid]==ele){
            int temp=mid;
            //go to right
            while(arr[mid]==ele){
                count++;
                mid++;
            }
            //go to left
            while(arr[temp-1]==ele){
                count++;
                temp--;
            }
            return count;
        }
        else if(arr[mid]<ele){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    return count;
}

//First Occurence
int indexOfFirstOccurence(int arr[],int n,int ele){
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<ele){low=mid+1;}
        else if(arr[mid]>ele){high=mid-1;}
        else{
            if(mid==0 || arr[mid]!=arr[mid-1]){return mid;} //here we found the element
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

//Last Occurence
int indexOfLastOccurence(int arr[],int n,int ele){
    int low=0;
    int high=n-1;
    int mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>ele){
            high=mid-1;
        }
        else if(arr[mid]<ele){
            low=mid+1;
        }
        else{
            if(mid==n-1 || arr[mid]!=arr[mid+1]){return mid;}
            else{
                low=mid+1;
            }
        }
        //cout<<mid<<endl;
    }
    return -1;
}


//Efficient solution
//time complexity=O(logn)
int countOccu2(int arr[],int n,int ele){
    int count=0;
    int first=indexOfFirstOccurence(arr,n,ele);
    if(first==-1){
        return 0;
    }
    return (indexOfLastOccurence(arr,n,ele)-first+1);
}


int main(){
    int arr[]{10,10,20,20,20,30,30,40,40,50};
    //cout<<countOccu(arr,10,50);
    cout<<countOccu2(arr,10,20);
    return 0;
}