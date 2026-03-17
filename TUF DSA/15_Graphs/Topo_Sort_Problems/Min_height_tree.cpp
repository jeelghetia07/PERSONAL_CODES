#include<bits/stdc++.h>
using namespace std;

/*      GFG
    You are given an undirected graph, which has tree characteristics with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element edges[i] = [u, v] represents an edge from vertex u to v.
    You can choose any vertex as the root of the tree. Your task is to find all the vertices that, when chosen as the root, result in the minimum possible height of the tree.
    Note: The height of a rooted tree is defined as the maximum number of edges on the path from the root to any leaf node.
*/

class Solution {
  public:
    vector<int> minHeightRoot(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        vector<int> indegree(v+1, 0);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        // for(auto it : adj){
        //     for(auto ver : it){
        //         indegree[ver]++;
        //     }
        // }
        
        queue<int> q;
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 1) q.push(i);
        }

        int remainingNodes = v;
        
        while(remainingNodes > 2){      // greater than 2 because the tree length can be even then 2 nodes and then odd in 1 node
            int sz = q.size();
            remainingNodes -= sz;
            
            for(int i = 0 ; i < sz ; i++){
                int node = q.front();
                q.pop();
                
                for(auto neighbour : adj[node]){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 1) q.push(neighbour);
                }
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
        }
        return ans;
    }
};

int main(){
    int V = 5, E = 4;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {2, 3}, {3, 4}};       //  [2, 3]

    return 0;
}