#include<bits/stdc++.h>
using namespace std;

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

int numProvinces(vector<vector<int>> adj, int V){   // here is an adj matrix not a list.
    Disjoint ds(V);

    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            if(adj[i][j] == 1){
                ds.unionBySize(i,j);
            }
        }
    }

    int cnt = 0;

    for(int i = 0 ; i < V ; i++){
        if(ds.findUPar(i) == i) cnt++;      // this shows that anew component has started.
    }
    return cnt;
}

int main(){
    vector<vector<int>> adj = {{1, 0, 1},{0, 1, 0},{1, 0, 1}};
    int ans = numProvinces(adj, adj.size());

    cout << "The number of provinces are : " << ans;
    return 0;
}