#include<bits/stdc++.h>
using namespace std;

                // MEMOIZATION USING RECURRSION.

// int dfs(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& dp){
//     if(col < 0 || col >= mat[0].size()){  // if column gets out of bound then return a large number to ignore this path.
//         return 1e9;
//     }
//     if(row == mat.size()-1) return mat[row][col];
//     if(dp[row][col] != -1) return dp[row][col];

//     int down = mat[row][col] + dfs(row+1, col, mat, dp);
//     int Rdgnl = mat[row][col] + dfs(row+1, col+1, mat, dp);
//     int Ldgnl = mat[row][col] + dfs(row+1, col-1, mat, dp);

//     int ans = min({down, Rdgnl, Ldgnl});
//     return dp[row][col] = ans;
// }


// // Main function to find minimum falling path sum.
// int minFallingPathSum(vector<vector<int>>& mat){
//     int n = mat.size();
//     int m = mat[0].size();

//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     int minSum = 1e9;

//     for(int col = 0 ; col < m ; col++){
//         minSum = min(minSum, dfs(0, col, mat, dp));
//     }
//     return minSum;
// }


                // TABULATION METHOD.

// int minFallingPathSum(vector<vector<int>>& mat){
//     int n = mat.size();
//     int m = mat[0].size();

//     vector<vector<int>> dp(n, vector<int>(m, 0));

//     for(int col = 0 ; col < m ; col++){
//         dp[n-1][col] = mat[n-1][col];
//     }

//     for(int row = n-2 ; row >= 0 ; row--){
//         for(int col = 0 ; col < m ; col++){
//             int down = dp[row+1][col];
//             int downLeft = (col > 0) ? dp[row+1][col-1] : 1e9;
//             int downRight = (col < m-1) ? dp[row+1][col+1] : 1e9;

//             dp[row][col] = mat[row][col] + min({down, downLeft, downRight});
//         }
//     }
//     int mini = INT_MAX;
//     for(int col = 0 ; col < m ; col++){
//         mini = min(mini, dp[0][col]);
//     }
//     return mini;
// }


                // SPACE OPTIMIZED.

int minFallingPathSum(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int> dp(mat[n-1]), curr(m, 0);    // initialized last row.

    for(int row = n-2 ; row >= 0 ; row--){
        for(int col = 0 ; col < m ; col++){
            int down = dp[col];
            int downLeft = (col > 0) ? dp[col-1] : 1e9;
            int downRight = (col < m-1) ? dp[col+1] : 1e9;

            curr[col] = mat[row][col] + min({down, downLeft, downRight});
        }
        dp = curr;
    }
    int mini = INT_MAX;
    for(int col = 0 ; col < m ; col++){
        mini = min(mini, dp[col]);
    }
    return mini;
}



int main(){
    vector<vector<int>> matrix = {
        {1, 4, 3, 1},
        {2, 3, -1, -1},
        {1, 1, -1, 8}
    };

    cout << "Minimum Falling Path Sum: " << minFallingPathSum(matrix) << endl;

    return 0;
}