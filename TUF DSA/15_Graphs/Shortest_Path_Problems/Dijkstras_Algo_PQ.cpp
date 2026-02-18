// Dijkstra's_Algo_PQ.cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int, int>>> adj(V);
    
    for(auto &e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    
    // pq format is : priority_queue<Type, Container, Comparator>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dist(V, 1e9);
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(d > dist[node]) continue;
        
        for(auto it : adj[node]){
            int weight = it.second;
            int neighbour = it.first;
            
            if(d + weight < dist[neighbour]){
                dist[neighbour] = d + weight;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
    
    return dist;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    int src = 0;

    vector<int> ans = dijkstra(V, edges, src);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}