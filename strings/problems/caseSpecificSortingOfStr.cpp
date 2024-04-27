#include<iostream>
#include<vector>
using namespace std;

string caseSort(string str, int n)
{
    // your code here
    vector<int>tableL(26,0);
    vector<int>tableH(26,0);
    for(int i=0;i<n;i++){
        //cout<<str[i]<<" "<<int(str[i])<<endl;
        if(int(str[i])>=65 && int(str[i])<=91){//lowercase
            //cout<<int(str[i]-'A')<<endl;
            tableL[int(str[i]-'A')]++;
        }else{//uuppercase
            tableH[int(str[i]-'a')]++;
        }
    }
    string str2=str;
    int currL=0;
    int currH=0;
    // for(auto a:tableL){cout<<a<<" ";}
    // cout<<endl;
    // for(auto a:tableH){cout<<a<<" ";}
    // cout<<endl;
    for(int i=0;i<n;i++){
        if(int(str[i])>=65 && int(str[i])<=91){//lowercase
            while(tableL[currL]==0){
                currL++;
            }
            str2[i]=char(65+currL);
            tableL[currL]--;
        }
        else{
            while(tableH[currH]==0){
                currH++;
            }
            str2[i]=char(97+currH);
            tableH[currH]--;
        }
    }
    return str2;
}

int main(){
    cout<<caseSort("defRTSersUXI",12)<<endl;
    cout<<caseSort("srbDKi",6)<<endl;
    return 0;
}