#include<bits/stdc++.h>
using namespace std;
int mod = (int)(1e9 + 7);

class UNIQUE{
public:
    int f(int i, int j, vector<vector<int>> &arr, vector<vector<int>>& dp){
        if(i >= 0 && j >= 0 && arr[i][j] == 1) return 0;
        if(i == 0 && j == 0 && arr[i][j] == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = 0, left = 0;
        if(i > 0) int up = f(i-1, j, arr, dp);
        if(j > 0) int left = f(i, j-1, arr, dp);

        return dp[i][j] = (up + left) % mod;
    }   
    // int uniquePaths(vector<vector<int>> &mat){
    //     int m = mat.size();
    //     int n = mat[0].size();

    //     int dp[m][n];
    //     for(int i = 0 ; i < m ; i++){
    //         for(int j = 0 ; j < n ; j++){
    //             // Base conditions.
    //             if(mat[i][j] == 1){      // if there is an obstacle..no paths can pass through it.
    //                 dp[i][j] = 0;   
    //                 continue; 
    //             }
    //             if(i == 0 && j == 0){       // if we are at starting point...there one path to it.
    //                 dp[i][j] = 1;    
    //             } 
    //             else{
    //                 int up = 0, left = 0;
    //                 if(i > 0) up = dp[i-1][j];
    //                 if(j > 0) left = dp[i][j-1];
    //                 dp[i][j] = up + left;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    //     // return f(m-1, n-1, obstacleGrid, dp);
    // }

    int uniquePaths(vector<vector<int>> &mat){
        int m = mat.size();
        int n = mat[0].size();

        vector<int> prev(n, -1);
        vector<int> curr(n, -1);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }
                int up = 0 , left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j-1];

                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

int main(){
    vector<vector<int>> maze{
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}
    };
    
    //Create an instance of Solution class
    UNIQUE sol;

    cout << "Number of paths with obstacles: " << sol.uniquePaths(maze) << endl;
    return 0;
}