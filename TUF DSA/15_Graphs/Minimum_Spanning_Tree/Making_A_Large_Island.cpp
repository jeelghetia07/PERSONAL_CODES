#include<bits/stdc++.h>
using namespace std;

/*      LC = 827
    You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
    Return the size of the largest island in grid after applying this operation.
    An island is a 4-directionally connected group of 1s.
*/

class Disjoint{
public:
    vector<int> size, parent;
    Disjoint(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0 ; i <= n ;i++){
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
    bool isValid(int nr, int nc, int n){
        return (nr >= 0 && nr < n && nc >= 0 && nc < n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n*n);

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){

                if(grid[row][col] == 0) continue;

                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, 1, 0, -1};

                for(int i = 0 ; i < 4 ; i++){
                    int nr = row + delrow[i];
                    int nc = col + delcol[i];
                    
                    if(isValid(nr, nc, n)){
                        if(grid[nr][nc] == 1){
                            int nodeNo = (row*n) + col;
                            int adjNodeNo = (nr*n) + nc;

                            if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                                ds.unionBySize(nodeNo, adjNodeNo);
                            }
                        }
                    }
                }
            }
        }

        int maxi = 0;   // this is the total max component size after replacing 0 with 1.

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 1) continue;
                
                unordered_set<int> components;

                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, 1, 0, -1};

                for(int k = 0 ; k < 4 ; k++){
                    int nr = row + delrow[k];
                    int nc = col + delcol[k];
                    
                    if(isValid(nr, nc, n)){
                        if(grid[nr][nc] == 1){
                            int nodeNo = (row*n) + col;
                            int adjNodeNo = (nr*n) + nc;

                            components.insert(ds.findUPar(adjNodeNo));
                        }
                    }
                }

                int totalSize = 0;      //for the converted 0 to 1.
                for(auto it : components){
                    totalSize += ds.size[it];
                }
                maxi = max(maxi, totalSize+1);
            }
        }

        for(int cellNo = 0 ; cellNo < n*n ; cellNo++){
            maxi = max(maxi, ds.size[ds.findUPar(cellNo)]);
        }

        return maxi;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0},{0,1}};
    Solution obj;

    int ans = obj.largestIsland(grid);
    cout << "The ans is : " << ans;
}