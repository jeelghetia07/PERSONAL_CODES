// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

#include<bits/stdc++.h>
using namespace std;

class REPLACE{
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat){
        vis[row][col] = 1;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, mat);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){    // m = rows, n = cols.
        vector<vector<int>> vis(n, vector<int>(m,0));
        // traverse the boundaries first...
        // first and last row.
        for(int j = 0 ; j < m ; j++){
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0, j, vis, mat);
            }
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1, j, vis, mat);
            }
        }
        // first and last col.
        for(int i = 0 ; i < n ; i++){
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0, vis, mat);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, vis, mat);
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat; 
    }
};

int main() {
    // sample board
    vector<vector<char>> mat{
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };

    REPLACE ob;

    vector<vector<char>> ans = ob.fill(mat.size(), mat[0].size(), mat);
    // printing board
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}