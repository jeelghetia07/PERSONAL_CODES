#include<bits/stdc++.h>
using namespace std;

/*      LC = 1129
    You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

    You are given two arrays redEdges and blueEdges where:

    redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
    blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
    Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &e : redEdges){
            adj[e[0]].push_back({e[1], 0});     // pushing the nodes with the edge colors, and as its a directed graph we just push once.
        }

        for(auto &e : blueEdges){
            adj[e[0]].push_back({e[1], 1});
        }

        vector<int> ans(n, -1);     // initalized all dist with -1.
        vector<vector<int>> vis(n, vector<int>(2, 0));      // here a 2D vector becoz we can reach a node with both 0(red) and 1(blue) colors. 

        queue<tuple<int, int>> q;
        q.push({0, 0});         // pushing 0 twice cause we have to take both the color edges starting from 0 in all sides so if we want to go to 0->1 (1 "blue") then it will always come from {0, 0} = {node, initColor}.
        q.push({0, 1});

        vis[0][0] = 1;
        vis[0][1] = 1;

        ans[0] = 0;

        int dist = 0;       // the dist will keep increasing at each level.

        while(!q.empty()){
            int sz = q.size();
            dist++;     // we take all nodes at the same level once cause that BFS obviosly.

            for(int i = 0 ; i < sz ; i++){
                auto [node, initColor] = q.front();
                q.pop();

                for(auto it : adj[node]){
                    int v = it.first;
                    int edgeColor = it.second;

                    if(edgeColor != initColor && !vis[v][edgeColor]){           // the edgeColor shoud be diff from the pastEdgeColor(initColor) and should not be visited before with that paticular color.
                        q.push({v, edgeColor});
                        vis[v][edgeColor] = 1;
                        if(ans[v] == -1){       // once we reach a node it would definitely be the shortest path.
                            ans[v] = dist;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main(){
    /*
        n = 5
        redEdges = [[0,1], [1,2], [2,3], [3,4]]
        blueEdges = [[0,2], [1,3], [2,4], [0,1]]
    */

    return 0;
}