#include<bits/stdc++.h>
using namespace std;

/*  LC 685
    In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

    The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

    The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

    Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
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

    bool unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return false;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
        return true;
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    Disjoint ds(n+1);
    vector<int> indegreeParent(n+1, 0);
    vector<int> ans, cand1, cand2;

    for(auto &it : edges){
        int u = it[0];
        int v = it[1];

        if(indegreeParent[v] == 0){
            indegreeParent[v] = u;
        }
        else{
            cand1 = {indegreeParent[v], v};
            cand2 = {u, v};
        }
    }

    for(auto &e : edges){
        if(!cand2.empty() && e == cand2){
            continue;
        }
        int u = e[0], v = e[1];

        if(!ds.unionBySize(u,v)){
            if(cand1.empty())
                return e;
            else
                return cand1;
        }
    }
    return cand2;
}

int main(){
    vector<vector<int>> edges = {{2,1}, {3,1}, {4,2}, {1,4}};
}