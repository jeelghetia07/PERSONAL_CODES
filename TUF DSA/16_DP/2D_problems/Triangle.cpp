#include<bits/stdc++.h>
using namespace std;


                // MEMOIZATION + RECURRUSION

// int solve(int i, int j, vector<vector<int>> &arr, int n, vector<vector<int>> &dp){
//     if(i == n-1) return arr[i][j];
//     if(dp[i][j] != -1) return dp[i][j];
//     int down = arr[i][j] + solve(i+1, j, arr, n, dp);
//     int dgnl = arr[i][j] + solve(i+1, j+1, arr, n, dp);

//     return dp[i][j] = min(down, dgnl);
// }


                // TABULATION METHOD.

// int solve(vector<vector<int>> &arr, int n){
//     vector<vector<int>> dp(n, vector<int>(n,0)); 
//     for(int i = 0 ; i < n ; i++){
//         dp[n-1][i] = arr[n-1][i];
//     } 

//     for(int i = n-2 ; i >= 0 ; i--){
//         for(int j = i ; j >= 0 ; j--){
//             int down = arr[i][j] + dp[i+1][j];
//             int dgnl = arr[i][j] + dp[i+1][j+1];
//             dp[i][j] = min(down, dgnl);
//         }
//     }
//     return dp[0][0];
// }

                // SPACE OPTIMIZED APPROACH

int solve(vector<vector<int>> &arr, int n){
    vector<int> front(n, 0), curr(n, 0);
    for(int i = 0 ; i < n ; i++){
       front[i] = arr[n-1][i];
    } 
    
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = i ; j >= 0 ; j--){
            int down = arr[i][j] + front[j];
            int dgnl = arr[i][j] + front[j+1];
            curr[j] = min(down, dgnl);
        }
        front = curr;
    }
    return front[0];
}


int minimumPathSum(vector<vector<int>> &triangle){
    int n = triangle.size();

    return solve(triangle, n);
}

int main(){
    vector<vector<int>> triangle{
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    cout << minimumPathSum(triangle);
    return 0;
}