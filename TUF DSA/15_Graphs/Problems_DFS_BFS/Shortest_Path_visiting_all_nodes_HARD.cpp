#include<bits/stdc++.h>
using namespace std;

/*      LC = 847
    You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

    Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;

        int finalstate = (1 << n) - 1;      // suppose 4 nodes are there, then 1 << 4 = 10000 - 1 = 1111.

        queue<pair<int, int>> q;
        // [no of many nodes][each node may have 2^n states]          ..... [currentNode][visited state].       // if this repeats means we went from 0 -> 1 -> 0 -> 1, this will have [0][0001].

        // {node , pathMask}.
        set<pair<int, int>> vis;

        // adding all the nodes initially cause we can start anywhere.
        for(int i = 0 ; i < n ; i++){
            q.push({i, 1 << i});            // this will give 0001 (visited node 0 only), 0010 (vis node 1 only), etc. 
            vis.insert({i, 1 << i});
        }

        int path = 0;

        while(!q.empty()){
            int size = q.size();
            path++;

            // checking all nodes from one particular node.
            while(size--){
                auto it = q.front();
                q.pop();

                int currNode = it.first;
                int currMask = it.second;

                for(auto &ngh : graph[currNode]){
                    int nextMask = currMask | (1 << ngh);
                    if(nextMask == finalstate) return path;

                    if(vis.find({ngh, nextMask}) == vis.end()){
                        vis.insert({ngh, nextMask});
                        q.push({ngh, nextMask});
                    }
                }
            }
        }

        return -1;
    }
};

int main(){
    /*
        Input: graph = [[1,2,3],[0],[0],[0]]
        Output: 4
        Explanation: One possible path is [1,0,2,0,3]


        Example 2:

        Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
        Output: 4
        Explanation: One possible path is [0,1,4,2,3]
    */

    return 0;
}