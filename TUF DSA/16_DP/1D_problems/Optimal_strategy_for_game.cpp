#include<bits/stdc++.h>
using namespace std;

/*      GFG
    You are given an integer array arr[] of size n. The array elements represent n coins of values v1, v2, ....vn.
    You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the coin's value.
    You need to determine the maximum possible amount of money you can win if you go first.
    Note: Both the players are playing optimally.
*/

class Solution {
  public:
    int func(int i, int j, vector<int>& arr, int n, vector<vector<int>>& dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int take_left = arr[i] + min(func(i+2, j, arr, n, dp), func(i+1, j-1, arr, n, dp));
        int take_right = arr[j] + min(func(i+1, j-1, arr, n, dp), func(i, j-2, arr, n, dp));
        
        return dp[i][j] = max(take_left, take_right);
    }
    int maximumAmount(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return func(0, n-1, arr, n, dp);
    }
};

int main(){
    /*
        Examples:

        Input: arr[] = [5, 3, 7, 10]
        Output: 15
        Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.
        Input: arr[] = [8, 15, 3, 7]
        Output: 22
        Explanation: The user collects the maximum value as 22(7 + 15). It is guaranteed that we cannot get more than 22 by any possible moves.
    */

    return 0;
}