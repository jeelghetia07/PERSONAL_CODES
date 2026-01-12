#include<bits/stdc++.h>
using namespace std;

                        // RECCURSION....TC = O(2^mxn)....SC = O((m-1)+(n-1))...this is the max path length.

// int f(int i, int j){             
//     if(i == 0 && j == 0) return 1;
//     if(i < 0 || j < 0) return 0;

//     int up = f(i-1, j);
//     int left = f(i, j-1);

//     return up + left;
// }

// int uniquePaths(int m, int n){
//     return f(m-1, n-1);
// }


                         // MEMOIZATION....TC = O(mxn)....SC = O((m-1)+(n-1)) + O(mxn)...this is the max path length.


// int f(int i, int j, vector<vector<int>> &dp){            
//     if(i == 0 && j == 0) return 1;
//     if(i < 0 || j < 0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
    
//     int up = f(i-1, j, dp);
//     int left = f(i, j-1, dp);

//     return dp[i][j] = up + left;
// }

// int uniquePaths(int m, int n){
//     vector<vector<int>> dp(m, vector<int> (n ,-1));
//     return f(m-1, n-1, dp);
// }


                                // TABULATION....TC = O(mxn)....SC = O((m-1)+(n-1)) + O(mxn)...this is the max path length.

// int uniquePaths(int m, int n){
//     int dp[m][n];
//     for(int i = 0 ; i < m ; i++){
//         for(int j = 0 ; j < n ; j++){
//             if(i == 0 && j == 0) dp[i][j] = 1;
//             else{
//                 int up = 0;
//                 int left = 0;
//                 if(i > 0) up = dp[i-1][j];
//                 if(j > 0) left = dp[i][j-1];
//                 dp[i][j] = up + left;
//             }
//         }
//     }
//     return dp[m-1][n-1]; 
// }


                                // SPACE OPTIMIZED TC = O(mxn)...SC = O(n).


int uniquePaths(int m, int n){
    vector<int> prev(n,0);
    for(int i = 0 ; i < m ; i++){
        vector<int> curr(n,0);
        for(int j = 0 ; j < n ; j++){
            if(i == 0 && j == 0) curr[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];       // dp[i-1][j] .. here the dp[i-1]..represents the upper row..so its prev.
                if(j > 0) left = curr[j-1];      // dp[i][j-1] ..here the dp[i] represents the same row...so its curr.
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1]; 
}


int main(){       // we just have to tell the size of the matrix....no need of the matrix itself.
    int m,n;
    cin >> m >> n;

    int ans = uniquePaths(m,n);
    cout << "The uniques ways are : " << ans;
}