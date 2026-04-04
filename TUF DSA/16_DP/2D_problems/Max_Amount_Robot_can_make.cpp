#include<bits/stdc++.h>
using namespace std;

/*      LC = 3418
    You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

    The grid contains a value coins[i][j] in each cell:

    If coins[i][j] >= 0, the robot gains that many coins.
    If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
    The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

    Note: The robot's total coins can be negative.

    Return the maximum profit the robot can gain on the route.
*/

class Solution {
public:
    // int func(int i, int j, int chances, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp){
    //     if(i == n-1 && j == m-1){
    //         if(grid[i][j] < 0){
    //             int rob = grid[i][j];
    //             int notrob = INT_MIN;
    //             if(chances > 0)
    //                 notrob = 0;

    //             return max(rob, notrob);
    //         }
    //         else{
    //             return grid[i][j];
    //         }
    //     } 

    //     if(dp[i][j][chances] != -1) return dp[i][j][chances];

    //     int right = INT_MIN, down = INT_MIN;
    //     if(j+1 < m){
    //         int next = func(i, j+1, chances, grid, n, m, dp);
    //         if(grid[i][j] < 0){
    //             int rob = grid[i][j] + func(i, j+1, chances, grid, n, m, dp);
    //             int notrob = INT_MIN;

    //             if(chances > 0)
    //                 notrob = 0 + func(i, j+1, chances-1, grid, n, m, dp);

    //             right = max(rob, notrob);
    //         }
    //         else{
    //             if(next != INT_MIN)
    //                 right = grid[i][j] + next;
    //         }
    //     }
    //     if(i+1 < n){
    //         int next = func(i+1, j, chances, grid, n, m, dp);
    //         if(grid[i][j] < 0){
    //             int rob = grid[i][j] + func(i+1, j, chances, grid, n, m, dp);
    //             int notrob = INT_MIN;
    //             if(chances > 0)
    //                 notrob = func(i+1, j, chances-1, grid, n, m, dp);

    //             down = max(rob, notrob);
    //         }
    //         else{
    //             if(next != INT_MIN)
    //                 down = grid[i][j] + next;
    //         }
    //     }

    //     return dp[i][j][chances] = max(right, down);
    // }
    // int maximumAmount(vector<vector<int>>& coins) {
    //     int n = coins.size();
    //     int m = coins[0].size();

    //     int chances = 2;

    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));

    //     return func(0, 0, chances, coins, n, m, dp);
    // }






    int maximumAmount(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int chances = 2;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));

        // Base Case.
        for(int chances = 0 ; chances <= 2 ; chances++){        
            if(grid[n-1][m-1] < 0){
                int rob = grid[n-1][m-1];
                int notrob = INT_MIN;
                if(chances > 0)
                    notrob = 0;

                dp[n-1][m-1][chances] = max(rob, notrob);
            }
            else{
                dp[n-1][m-1][chances] = grid[n-1][m-1];
            }
        }

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                for(int chances = 0 ; chances <= 2 ; chances++){

                    if(i == n-1 && j == m-1) continue;

                    int right = INT_MIN, down = INT_MIN;

                    if(j+1 < m){
                        int next = dp[i][j+1][chances];
                        if(grid[i][j] < 0){
                            int rob = INT_MIN;
                            if(next != INT_MIN)
                                rob = grid[i][j] + next;

                            int notrob = INT_MIN;
                            if(chances > 0){
                                int nextNotRob = dp[i][j+1][chances-1];
                                if(nextNotRob != INT_MIN)
                                    notrob = nextNotRob;
                            }
                            right = max(rob, notrob);
                        }
                        else{
                            if(next != INT_MIN)
                                right = grid[i][j] + next;
                        }
                    }
                    if(i+1 < n){
                        int next =  dp[i+1][j][chances];
                        if(grid[i][j] < 0){
                            int rob = INT_MIN;
                            if(next != INT_MIN)
                                rob = grid[i][j] + next;

                            int notrob = INT_MIN;
                            if(chances > 0){
                                int nextNotRob = dp[i+1][j][chances-1];
                                if(nextNotRob != INT_MIN)
                                    notrob = 0 +  nextNotRob;
                            }
                            down = max(rob, notrob);
                        }
                        else{
                            if(next != INT_MIN)
                                down = grid[i][j] + next;
                        }
                    }
                    dp[i][j][chances] = max(right, down);
                }
            }
        }

        return dp[0][0][2];
    }
};

int main(){
    /*
        Example 1:

        Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
        Output: 8
        Explanation:
            An optimal path for maximum coins is:

            Start at (0, 0) with 0 coins (total coins = 0).
            Move to (0, 1), gaining 1 coin (total coins = 0 + 1 = 1).
            Move to (1, 1), where there's a robber stealing 2 coins. The robot uses one neutralization here, avoiding the robbery (total coins = 1).
            Move to (1, 2), gaining 3 coins (total coins = 1 + 3 = 4).
            Move to (2, 2), gaining 4 coins (total coins = 4 + 4 = 8).


        Example 2:

        Input: coins = [[10,10,10],[10,10,10]]
        Output: 40
        Explanation:
            An optimal path for maximum coins is:
            
            Start at (0, 0) with 10 coins (total coins = 10).
            Move to (0, 1), gaining 10 coins (total coins = 10 + 10 = 20).
            Move to (0, 2), gaining another 10 coins (total coins = 20 + 10 = 30).
            Move to (1, 2), gaining the final 10 coins (total coins = 30 + 10 = 40).
    */

    return 0;
}