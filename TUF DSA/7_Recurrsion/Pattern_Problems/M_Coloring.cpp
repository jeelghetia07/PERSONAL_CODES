#include<bits/stdc++.h>
using namespace std;

/*      LC = 
    You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.
    Note: The graph is indexed with 0-based indexing.
*/

class Solution {
  public:
    bool isColoringPossible(int node, int col, vector<vector<int>>& adj, vector<int>& color){
        for(auto neighbour : adj[node]){
            if(color[neighbour] == col) return false;
        }
        return true;
    }
    bool func(int node, vector<vector<int>>& adj, vector<int>& color, int m, int v){
        if(node == v) return true;
        
        for(int col = 1 ; col <= m ; col++){
            if(isColoringPossible(node, col, adj, color)){
                color[node] = col;
                if(func(node+1, adj, color, m, v)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> color(v, 0);        // initailizing to 0 colors.
        
        if(func(0, adj, color, m, v)) return true;
        return false;
    }
};

int main(){
    int V = 4, m = 3;
    vector<vector<int>> edges = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]]; // true;

    return 0;
}