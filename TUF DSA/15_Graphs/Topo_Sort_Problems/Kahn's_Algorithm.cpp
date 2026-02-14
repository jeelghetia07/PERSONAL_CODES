#include<bits/stdc++.h>
using namespace std;

/*
    Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges{}{}, where each entry edges{i} = {u, v} denotes a directed edge u -> v. Return the topological sort for the given graph.

    Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
*/

vector<int> topoSort(int V, vector<vector<int>>& edges){
    vector<vector<int>> adj(V);

    for(auto &e : edges){       // creating the adj list.
        adj[e[0]].push_back(e[1]);
    }

    vector<int> indegree(V, 0);
    for(int i = 0 ; i < V ; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // as node is in your topo sort....so plz remove it from the indegree.
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

int main(){
    vector<vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};
    vector<int> ans = topoSort(6, edges);

    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}