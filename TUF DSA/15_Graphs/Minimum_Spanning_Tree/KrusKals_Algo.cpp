#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int> rank, parent, size;
public:
    Disjoint(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){      // here i have done the path compression....connected the node to the ultimate parent.
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{       // if both rank are same then we can attach any one with the other.
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{   // if its equal or greater than...we still attach it...then why to write the else if then else..so we are combining both.
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
  public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        Disjoint ds(V);
        // O(mlogm)
        sort(edges.begin(), edges.end(), comp);
        
        
        int mstwt = 0;
        // O(m*4*alpha)
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(ds.findUParent(u) != ds.findUParent(v)){
                mstwt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
};

int main(){
    int V = 3, E = 3;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};

    Solution obj;

    int sum = obj.spanningTree(V, edges);
    cout << "The minimum sum is : " << sum << endl;

    return 0;
}