#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
    A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/

class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<int> adj[], int v){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, v);
            }
        }
    }
    int findMotherVertex(int v, vector<int> adj[]) {
        vector<int> vis(v, 0);
        int candidate = -1;
        
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                dfs(i, vis, adj, v);
                candidate = i;
            }
        }
        
        vector<int> check(v, 0);
        dfs(candidate, check, adj, v);
        
        for(int i = 0 ; i < v ; i++){
            if(!check[i]) return -1;
        }
        return candidate;
    }
};

int main(){
    vector<int> adj[] = {{2,3}, {0}, {1}, {4}, {}};       // ans minimum vertex is 0.

    return 0;
}