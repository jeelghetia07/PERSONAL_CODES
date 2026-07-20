#include<bits/stdc++.h>
using namespace std;

/*      LC = 797
    Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

    The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/

class Solution {
public:
    void dfs(int node, vector<int>& path, vector<vector<int>>& adj, vector<vector<int>>& ans, int finalNode){
        path.push_back(node);       // pushing the node, everytime we encounter a new node.

        if(node == finalNode){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(auto v : adj[node]){
            dfs(v, path, adj, ans, finalNode);
        }

        path.pop_back();        // this to remove each ele added at every recursive stage.

        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj){
        int n = adj.size();

        vector<vector<int>> ans;
        vector<int> path;       // path vec.

        dfs(0, path, adj, ans, n-1);

        return ans;
    }




                        // BFS method.


    // vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
    //     int n = adj.size();

    //     // adj list is already given.
    //     vector<vector<int>> ans;        // for storing the ans.

    //     // There is no use of vis becoause if we use it, then once we reach the n-1 node, it will marked vis and we cannot vis it other time.

    //     queue<pair<int, vector<int>>> q;        // this will store the particular path node and vec path.

    //     vector<int> temp;       // the path vector.
    //     temp.push_back(0);

    //     q.push({0, temp});      

    //     while(!q.empty()){
    //         auto it = q.front();
    //         q.pop();

    //         int node = it.first;
    //         auto vec = it.second;

    //         if(node == n-1){
    //             ans.push_back(vec);
    //         }

    //         for(auto neighbourNode : adj[node]){
    //             vector<int> path = vec;     // this creates a copy of vec everytime for a new node.
    //             path.push_back(neighbourNode);
    //             q.push({neighbourNode, path});
    //         }
    //     }
    //     return ans;
    // }
};

int main(){
    /*
        Input: graph = [[1,2],[3],[3],[]]
        Output: [[0,1,3],[0,2,3]]
        Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.


        Example 2:

        Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
        Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 
    */

    return 0;
}