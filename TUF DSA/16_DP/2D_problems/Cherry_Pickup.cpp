#include<bits/stdc++.h>
using namespace std;

                // MEMOIZATION USING RECURRSION

// int f(int i, int j1, int j2, vector<vector<int>> &grid, int r, int c, vector<vector<vector<int>>> &dp){
//     if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
//         return -1e8;     // not returning INT_MIN becoz it will add and overflow the program.
//     }
//     if(i == r-1){
//         return (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
//     }
//     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

//     int maxi = -1e8;
//     int value = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);

//     // tyring all 9 moves.
//     for(int dj1 = -1 ; dj1 <= +1 ; dj1++){
//         for(int dj2 = -1 ; dj2 <= +1 ; dj2++){
//             int ans = value + f(i+1, j1+dj1, j2+dj2, grid, r, c, dp);
//             maxi = max(maxi, ans);
//         }
//     }
//     return dp[i][j1][j2] = maxi;
// }

// int maximumCherry(int r, int c, vector<vector<int>> &grid){
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<vector<int>>> dp(n , vector<vector<int>>(m, vector<int>(m, -1)));
//     return f(0, 0, m-1, grid, r, c, dp);
// }

int maximumCherry(int n, int m, vector<vector<int>> &grid){
    // vector<vector<vector<int>>> dp(n , vector<vector<int>>(m, vector<int>(m, -1)));
    int dp[n][m][m];

    // BASE CASES.
    for(int j1 = 0 ; j1 < m ; j1++){
        for(int j2 = 0 ; j2 < m ; j2++){
            dp[n-1][j1][j2] = (j1 == j2) ? grid[n-1][j1] : (grid[n-1][j1] + grid[n-1][j2]);
        }
    }

    for(int i = n-2 ; i >= 0 ; i--){
        for(int j1 = 0 ; j1 < m ; j1++){
            for(int j2 = 0 ; j2 < m ; j2++){
                int maxi = -1e8;
                for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
                    for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                        int value = 0;
                        value = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                        if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m)
                            value += dp[i+1][j1+dj1][j2+dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}


int main(){
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = grid.size(), m = grid[0].size();
    cout << maximumCherry(n, m, grid) << endl;
    return 0;
}