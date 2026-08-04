#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.
*/

class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        
        st.push(node);
    }
    
    
    void dfs3(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) dfs3(it, vis, adj);
        }
        
        return ;
    }
    
    
    int kosaraju(int n, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        stack<int> st;
        
        // doing the normal dfs.
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        // reverse the graph
        vector<vector<int>> adjT(n);
        
        for(int i = 0 ; i < n ; i++){
            vis[i] = 0;         // this is for again doing the dfs.
            for(auto it : adj[i]){      // this means that there is an edge from i->it
                adjT[it].push_back(i);
            }
        }
        
        int cnt = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                cnt++;
                dfs3(node, vis, adjT);
            }
        }
        
        return cnt;
    }
};

int main(){
    /*
        V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]
        Output: 3
        Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

        
        Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]
        Output: 1
        Explanation: All of the nodes are connected to each other. So, there's only one SCC.

        
        Input: V = 2, E = 1, edges[][] = [[0, 1]]
        Output: 2
    */

    return 0;
}