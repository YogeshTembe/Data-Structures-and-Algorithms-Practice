#include<iostream>
#include<vector>
using namespace std;

//recursive solution
int lcs(int n, int m, string s1, string s2)
{
    // your code here
    if(n==0 || m==0){
        return 0;
    }
    if(s1[n-1]==s2[m-1]){
        return 1+lcs(n-1,m-1,s1,s2);
    }
    return max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
}

//dp solution
int lcs2(int n,int m,string s1,string s2){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //first row
    for(int i=0;i<m;i++){
        dp[0][i]=0;
    }
    //first column
    for(int j=0;j<n;j++){
        dp[j][0]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    cout<<lcs(6,6,"ABCDGH","AEDFHR")<<endl;
    cout<<lcs2(6,6,"ABCDGH","AEDFHR")<<endl;
    return 0;
}