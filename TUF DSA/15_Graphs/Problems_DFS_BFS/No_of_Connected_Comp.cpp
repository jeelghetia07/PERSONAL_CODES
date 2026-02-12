#include<bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Given an undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by [ai,bi], denoting a edge between vertex ai and bi. We say two vertices u and v belong to a same component if there is a path from u to v or v to u. Find the number of connected components in the graph.

    A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
*/

class COMPONENTS{
public:
    int CountComponents(int V, vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(auto &e : edges){                // e might be like {0,1}, {1,2}, {3,4}.
            adj[e[0]].push_back(e[1]);     // here the 0 and 1 denotes the index ...the [row][col]....which nodes have edges between them.
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V,0);
        int comp = 0;

        for(int i = 0 ; i < V ; ++i){
            if(!vis[i]){
                comp++;

                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto &nbr : adj[node]){
                        if(!vis[nbr]){
                            vis[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        return comp;
    }
};

int main(){
    int V = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    COMPONENTS obj;
    cout << "Number of Connected Components : " << obj.CountComponents(V,edges) << endl;
    return 0;
}