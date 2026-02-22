#include<bits/stdc++.h>
using namespace std;

/*      // LC = 2304...nice ques.....if not understand ask gpt.
    You are given a 0-indexed m x n integer matrix grid consisting of distinct integers from 0 to m * n - 1. You can move in this matrix from a cell to any other cell in the next row. That is, if you are in cell (x, y) such that x < m - 1, you can move to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). Note that it is not possible to move from cells in the last row.

    Each possible move has a cost given by a 0-indexed 2D array moveCost of size (m * n) x n, where moveCost[i][j] is the cost of moving from a cell with value i to a cell in column j of the next row. The cost of moving from cells in the last row of grid can be ignored.

    The cost of a path in grid is the sum of all values of cells visited plus the sum of costs of all the moves made. Return the minimum cost of a path that starts from any cell in the first row and ends at any cell in the last row.
*/


                    // MEMOIZATION APPROACH


// int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp){
//     int n = grid.size();
//     int m = grid[0].size();

//     if(i == n-1){
//         return grid[i][j];
//     }

//     if(dp[i][j] != -1) return dp[i][j];

//     int minCost = 1e8;

//     for(int nextColumn = 0 ; nextColumn < m ; nextColumn++){
//         int move_cost = moveCost[grid[i][j]][nextColumn];
//         int total_cost = grid[i][j] + move_cost + func(i+1, nextColumn, grid, moveCost, dp);

//         minCost = min(minCost, total_cost);
//     }
//     return dp[i][j] = minCost;
// }

// int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//     int n = grid.size();
//     int m = grid[0].size();
//     int ans = 1e8;

//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     for(int j = 0 ; j < m ; j++){        // here we first try all smallest number in first row and keep updating the min.
//         ans = min(ans, func(0, j, grid, moveCost, dp));
//     }
//     return ans;
// }





                // TABULATION APPROACH


int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 1e8;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j = 0 ; j < m ; j++){
        dp[n-1][j] = grid[n-1][j];
    }

    for(int i = n-2 ; i >= 0 ; i--){        // the loop runs till 0 and it just simply calc and fill the sum into the dp[0][0], dp[0][1] etc....but we have to take the mini out of those....so at last...
        for(int j = 0 ; j < m ; j++){
            int minCost = 1e8;

            for(int nextColumn = 0 ; nextColumn < m ; nextColumn++){
                int move_cost = moveCost[grid[i][j]][nextColumn];
                int total_cost = grid[i][j] + move_cost + dp[i+1][nextColumn];

                minCost = min(minCost, total_cost);
            }
            dp[i][j] = minCost;
        }
    }

    for(int j = 0 ; j < m ; j++){       // this is for the ....taking the min ans.
        ans = min(ans, dp[0][j]);
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{5,3},{4,0},{2,1}}, moveCost = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};
    int ans = minPathCost(grid, moveCost);

    cout << "The minimum path sum : " << ans;
    return 0;
}