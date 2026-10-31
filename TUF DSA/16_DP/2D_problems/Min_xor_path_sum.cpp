#include<bits/stdc++.h>
using namespace std;

/*      LC = 3882
    You are given a 2D integer array grid of size m * n.

    You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).

    At each step, you may move either right or down.

    The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.

    Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).
*/

class Solution {
public:
    int func(int row, int col, int n, int m, vector<vector<int>>& grid, int xr, vector<vector<vector<int>>>& dp){
        if(row >= n || col >= m) return 1e9;

        int currXor = xr ^ grid[row][col];
        
        if(row == n-1 && col == m-1){
            return currXor;
        }

        if(dp[row][col][currXor] != -1) return dp[row][col][currXor];

        int right = func(row+1, col, n, m, grid, currXor, dp);
        int down = func(row, col+1, n, m, grid, currXor, dp);
        
        return dp[row][col][currXor] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1024, -1)));

        return func(0, 0, n, m, grid,0, dp);
    }
};

int main(){
    /*
        Example 1:

        Input: grid = [[1,2],[3,4]]
        Output: 6
        Explanation:

        There are two valid paths:

        (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
        (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6
        The minimum XOR value among all valid paths is 6.


        Example 2:

        Input: grid = [[6,7],[5,8]]
        Output: 9
        Explanation:

        There are two valid paths:

        (0, 0) → (0, 1) → (1, 1) with XOR: 6 XOR 7 XOR 8 = 9
        (0, 0) → (1, 0) → (1, 1) with XOR: 6 XOR 5 XOR 8 = 11
        The minimum XOR value among all valid paths is 9.


        Example 3:

        Input: grid = [[2,7,5]]
        Output: 0
        Explanation:

        There is only one valid path:

        (0, 0) → (0, 1) → (0, 2) with XOR: 2 XOR 7 XOR 5 = 0
        The XOR value of this path is 0, which is the minimum possible.


        Constraints:

        1 <= m == grid.length <= 1000
        1 <= n == grid[i].length <= 1000
        m * n <= 1000
        0 <= grid[i][j] <= 1023​
    */

    return 0;
}