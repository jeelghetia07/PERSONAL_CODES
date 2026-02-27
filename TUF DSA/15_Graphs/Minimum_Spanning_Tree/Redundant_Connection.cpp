#include<bits/stdc++.h>
using namespace std;

/*      LC 684
    In this problem, a tree is an undirected graph that is connected and has no cycles.

    You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

    Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
*/

class Disjoint{
public:
    vector<int> size, parent;
    Disjoint(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};


vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    Disjoint ds(n+1);

    vector<int> ans;

    for(auto &it : edges){
        int u = it[0];
        int v = it[1];

        int ulp_u = ds.findUPar(u);
        int ulp_v = ds.findUPar(v);

        if(ulp_u == ulp_v){
            ans.push_back(u);
            ans.push_back(v);
        }
        else{
            ds.unionBySize(u, v);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};        // ans = [1,4]
}