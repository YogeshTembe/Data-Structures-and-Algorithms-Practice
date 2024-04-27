#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;

vector<string> winner(string arr[],int n)
{
    // Your code here
    // Return the string containing the name and an integer
    // representing the number of votes the winning candidate got
    unordered_map<string,int>votes;
    int maxVotes=INT_MIN;
    for(int i=0;i<n;i++){
        votes[arr[i]]++;
        if(votes[arr[i]]>maxVotes){
            maxVotes=votes[arr[i]];
        }
    }
    set<string>people;
    for(auto it=votes.begin();it!=votes.end();it++){
        if(it->second==maxVotes){
            people.insert(it->first);
        }
    }
    vector<string>res{*people.begin(),std::to_string(maxVotes)};
    return res;
}

int main(){
/*
Input:
n = 13
Votes[] = {john,johnny,jackie,johnny,john 
jackie,jamie,jamie,john,johnny,jamie,
johnny,john}
Output: john 4

*/
    return 0;
}