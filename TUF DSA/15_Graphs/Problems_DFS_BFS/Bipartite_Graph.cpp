#include<bits/stdc++.h>
using namespace std;

bool dfs(int n, int col, vector<int>& vis, vector<vector<int>>& adj){
    vis[n] = col;

    for(auto it : adj[n]){
        if(vis[it] == -1){
            dfs(it, !col, vis, adj);
        }
        else if(vis[it] == vis[n]) return false;
    }
    return true;
}

bool bfs(int n, vector<int>& vis, vector<vector<int>>& adj){
    vis[n] = 1;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbour : adj[node]){
            if(vis[neighbour] == -1){
                vis[neighbour] = 1 - vis[node];
                q.push(neighbour);
            }
            else if(vis[neighbour] == vis[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph){
    int n = graph.size();

    vector<int> vis(n, -1);

    // for(int i = 0 ; i < n ; i++){
    //     if(vis[i] == -1){
    //         if(!bfs(i, vis, graph)) return false;
    //     }
    // }
    for(int i = 0 ; i < n ; i++){
        if(vis[i] == -1){
            if(!dfs(i, 0, vis, graph)) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    if(isBipartite(graph)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}