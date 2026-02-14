#include<bits/stdc++.h>
using namespace std;

/*
    Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges{}{}, where each entry edges{i} = {u, v} denotes a directed edge u -> v. Return the topological sort for the given graph.

    Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
*/

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
    vis[node] = 1;
    
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);      // after completing every dfs call....store the ans in the stack.
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);

    for(auto &e : edges){       // creating the adj list.
        adj[e[0]].push_back(e[1]);
    }
    
    stack<int> st;
    vector<int> vis(V, 0);
    
    for(int i = 0 ; i < V ; i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }
    
    vector<int> ans;
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    vector<vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};
    vector<int> ans = topoSort(6, edges);

    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}