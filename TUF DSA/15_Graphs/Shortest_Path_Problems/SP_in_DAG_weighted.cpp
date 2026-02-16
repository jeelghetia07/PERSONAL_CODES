#include<bits/stdc++.h>
using namespace std;

/*
    Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
    Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/

// void toposort_DFS(int node, vector<int>& vis, vector<vector<pair<int, int>>>& adj, stack<int>& st){        // we are doing topo sort becoz....in that we start from a node which has no previous....so from that we can know other nodes distance.....so accordingly.....if not understood.....go to the video lec
//     vis[node] = 1;
    
//     for(auto it : adj[node]){
//         int v = it.first;
//         if(!vis[v]){
//             toposort_DFS(v, vis, adj, st);
//         }
//     }
//     st.push(node);
// }

// vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
//     vector<vector<pair<int, int>>> adj(V);
    
//     for(auto &e : edges){
//         adj[e[0]].push_back({e[1], e[2]});
//     }
    
//     vector<int> vis(V, 0);
//     stack<int> st;
    
//     for(int i = 0 ; i < V ; i++){       // this runs for all components;        TC = O(v+e);
//         if(!vis[i]){
//             toposort_DFS(i, vis, adj, st);
//         }
//     }
    
//     vector<int> dist(V, INT_MAX);
//     dist[0] = 0;
    
//     while(!st.empty()){     // this will run for the total N nodes...O(N)..read down.....hence.....TC = O(v+e);
//         int node = st.top();
//         st.pop();
        
//         for(auto it : adj[node]){       // this will run for all the edges...means O(E)...
//             int v = it.first;
//             int d = it.second;
            
            
//             if(dist[node] != INT_MAX){
//                 if(dist[node] + d < dist[v]){
//                     dist[v] = dist[node] + d;
//                 }
//             }
//         }
//     }
    
//     for(int i = 0 ; i < V ; i++){
//         if(dist[i] == INT_MAX) dist[i] = -1;
//     }
//     return dist;
// }



            // BFS( KAHN'S ALGORITHM )

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges){
    vector<vector<pair<int,int>>> adj(V);

    for(auto &e : edges){
        adj[e[0]].push_back({e[1], e[2]});
    }
    
    vector<int> indegree(V, 0);
    
    for(int i = 0 ; i < V ; i++){
        for(auto it : adj[i]){
            int v = it.first;
            indegree[v]++;
        }
    }
    
    queue<int> q;
    
    for(int i = 0 ; i < V ; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> dis(V, INT_MAX);
    dis[0] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(dis[node] != INT_MAX){       // if i have a node 5 --> 7 has a wiegth of 3....but node 5 has no connection with 0..then the distance should be INT_MAX.
            for(auto it : adj[node]){
                int v = it.first;
                int d = it.second;
                
                if(dis[v] == INT_MAX){
                    dis[v] = dis[node] + d;
                }
                else{
                    dis[v] = min(dis[v], dis[node] + d);
                }
            }
        }
        
        for(auto it : adj[node]){
            int v = it.first;
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
    
    for(int i = 0 ; i < V ;i++){
        if(dis[i] == INT_MAX) dis[i] = -1;
    }
    
    return dis;
}

int main(){
    int V = 6, E = 7;
    vector<vector<int>> edges = {{0,1,2}, {0,4,1}, {4,5,4}, {4,2,2}, {1,2,3}, {2,3,6}, {5,3,1}};

    vector<int> dis = shortestPath(V, E, edges);
    
    for(auto it : dis){
        cout << it << " "; 
    }
    return 0;
}