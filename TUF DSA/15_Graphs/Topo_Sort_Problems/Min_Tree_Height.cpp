#include<bits/stdc++.h>
using namespace std;

/*      LC = 310
    A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

    Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

    Return a list of all MHTs' root labels. You can return the answer in any order.

    The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 1) q.push(i);
        }

        int remainingNodes = n;

        while(remainingNodes > 2){
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
    /*
        Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
        Output: [3,4]
    */

    return 0;
}