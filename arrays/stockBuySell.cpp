#include<iostream>
#include<vector>
using namespace std;

int maxProfit(int price[],int start, int end){
    cout<<start<<" "<<end<<" "<<endl;
    if(end<=start){
        return 0;
    }
    int profit=0;
    
    for(int i=start;i<end;i++){
        for(int j=i+1;j<=end;j++){
            if(price[j]>price[i]){
                int currProfit=price[j]-price[i]+maxProfit(price,start,i-1)+maxProfit(price,j+1,end); //we check for left of i and right of j
                if(currProfit>profit){
                    profit=currProfit;
                }
            }
        }
    }
    cout<<profit<<endl;
    return profit;
}

//efficient solution
int maxProfit2(int price[],int n){
    int profit=0;
    for(int i=1;i<n;i++){
        if(price[i]>price[i-1]){
            profit=profit+(price[i]-price[i-1]);
        }
    }
    return profit;
}

int main(){
    //int a[]={1,5,3,1,2,8};
    int a[]={1,5,3,8,12};
    cout<<maxProfit2(a,5);
    return 0;
}