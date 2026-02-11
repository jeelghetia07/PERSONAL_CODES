#include<bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res){
    vis[node] = 1;
    res.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfsHelper(it, adj, vis, res);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> vis(n, 0);
    vector<int> res;

    dfsHelper(1, adj, vis, res);
    return res;  
}

void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    vector<vector<int>> adj(9);

    addEdge(adj, 1,2);
    addEdge(adj, 2,5);
    addEdge(adj, 2,6);
    addEdge(adj, 1,3);
    addEdge(adj, 3,4);
    addEdge(adj, 4,8);
    addEdge(adj, 8,7);
    addEdge(adj, 7,3);

    vector<int> ans = dfs(adj);

    for(int x : ans){
        cout << x << " ";
    }
}