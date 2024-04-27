#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int src;
    int dest;
    long long int wt;
    Edge(int s,int d,long long int w):src(s),dest(d),wt(w){}
};

bool mycomp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}

bool find(int x,vector<int>&parent){
    if(x==parent[x]){return x;}
    parent[x]=find(x,parent);
    return parent[x];
}

void unionop(int x,int y,vector<int>&parent,vector<int>&rank){
    int x_rep=find(parent[x],parent);
    int y_rep=find(parent[y],parent);
    if(x_rep==y_rep){return;}
    if(rank[x_rep]<rank[y_rep]){ parent[x_rep]=y_rep; }
    else if(rank[y_rep]<rank[x_rep]){ parent[y_rep]=x_rep; }
    else{ 
        parent[y_rep]=x_rep;
        rank[x_rep]++;
    }
}

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m){
    vector<Edge>edges;
    for(int i=0;i<m;i++){
        for(auto v:adj[i]){
            if(v.first<v.second){
                Edge e=Edge(i,v.first,v.second);
                edges.push_back(e);
            }
        }
    }
    sort(edges.begin(),edges.end(),mycomp);
    
    vector<int>parent(n,0);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int totalEdges=0;
    long long int res=0;
    for(int i=0;i<edges.size();i++){
        if(totalEdges>=(n-1)){break;}
        int s_rep=find(edges[i].src,parent);
        int d_rep=find(edges[i].dest,parent);
        if(s_rep!=d_rep){
            res+=edges[i].wt;
            unionop(s_rep,d_rep,parent,rank);
            totalEdges++;
        }
    }
    return res;
}

int main(){
    //{(1,2,4),(1,3,3),(2,4,1),(2,5,1),(4,5,3),(3,4,2)}
    const int n=5;
    vector<pair<int, long long int>> adj[n];
    adj[0]={{1,4},{2,3}};
    adj[1]={{0,4},{3,1},{4,1}};
    adj[2]={{0,3},{3,2}};
    adj[3]={{2,1},{4,3},{2,2}};
    adj[4]={{1,1},{3,3}};
    cout<<kruskalDSU(adj,n,6);
    return 0;
}