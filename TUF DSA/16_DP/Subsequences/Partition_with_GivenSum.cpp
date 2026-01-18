#include<bits/stdc++.h>
using namespace std;

// Problem Statement : Given an array with N positive integers and an integer D, count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.

int f(int ind, int tar, vector<int>& arr, vector<vector<int>>& dp){
    if(ind == 0){
        if(tar == 0 && arr[ind] == 0)  return 2;   // this is becoz....if the ele is 0 and sum to be achieved is also 0...then we have 2 options...pick and non pick...so return 2;
        else if(tar == 0 || arr[ind] == tar) return 1;     // if arr[ind] = 5..and sum = 5...then only 1 choice..take...
        return 0;
    }

    if(dp[ind][tar] != -1) return dp[ind][tar];

    int nonpick = f(ind-1, tar, arr, dp);
    int pick = 0;
    if(tar >= arr[ind]) pick = f(ind-1, tar-arr[ind], arr, dp);

    return dp[ind][tar] = pick + nonpick;
}

// int FindWays(vector<int>& arr, int n, int tar){
//     vector<vector<int>> dp(n, vector<int>(tar+1, -1));   // dp of the same size.
//     return f(n-1, tar, arr, dp);
// }

int FindWays(vector<int>& arr, int n, int k){
    vector<vector<int>> dp(n, vector<int>(k+1, 0));   // dp of the same size.
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;         // the case where tar is 0...but at index there is any value...therefore notpick...and hence return 1;
    if(arr[0] != 0 && k >= arr[0]) dp[0][arr[0]] = 1;

    for(int ind = 1 ; ind < n ; ind++){
        for(int tar = 0 ; tar <= k ; tar++){
            int nonpick = dp[ind-1][tar];
            int pick = 0;
            if(tar >= arr[ind]) pick = dp[ind-1][tar-arr[ind]];
            dp[ind][tar] = pick + nonpick;
        }
    }
    return dp[n-1][k];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(auto &it : arr) totSum += it;

    if((totSum-d) < 0 || (totSum-d) % 2 != 0) return false;
    return FindWays(arr, n, (totSum-d)/2);
}

int main(){
    vector<int> arr = {5,2,6,4};
    int n = arr.size();
    int d = 3;

    cout << "The no is : " << countPartitions(n,d, arr);
    return 0;
}