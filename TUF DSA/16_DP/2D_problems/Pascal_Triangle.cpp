#include<bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<vector<int>>& dp){
    if(j == 0 || j == i) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = func(i-1, j-1, dp) + func(i-1, j, dp);
}

vector<vector<int>> generate(int n) {
    vector<vector<int>> ans;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int i = 0 ; i < n ; i++){
        vector<int> row;
        for(int j = 0 ; j <= i ; j++){
            row.push_back(func(i, j, dp));
        }
        ans.push_back(row);
    }
    return ans;



    // vector<vector<int>> dp(n, vector<int>(n, 0));

    // for(int i = 0 ; i < n ; i++){
    //     dp[i][0] = 1;
    // }

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         if(i == j) dp[i][j] = 1;
    //     }
    // }

    // for(int i = 2 ; i < n ; i++){
    //     for(int j = 1 ; j < i ; j++){
    //         dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    //     }
    // }

    // vector<vector<int>> ans;
    
    // for(int i = 0 ; i < n ; i++){
    //     vector<int> level;
    //     for(int j = 0 ; j < n ; j++){
    //         if(dp[i][j] == 0) continue;
    //         level.push_back(dp[i][j]);
    //     }
    //     ans.push_back(level);
    // }
    // return ans;
}

int main(){
    int n = 5;
    vector<vector<int>> ans = generate(n);
    return 0;
}