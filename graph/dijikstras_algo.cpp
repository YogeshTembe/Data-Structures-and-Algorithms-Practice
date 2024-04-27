#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

const int V=9;

int minDistanceNode(int dist[],bool sptset[]){
    int minDist=INT_MAX;
    int minIdx = -1;
    for(int i=0;i<V;i++){
        if(!sptset[i] && dist[i]<minDist){
            minDist = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void dijkstra1(int src,int graph[][V]){
    bool sptset[V];
    int dist[V];
    for(int i=0;i<V;i++){
        sptset[i]=false;
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int minDistNode=minDistanceNode(dist,sptset);
        sptset[minDistNode] = true;
        cout<<minDistNode<<endl;
        for(int j=0;j<V;j++){//neighbors
            if(!sptset[j] && graph[minDistNode][j]!=0 && dist[j]>(dist[minDistNode]+graph[minDistNode][j])){
                dist[j]=dist[minDistNode]+graph[minDistNode][j];
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}


void printpriorityqueue(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq){
    while(!pq.empty()){
        cout<<pq.top().first<<"-"<<pq.top().second<<" ";
        pq.pop();
    }
    cout<<endl;
}
//using priority queue 
void dijkstra2(int src,int graph[][V]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//dist,node
    //priority_queue<pair<int,int>>pq;
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    pq.push({dist[src],src});
    while(!pq.empty()){
        printpriorityqueue(pq);
        int minDistnode=pq.top().second;
        cout<<minDistnode<<" "<<dist[minDistnode]<<endl;
        pq.pop();
        for(int i=0;i<V;i++){//neighbors
            if(graph[minDistnode][i] != 0 && dist[i]>dist[minDistnode]+graph[minDistnode][i]){
                dist[i] = dist[minDistnode]+graph[minDistnode][i];
                pq.push({dist[i],i}); 
                //priority queue will have duplicates because there is no way we can remove somthing from priority queue, it has only pop method.
                //but we don't have to worry about duplicates in pq, because at the end we take dist[minDistnode] from dist array and not from pq.
                //so because of duplicates it will have a extra iteration but it will not affect the result
                //to avoid this we can use set instead of priority queue
            }
        }
    }
    //output
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}

//using set
void dijkstra3(int src,int graph[][V]){
    set<pair<int,int>>s;//dist,node
    s.insert({src,0});
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    while(!s.empty()){
        int minDistNode = (s.begin())->second;
        s.erase(s.begin());
        for(int i=0;i<V;i++){
            if(graph[minDistNode][i]!=0 && dist[i]>dist[minDistNode]+graph[minDistNode][i]){
                if(dist[i]!=INT_MAX){
                    s.erase({dist[i],i});
                }
                dist[i]=dist[minDistNode]+graph[minDistNode][i];
                s.insert({dist[i],i});
            }
        }
    }

    //output
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra3(0,graph);
    return 0;
}