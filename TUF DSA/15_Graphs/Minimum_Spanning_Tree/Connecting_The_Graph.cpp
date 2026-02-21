#include<bits/stdc++.h>
using namespace std;

/*      similar to LC = 1319
    You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to connect the graph.
    If it is not possible to connect the graph, return -1.
*/

class Disjoint{
public:
    vector<int> parent, size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0 ; i < n ; i++){
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

        // if both the ultimate parents are diff then we compare teh size and attach the smaller one into the larger one.

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        Disjoint ds(n);
        int cntExtra = 0;
        
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            
            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtra++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntComp = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(ds.parent[i] == i) cntComp++;
        }
        
        if(cntExtra >= cntComp-1) return cntComp-1;
        return -1;
    }
};

int main(){
    int n = 4,m = 3;
    vector<vector<int>> edge = {{0, 1} , {0, 2} , {1, 2}};

    Solution obj;

    int ans = obj.Solve(n, edge);
    cout  << "The edges used to connect all the components are : " << ans;
    return 0;
}