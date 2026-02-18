#include<bits/stdc++.h>
using namespace std;

/*
    You are given an undirected weighted graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where edges[i] = [ui, vi, timei] means that there is an undirected edge between nodes ui and vi that takes timei minutes to reach.
    Your task is to return in how many ways you can travel from node 0 to node V - 1 in the shortest amount of time.
*/

int countPaths(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(V);
    
    for(auto &e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    
    vector<int> dist(V, 1e9);
    vector<int> ways(V, 0);
    
    dist[0] = 0;
    ways[0] = 1;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});    // {dis, node}
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int dis = it.first;
        int node = it.second;
        
        for(auto v : adj[node]){
            int ver = v.first;
            int edw = v.second;
            
            if(edw + dis < dist[ver]){  // this is the first occurence i found a node having shorter distance.
                dist[ver] = edw + dis;
                pq.push({dist[ver], ver});
                ways[ver] = ways[node];
            }
            else if(edw + dis == dist[ver]){    // i found a path having same dis so ways will increase.
                ways[ver] += ways[node];
            }
        }
    }
    
    return ways[V-1];
}

int main(){

}