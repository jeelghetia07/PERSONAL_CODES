#include<bits/stdc++.h>
using namespace std;

/*      LC = 695
    You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    The area of an island is the number of cells with a value 1 in the island.
    Return the maximum area of an island in grid. If there is no island, return 0.
*/

class Disjoint{
public:
    vector<int> parent, size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);    // initially all nodes are parent of themselves and having size 1

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
    bool isValid(int nr, int nc, int n, int m){
        return (nr >= 0 && nr < n && nc >= 0 && nc < m);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {        // This is somewhat time taking....so we better use the DFS method....it takes lesser time.
        int n = grid.size();
        int m = grid[0].size();

        Disjoint ds(n*m);

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 0) continue;

                for(int i = 0 ; i < 4 ; i++){
                    int nr = row + delrow[i];
                    int nc = col + delcol[i];

                    if(isValid(nr, nc, n, m) && grid[nr][nc] == 1){
                        int nodeNo = (row*m) + col;
                        int adjNodeNo = (nr*m) + nc;

                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }


        int maxArea = INT_MIN;

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 1){
                    int nodeNo = (row*m) + col;
                    int tempArea = ds.size[nodeNo];
                    maxArea = max(maxArea, tempArea);
                }
            }
        }

        if(maxArea == INT_MIN) return 0;
        return maxArea;
    }
};

int main(){
    /*
        Input: grid =   [[0,0,1,0,0,0,0,1,0,0,0,0,0],
                        [0,0,0,0,0,0,0,1,1,1,0,0,0],
                        [0,1,1,0,1,0,0,0,0,0,0,0,0],
                        [0,1,0,0,1,1,0,0,1,0,1,0,0],
                        [0,1,0,0,1,1,0,0,1,1,1,0,0],
                        [0,0,0,0,0,0,0,0,0,0,1,0,0],
                        [0,0,0,0,0,0,0,1,1,1,0,0,0],
                        [0,0,0,0,0,0,0,1,1,0,0,0,0]];
        Output: 6
    */

    return 0;
}