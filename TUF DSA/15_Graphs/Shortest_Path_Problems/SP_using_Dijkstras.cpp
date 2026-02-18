#include<bits/stdc++.h>
using namespace std;

/*
    Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
    You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

    Note : The Graph is connected and doesn't contain any negative weight edge.
    It is guaranteed that all the shortest distance will fit in a 32-bit integer.
*/

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n+1);
    
    for(auto &e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;            
    pq.push({0, 1});
    
    vector<int> vis(n+1, 1e9);
    vis[1] = 0;
    vector<int> parent(n+1);
    
    for(int i = 0 ; i <= n ; i++){
        parent[i] = i;
    }
    
    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int dist = it.first;
        pq.pop();
        
        if(dist > vis[node]) continue;
        
        for(auto v : adj[node]){
            int ver = v.first;
            int d = v.second;
            
            if(dist + d < vis[ver]){
                vis[ver] = dist + d;
                parent[ver] = node;
                pq.push({vis[ver], ver});
            }
        }
    }
    
    if(vis[n] == 1e9) return {-1};
    
    vector<int> path;
    int node = n;
    
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    
    reverse(path.begin(), path.end());

    cout << "The max weight to reach n is : " << vis[n] << endl;
    
    return path;
}

int main(){
    int n = 5, m= 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    vector<int> ans = shortestPath(n, m, edges);

    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}