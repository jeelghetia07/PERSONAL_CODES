#include<bits/stdc++.h>
using namespace std;

/*      LC = 329
    Given an m x n integers matrix, return the length of the longest increasing path in matrix.

    From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
*/

class Solution {
public:
    bool isValid(int nr, int nc, int n, int m){
        return (nr >= 0 && nr < n && nc >= 0 && nc < m);
    }
    int dfs(int row, int col, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp){
        if(dp[row][col] != -1) return dp[row][col];

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int maxLen = 1;

        for(int i = 0 ; i < 4 ; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if(isValid(nr, nc, n, m) && (grid[nr][nc] > grid[row][col])){
                maxLen = max(maxLen, 1 + dfs(nr, nc, grid, n, m, dp));
            }
        }

        return dp[row][col] = maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                maxi = max(maxi, dfs(row, col, grid, n, m, dp));
            }
        }

        return maxi;
    }
};

int main(){
    /*
        Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
        Output: 4
        Explanation: The longest increasing path is [1, 2, 6, 9].
    */

    return 0;
}