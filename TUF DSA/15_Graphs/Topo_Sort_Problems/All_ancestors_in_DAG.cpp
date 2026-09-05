#include<bits/stdc++.h>
using namespace std;

/*      LC = 2192
    You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

    You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

    Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

    A node u is an ancestor of another node v if u can reach v via a set of edges.
*/

class Solution {
public:

                    // this is VERY VERY GOOD LOGIC, VERY SUPER.
                    /*
                        "Instead of starting from every possible ancestor and asking who can I reach?, I'll start from the target and walk backwards to find who could have reached me."
                    */


    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> allAnc(n);

        for(int i = 0; i < n; i++){
            queue<int> q;
            q.push(i);

            vector<bool> vis(n);

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int &next : adj[node]){
                    if(vis[next]) continue;
                    vis[next] = 1;
                    
                    allAnc[i].push_back(next);
                    q.push(next);
                }
            }
            sort(allAnc[i].begin(), allAnc[i].end());
        }
        return allAnc;
    }



                    // this is th TOPO sort problem type solution.


    // vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    //     vector<vector<int>> adj(n);

    //     for(auto &e : edges){
    //         adj[e[0]].push_back(e[1]);
    //     }

    //     vector<int> indegree(n, 0);
    //     for(int i = 0 ; i < n ; i++){
    //         for(auto it : adj[i]){
    //             indegree[it]++;
    //         }
    //     }

    //     queue<int> q;
    //     for(int i = 0 ; i < n ; i++){
    //         if(indegree[i] == 0) q.push(i);
    //     }

    //     vector<set<int>> ancestor(n);
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
            
    //         // here this means there is node ---> it.....means node is an ancestor of it.
    //         for(auto it : adj[node]){
    //             // node is an ancestor of it.
    //             ancestor[it].insert(node);

    //             // all ancestors of node are also ancestors of it.
    //             if(!ancestor[node].empty()){
    //                 for(int x : ancestor[node]){
    //                     ancestor[it].insert(x);
    //                 }
    //             }

    //             indegree[it]--;
    //             if(indegree[it] == 0) q.push(it);
    //         }
    //     }

    //     vector<vector<int>> vec(n);

    //     // now createing the final sorted array.
    //     for(int i = 0 ; i < n ; i++){
    //         vec[i] = vector<int>(ancestor[i].begin(), ancestor[i].end());
    //     }

    //     return vec;
    // }
};

int main(){
    /*
        Example 1:

        Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
        Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
        Explanation:
            The above diagram represents the input graph.
            - Nodes 0, 1, and 2 do not have any ancestors.
            - Node 3 has two ancestors 0 and 1.
            - Node 4 has two ancestors 0 and 2.
            - Node 5 has three ancestors 0, 1, and 3.
            - Node 6 has five ancestors 0, 1, 2, 3, and 4.
            - Node 7 has four ancestors 0, 1, 2, and 3.


        Example 2:

        Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
        Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
        Explanation:
            The above diagram represents the input graph.
            - Node 0 does not have any ancestor.
            - Node 1 has one ancestor 0.
            - Node 2 has two ancestors 0 and 1.
            - Node 3 has three ancestors 0, 1, and 2.
            - Node 4 has four ancestors 0, 1, 2, and 3.
        

        Constraints:

        1 <= n <= 1000
        0 <= edges.length <= min(2000, n * (n - 1) / 2)
        edges[i].length == 2
        0 <= fromi, toi <= n - 1
        fromi != toi
        There are no duplicate edges.
        The graph is directed and acyclic.
    */

    return 0;
}