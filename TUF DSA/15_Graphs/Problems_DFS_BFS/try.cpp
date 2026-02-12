#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], int vis[]){
    vis[node] = 1;
    for(auto neighbour : adj[node]){
        if(!vis[neighbour]){
            if((dfs(neighbour, node, adj, vis) == true)) return true;
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    int vis[V] = {0};

    for(int i = 0 ; i < V ; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis) == true) return true;
        }
    }
    return false;
}

int main(){
    vector<int> adj[4] = {{}, {2, 3}, {1, 3}, {1, 2}};      
    cout << isCycle(4, adj);
    return 0;
}