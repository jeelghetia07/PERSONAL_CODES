#include<bits/stdc++.h>
using namespace std;

/*     GFG
    You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
    Note : An island means group of 1s such that they share a common side.
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

bool isValid(int nr, int nc, int n, int m){
    return nr >= 0 && nr < n && nc >= 0 && nc < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &grid){
    Disjoint ds(n*m);       // creating all nodes of the matrix..
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    vector<int> ans;

    for(auto it : grid){
        int row = it[0];
        int col = it[1];

        if(vis[row][col] == 1){
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;      // firstly counting each cell as an indv island....

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0 ; i < 4 ; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(isValid(nr, nc, n, m)){
                if(vis[nr][nc] == 1){
                    int nodeNo = (row*m) + col;
                    int adjnodeNo = (nr*m) + nc;

                    if(ds.findUPar(nodeNo) != ds.findUPar(adjnodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main(){
    int n = 4, m = 5, k = 4;
    vector<vector<int>> grid = {{1,1},{0,1},{3,3},{3,4}};       // ans = 1 1 2 2

    vector<int> ans = numOfIslands(n, m, grid);     
    return 0;
}