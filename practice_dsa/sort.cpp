#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){return;}
    }
}

void selection_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

void insertion_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void merge(int arr[],int l,int m,int h){
    //cout<<l<<" "<<m<<" "<<h<<endl;
    const int n1=m-l+1;
    const int n2=h-m;
    int *arr1=new int[n1];//left
    int *arr2=new int[n2];//right
    //cout<<"arr1"<<endl;
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
        //cout<<arr1[i];
    }
    // cout<<endl;
    // cout<<"arr2"<<endl;
    for(int i=0;i<n2;i++){
        arr2[i]=arr[m+i+1];
        //cout<<arr2[i];
    }
    //cout<<endl;

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            k++;
            i++;
        }else{
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr[k]=arr1[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k]=arr2[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[],int l,int h){
    if(l<h){
        int m=l+(h-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

void naive_partition(int arr[],int l,int h,int p){
    int *temp=new int[h-l+1];
    int index=0;
    for(int i=l;i<=h;i++){
        if(arr[i]<p){
            temp[index]=arr[i];
            index++;
        }
    }
    temp[index]=p;
    index++;
    for(int i=l;i<=h;i++){
        if(arr[i]>p){
            temp[index]=arr[i];
            index++;
        }
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i-l];
    }
}

int lomuto_partition(int arr[],int l,int h){
    int p=arr[h];
    int i=l-1;
    for(int j=l;j<=h;j++){
        if(arr[j]<p){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;   
}

int hoares_partition(int arr[],int l,int h){
    int i=l-1;
    int j=h+1;
    int p=arr[l];
    while(true){
        do{
            i++;
        }while(arr[i]<p);

        do{
            j--;
        }while(arr[j]>p);

        if(i>=j){return j;}
        swap(arr[i],arr[j]);
    }
}

void quick_sort_l(int arr[],int l,int h){
    if(l<h){
        int p=lomuto_partition(arr,l,h);
        quick_sort_l(arr,l,p-1);
        quick_sort_l(arr,p+1,h);
    }
}

void quick_sort_h(int arr[],int l,int h){
    if(l<h){
        int p=hoares_partition(arr,l,h);
        quick_sort_h(arr,l,p);
        quick_sort_h(arr,p+1,h);
    }
}

void quick_sort_optimised(int arr[],int l,int h){
    BEGIN:
    if(l<h){
        int p=hoares_partition(arr,l,h);
        quick_sort_h(arr,l,p);
        l=p+1;
        goto BEGIN;
    }
}

//dutch national flag algo to sort array with 3 distinct values
void dutchNF(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        } else if(arr[mid]==1){
            mid++;
        } else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}

void cyclesort(int arr[],int n){
    for(int cs=0;cs<n;cs++){
        int item=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++){
            if(arr[i]<item){
                pos++;
            }
        }
        swap(item,arr[pos]);
        while(pos!=cs){
            pos=cs;
            for(int i=cs+1;i<n;i++){
                if(arr[i]<item){
                    pos++;
                }
            }
            swap(item,arr[pos]);
        }
    }
}

//heap sort
void maxHeapify(int arr[],int i,int n){
    int largest=i,left=2*i+1,right=2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,largest,n);
    }
}

void buildHeap(int arr[],int n){ //for internal nodes only
    for(int i=(n-2)/2;i>=0;i--){
        maxHeapify(arr,i,n);
    }
}

void heapsort(int arr[],int n){
    buildHeap(arr,n);
    for(int i=n-1;i>=0;i--){
        maxHeapify(arr,0,i);
        swap(arr[i],arr[0]);
    }
}

void countingsort(int arr[],int n,int k){
    int *count=new int[k];
    for(int i=0;i<k;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<count[i];j++){
            arr[index]=i;
            index++;
        }
    }
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
    cout<<endl;
}

void genericcountingsort(int arr[],int n,int k,int exp){
    int *count=new int[k];
    for(int i=0;i<k;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<k;i++){
        count[i]=count[i-1]+count[i];
    }
    int *output=new int[n];
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixsort(int arr[],int n){
    int max_val=arr[0];
    for(int i=1;i<n;i++){
        max_val=max(max_val,arr[i]);
    }
    for(int exp=1;max_val/exp > 0;exp=exp*10){
        genericcountingsort(arr,n,10,exp);
        //printarr(arr,n);
    }
}

void bucketsort(int arr[],int n,const int k){
    int max_val=arr[0];
    for(int i=1;i<n;i++){
        max_val=max(max_val,arr[i]);
    }
    max_val++;

    vector<vector<int>>bkt;
    for(int i=0;i<k;i++){
        vector<int>temp{};
        bkt.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int bi=(k*arr[i])/max_val;
        //cout<<arr[i]<<" "<<bi<<endl;
        bkt[bi].push_back(arr[i]);
    }

    for(int i=0;i<k;i++){
        sort(bkt[i].begin(),bkt[i].end());
    }

    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++){
            arr[index]=bkt[i][j];
            index++;
        }
    }
}

int main(){
    int arr[]{3,7,2,1,8,4,5};
    int n=7;
    //bubble_sort(arr,n);
    //selection_sort(arr,n);
    //insertion_sort(arr,n);
    //merge_sort(arr,0,n-1);
    //naive_partition(arr,0,n-1,4);
    //cout<<hoares_partition(arr,0,n-1,4)<<endl;
    //cout<<lomuto_partition(arr,0,n-1)<<endl;
    // quick_sort_l(arr,0,n-1);
    //quick_sort_h(arr,0,n-1);
    //quick_sort_optimised(arr,0,n-1);
    //cyclesort(arr,n);
    //heapsort(arr,n);
    // countingsort(arr,n,9);
    //genericcountingsort(arr,n,9,1);
    bucketsort(arr,n,2);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    //dutch national flag algorithm
    // int arr2[]{0,2,2,0,1,0,1,2,0};
    // int n2=9;
    // dutchNF(arr2,n2);
    // for(int i=0;i<n2;i++){
    //     cout<<arr2[i]<<endl;
    // }

    //radix sort
    // int arr3[]{321,56,789,453,3,12};
    // int n3=6;
    // radixsort(arr3,n3);
    // for(int i=0;i<n3;i++){
    //     cout<<arr3[i]<<endl;
    // }

    return 0;
}