#include<bits/stdc++.h>
using namespace std;

/*      LC = 3665
    Given an m x n binary grid grid where:

    grid[i][j] == 0 represents an empty cell, and
    grid[i][j] == 1 represents a mirror.
    A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). It can move only right or down. If the robot attempts to move into a mirror cell, it is reflected before entering that cell:

    If it tries to move right into a mirror, it is turned down and moved into the cell directly below the mirror.
    If it tries to move down into a mirror, it is turned right and moved into the cell directly to the right of the mirror.
    If this reflection would cause the robot to move outside the grid boundaries, the path is considered invalid and should not be counted.

    Return the number of unique valid paths from (0, 0) to (m - 1, n - 1).

    Since the answer may be very large, return it modulo 109 + 7.

    Note: If a reflection moves the robot into a mirror cell, the robot is immediately reflected again based on the direction it used to enter that mirror: if it entered while moving right, it will be turned down; if it entered while moving down, it will be turned right. This process will continue until either the last cell is reached, the robot moves out of bounds or the robot moves to a non-mirror cell.
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    // int func(int i, int j, int dir, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp){
    //     if(i >= n || j >= m) return 0;
    //     if(i == n-1 && j == m-1) return 1;

    //     if(dp[i][j][dir] != -1) return dp[i][j][dir];
        
    //     int right = 0, down = 0;
    //     if(grid[i][j] == 0){
    //         right = func(i, j+1, 1, grid, n, m, dp);
    //         down = func(i+1, j, 0, grid, n, m, dp);
    //     }
    //     else{
    //         if(dir == 1){
    //             down = func(i+1, j, 0, grid, n, m, dp);
    //         }
    //         else{
    //             right = func(i, j+1, 1, grid, n, m, dp);
    //         }
    //     }

    //     return dp[i][j][dir] = (right + down) % mod;
    // }
    // int uniquePaths(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));

    //     return func(0, 0, 0, grid, n, m, dp);
    // }






    int func(int i, int j, int dir, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp){
        if(i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1) return 1;

        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        
        int right = 0, down = 0;
        if(grid[i][j] == 0){
            right = func(i, j+1, 1, grid, n, m, dp);
            down = func(i+1, j, 0, grid, n, m, dp);
        }
        else{
            if(dir == 1){
                down = func(i+1, j, 0, grid, n, m, dp);
            }
            else{
                right = func(i, j+1, 1, grid, n, m, dp);
            }
        }

        return dp[i][j][dir] = (right + down) % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        /* 
            here coming from right = 1.
            here coming from donw = 0.
        */

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(2, 0)));

        dp[n-1][m-1][0] = 1;
        dp[n-1][m-1][1] = 1;

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >=0 ; j--){

                if(i == n-1 && j == m-1) continue;

                if(grid[i][j] == 0){
                    dp[i][j][1] = (dp[i][j+1][1] + dp[i+1][j][0]) % mod;        // im coming from a cell having 0 and currently on a cell 0 that means i can go both sides now so we add both right and down.
                    dp[i][j][0] = (dp[i][j+1][1] + dp[i+1][j][0]) % mod;
                }
                else{
                    dp[i][j][0] = dp[i][j+1][1];        // this means that if im coming from down ( = 0) i have to go right now.
                    dp[i][j][1] = dp[i+1][j][0];        // this means that if im coming from right ( = 1) i have to go down now.
                }
            }
        }

        return dp[0][0][0];
    }
};

int main(){
    /*
        Example 1:

        Input: grid = [[0,1,0],[0,0,1],[1,0,0]]
        Output: 5
        Explanation:

        Number	Full Path
        1	(0, 0) → (0, 1) [M] → (1, 1) → (1, 2) [M] → (2, 2)
        2	(0, 0) → (0, 1) [M] → (1, 1) → (2, 1) → (2, 2)
        3	(0, 0) → (1, 0) → (1, 1) → (1, 2) [M] → (2, 2)
        4	(0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2)
        5	(0, 0) → (1, 0) → (2, 0) [M] → (2, 1) → (2, 2)
        [M] indicates the robot attempted to enter a mirror cell and instead reflected.


        Example 2:

        Input: grid = [[0,0],[0,0]]
        Output: 2
        Explanation:

        Number	Full Path
        1	(0, 0) → (0, 1) → (1, 1)
        2	(0, 0) → (1, 0) → (1, 1)


        Example 3:

        Input: grid = [[0,1,1],[1,1,0]]
        Output: 1
        Explanation:

        Number	Full Path
        1	(0, 0) → (0, 1) [M] → (1, 1) [M] → (1, 2)
        (0, 0) → (1, 0) [M] → (1, 1) [M] → (2, 1) goes out of bounds, so it is invalid.
        

        Constraints:

        m == grid.length
        n == grid[i].length
        2 <= m, n <= 500
        grid[i][j] is either 0 or 1.
        grid[0][0] == grid[m - 1][n - 1] == 0
    */

    return 0;
}