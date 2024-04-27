#include<iostream>
using namespace std;

//Naive solution
double medianOfTwoArrays(int a1[],int n1,int a2[],int n2){
    int i=0;
    int j=0;
    int res[n1+n2];
    int k=0;
    while(i<n1 && j<n2){
        while(a1[i]<a2[j]){
            res[k]=a1[i];
            i++;
            k++;
        }
        while(a1[i]>a2[j]){
            res[k]=a2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        res[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2){
       res[k]=a2[j];
       j++;
       k++; 
    }

    
    for(int i=0;i<n1+n2;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    if((n1+n2)%2==0){
        return double(res[(n1+n2)/2]+res[((n1+n2)/2)-1])/2.0;
    }
    return res[(n1+n2)/2];
}

double medianOfTwoArrays2(int a1[],int n1,int a2[],int n2){
    int start=0;
    int end=n1;
    while(start<=end){
        int i1=(start+end)/2;//mid
        int i2=((n1+n2+1)/2)-i1;
        cout<<i1<<" "<<i2<<endl;
        int mxl1=(i1==n1)?INT_MIN:a1[i1-1];
        int mnr1=(i1==n1)?INT_MAX:a1[i1];
        int mxl2=a2[i2-1];
        int mnr2=a2[i2];
        if(mxl1<=mnr2 && mxl2<=mnr1){
            if((n1+n2)%2==0){
                return double(max(mxl1,mxl2)+min(mnr1,mnr2))/2;
            }else{
                return max(mxl1,mxl2);
            }
        }
        else if(mxl1<mnr2){
            start=i1+1;
        }else{
            end=i1-1;
        }
    }
}
int main(){
    int a1[]{10,20,30,40,50};
    int a2[]{5,15,25,35,45};
    cout<<medianOfTwoArrays2(a1,5,a2,5);
    return 0;
}