// Cycle_in_Directed.cpp
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& Pathvis){
    vis[node] = 1;
    Pathvis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it, adj, vis, Pathvis)) return true;
        }
        // if the node has been previously visited but it has to be visited on the same path
        else if(Pathvis[it]){
            return true;
        }
    }

    Pathvis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges){
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
    }
    
    int n = adj.size();
    
    vector<int> vis(V, 0);
    vector<int> Pathvis(V, 0);

    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, Pathvis)) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    int V = 4;

    if(isCyclic(V, edges)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}