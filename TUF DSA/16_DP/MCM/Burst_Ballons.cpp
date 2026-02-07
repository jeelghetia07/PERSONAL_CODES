// Burst_Ballons.cpp
#include<bits/stdc++.h>
using namespace std;

                // RECURSIVE

// int f(int i, int j, vector<int>& arr){
//     if(i > j) return 0;
//     int maxi = INT_MIN;

//     for(int ind = i ; ind <= j ; ind++){
//         int cost = arr[i-1]*arr[ind]*arr[j+1] + f(i,ind-1, arr) + f(ind+1, j, arr);
//         maxi = max(maxi, cost);
//     }
//     return maxi;
// }

// int maxCoins(vector<int>& arr){
//     int n = arr.size();
//     arr.push_back(1);
//     arr.insert(arr.begin(), 1);
//     return f(1, n, arr);
// }



                // MEMOIZATION

// int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
//     if(i > j) return 0;
//     int maxi = INT_MIN;
//     if(dp[i][j] != -1) return dp[i][j];
//     for(int ind = i ; ind <= j ; ind++){
//         int cost = arr[i-1]*arr[ind]*arr[j+1] + f(i,ind-1, arr, dp) + f(ind+1, j, arr, dp);
//         maxi = max(maxi, cost);
//     }
//     return dp[i][j] = maxi;
// }

// int maxCoins(vector<int>& arr){
//     int n = arr.size();
//     arr.push_back(1);
//     arr.insert(arr.begin(), 1);
//     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

//     return f(1, n, arr, dp);
// }



                // TABULATION

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
    if(i > j) return 0;
    int maxi = INT_MIN;
    if(dp[i][j] != -1) return dp[i][j];
    for(int ind = i ; ind <= j ; ind++){
        int cost = arr[i-1]*arr[ind]*arr[j+1] + f(i,ind-1, arr, dp) + f(ind+1, j, arr, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int>& arr){
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int i = n ; i >= 1 ; i--){
        for(int j = 1 ; j <= n ; j++){
            // we increase the size to n+2....becoz we need the space of n+1..for ind+1....becoz dp[n+1] will have the space till n...we have to access n+1...so declare n+2.
            if(i > j) continue;
            int maxi = INT_MIN;
            for(int ind = i ; ind <= j ; ind++){
                int cost = arr[i-1]*arr[ind]*arr[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int main(){
    vector<int> ballons = {3, 1, 5, 8};
    cout << "The max amount of coins : " << maxCoins(ballons);
    return 0;
}