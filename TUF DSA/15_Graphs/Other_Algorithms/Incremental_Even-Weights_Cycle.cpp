#include<bits/stdc++.h>
using namespace std;

/*      LC = 3887
    You are given a positive integer n.
    There is an undirected graph with n nodes labeled from 0 to n - 1. Initially, the graph has no edges.
    You are also given a 2D integer array edges, where edges[i] = [ui, vi, wi] represents an edge between nodes ui and vi with weight wi. The weight wi is either 0 or 1.

    Process the edges in edges in the given order. For each edge, add it to the graph only if, after adding it, the sum of the weights of the edges in every cycle in the resulting graph is even.

    Return an integer denoting the number of edges that are successfully added to the graph.
*/

class Disjoint{
    vector<int> parent, size, parity;
public:
    Disjoint(int n){
        parent.resize(n);
        size.resize(n, 1);
        parity.resize(n, 0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] != node){
            int org_par = parent[node];
            parent[node] = findUPar(parent[node]);
            parity[node] ^= parity[org_par];
        }
        return parent[node];
    }

    bool canAttach(int u, int v, int wt){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
            return ((parity[u] ^ parity[v] ^ wt) == 0);
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            parity[ulp_u] = parity[u] ^ parity[v] ^ wt;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            parity[ulp_v] = parity[u] ^ parity[v] ^ wt;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
};

class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        
        Disjoint ds(n);
        int edgesCount = 0;
        
        for(auto &it : edges){
            int u = it[0], v = it[1], wt = it[2];

            if(ds.canAttach(u,v,wt)){
                edgesCount++;
            }
        }

        return edgesCount;
    }
};

int main(){
    /*
        Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,1]]
        Output: 2

        Explanation:

        [0, 1, 1]: We add the edge between vertex 0 and vertex 1 with weight 1.
        [1, 2, 1]: We add the edge between vertex 1 and vertex 2 with weight 1.
        [0, 2, 1]: The edge between vertex 0 and vertex 2 (the dashed edge in the diagram) is not added because the cycle 0 - 1 - 2 - 0 has total edge weight 1 + 1 + 1 = 3, which is an odd number.



        Example 2:

        Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,0]]
        Output: 3

        Explanation:

        [0, 1, 1]: We add the edge between vertex 0 and vertex 1 with weight 1.
        [1, 2, 1]: We add the edge between vertex 1 and vertex 2 with weight 1.
        [0, 2, 0]: We add the edge between vertex 0 and vertex 2 with weight 0.
        Note that the cycle 0 - 1 - 2 - 0 has total edge weight 1 + 1 + 0 = 2, which is an even number.
    */

    return 0;
}