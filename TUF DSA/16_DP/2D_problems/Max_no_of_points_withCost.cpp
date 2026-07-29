#include<bits/stdc++.h>
using namespace std;

/*      LC = 1937
    You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

    To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

    However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

    Return the maximum number of points you can achieve.

    abs(x) is defined as:

    x for x >= 0.
    -x for x < 0.

    Extremely hard to think the optimal solution.
*/

using ll = long long;
class Solution {
public:

                    // TC = O(n*m*m)



    // int func(int row, int PrevCol, vector<vector<int>>& mat, int n, int m, vector<vector<int>>& dp){
    //     if(row == n) return 0;

    //     if(dp[row][PrevCol] != -1) return dp[row][PrevCol];

    //     int maxi = INT_MIN;

    //     if(row + 1 <= n){
    //         for(int nc = 0 ; nc < m ; nc++){
    //             maxi = max(maxi, mat[row][nc] - abs(nc - PrevCol) + func(row+1, nc, mat, n, m, dp));
    //         }
    //     }

    //     return dp[row][PrevCol] = maxi;
    // }
    // long long maxPoints(vector<vector<int>>& mat) {
    //     int n = mat.size();
    //     int m = mat[0].size();

    //     int maxi = INT_MIN;
    //     vector<vector<int>> dp(n, vector<int>(m, -1));

    //     for(int j = 0 ; j < m ; j++){
    //         maxi = max(maxi, mat[0][j] + func(1, j, mat, n, m, dp));
    //     }

    //     return maxi;
    // }



                    // TC = O(n*m).



    long long maxPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        ll maxi = LLONG_MIN;
        vector<vector<ll>> dp(n, vector<ll>(m, 0));

        for(int j = 0 ; j < m ; j++){
            dp[n-1][j] = mat[n-1][j];
        }

        for(int row = n-2 ; row >= 0 ; row--){

            vector<ll> leftBest(m), rightBest(m);

            // leftBest[currentCOl] = max(dp[currRow+1][nextCol] + nextCol).... this is for all nextCol <= currCol
            leftBest[0] = dp[row+1][0] + 0;
            for(int col = 1 ; col < m ; col++){
                leftBest[col] = max(leftBest[col-1], dp[row+1][col] + col);
            }

            // rightBest[currentCOl] = max(dp[currRow+1][nextCol] - nextCol).... this is for all nextCol <= currCol
            rightBest[m-1] = dp[row+1][m-1] - (m-1);
            for(int col = m-2 ; col >= 0 ; col--){
                rightBest[col] = max(rightBest[col+1], dp[row+1][col] - col);
            }

            for(int col = 0 ; col < m ; col++){
                ll best = max(leftBest[col] - col, rightBest[col] + col);
                dp[row][col] = mat[row][col] + best;
            }
        }

        for(int j = 0 ; j < m ; j++){
            if(maxi < dp[0][j])
            maxi = dp[0][j];
        }

        return maxi;
    }

};

int main(){


    return 0;
}