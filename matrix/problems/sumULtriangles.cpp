#include<iostream>
#include<vector>
using namespace std;

vector<int> sumTriangles(const vector<vector<int> >& arr, int n)
{
    // code here
    int d1=0;
    int d2=0,c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>c){
                d1=d1+arr[i][j];
            }else if(c==j){
                d2=d2+arr[i][j];
                d1=d1+arr[i][j];
            }else{
                d2=d2+arr[i][j];
            }
        }
        c++;
    }
    vector<int>temp{d1,d2};
    return temp;
}

int main(){
    //vector<vector<int>>arr{{6, 5, 4},{1, 2, 5},{7, 9, 7}};
    vector<vector<int>>arr{{1, 2},{3, 4}};
    auto res=sumTriangles(arr,2);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}