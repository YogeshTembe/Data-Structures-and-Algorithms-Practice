#include<iostream>
#include<vector>
using namespace std;

//recursive solution
int totalProfit(int idx,vector<int>& values,vector<int>& weights, int totalSackWeight){
    //cout<<idx<<" "<<totalSackWeight<<endl;
    if(totalSackWeight==0){return 0;}
    if(idx<0){return 0;}
    int c1=0;
    if((totalSackWeight-weights[idx])>=0){
        c1=values[idx]+totalProfit(idx-1,values,weights,totalSackWeight-weights[idx]);
    }
    int c2=totalProfit(idx-1,values,weights,totalSackWeight);
    //cout<<idx<<" "<<max(c1,c2)<<endl;
    return max(c1,c2);
}

//dp solution
int totalProfit2(vector<int>& values,vector<int>& weights,int totalSackWeight){
    vector<vector<int>>dp(totalSackWeight+1,vector<int>(values.size()+1,0));//int dp[totalSackWeight][values.size()];
    //fill first column
    for(int i=0;i<=totalSackWeight;i++){
        dp[i][0]=0;
    }
    //fill first row
    for(int i=0;i<=values.size();i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=totalSackWeight;i++){
        for(int j=1;j<=values.size();j++){
            dp[i][j]=dp[i][j-1];
            if(weights[j-1]<=i){
                dp[i][j]=max(dp[i][j],values[j-1]+dp[i-weights[j-1]][j-1]);
            }
        }
    }
    for(auto a:dp){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return dp[totalSackWeight][values.size()];
}

int main(){
    // vector<int>values{10,40,30,50};
    // vector<int>weights{5,4,6,3};
    vector<int>values{60,100,120};
    vector<int>weights{10,20,30};
    cout<<totalProfit(values.size()-1,values,weights,50)<<endl;
    cout<<totalProfit2(values,weights,50)<<endl;
    return 0;
}