#include<bits/stdc++.h>
using namespace std;

/*
    You are given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an undirected edge between vertices u and v.

    Your task is to find the shortest path distance from a given source vertex src to all other vertices in the graph.
    If a vertex is not reachable from the source, return -1 for that vertex.

    Note: All edges have unit weight (1).
*/

vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) { 
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<int> vis(V, INT_MAX);
    vis[src] = 0;
    
    queue<int> q;    // node
    q.push(src);
    
    while(!q.empty()){
        int node = q.front();
        int dist = vis[node];
        q.pop();
        
        for(auto it : adj[node]){
            if(vis[it] == INT_MAX){
                vis[it] = vis[node]+1;
                q.push(it);
            }
        }
    }
    
    for(int i = 0 ; i < V ; i++){
        if(vis[i] == INT_MAX){
            vis[i] = -1;
        }
    }
    return vis;
}

int main(){
    int V = 9, E = 10;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 4}, {4, 5}, {2, 6}, {5, 6}, {6, 7}, {6, 8}, {7, 8}};
    int src = 0;

    vector<int> ans = shortestPath(V, edges, src);

    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}