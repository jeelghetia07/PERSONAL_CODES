#include<bits/stdc++.h>
using namespace std;

// Problem Statement : Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K.

// constriants....  1 <= nums[i] <= 1000....here 0 is not there....if 0 comes...then there will be increase in subsets.

                    // MEMOIZATION USING RECURSION.

// int f(int ind, int tar, vector<int>& arr, vector<vector<int>>& dp){
//     if(tar == 0) return 1;
//     if(ind == 0) return (arr[0] == tar);
//     if(dp[ind][tar] != -1) return dp[ind][tar];

//     int nonpick = f(ind-1, tar, arr, dp);
//     int pick = 0;
//     if(tar >= arr[ind]) pick = f(ind-1, tar-arr[ind], arr, dp);

//     return dp[ind][tar] = pick + nonpick;
// }

// int CountSubsets(vector<int>& arr, int n, int tar){
//     vector<vector<int>> dp(n, vector<int>(tar+1, -1));   // dp of the same size.
//     return f(n-1, tar, arr, dp);
// }



                    // TABULATION METHOD.

int CountSubsets(vector<int>& arr, int n, int k){
    vector<vector<int>> dp(n, vector<int>(k+1, 0));   // dp of the same size.
    
    for(int ind = 0 ; ind < n ; ind++){
        dp[ind][0] = 1;
    }
    if(k >= arr[0]) dp[0][arr[0]] = 1;

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

int main(){
    vector<int> arr = {1,2,2,3};
    int n = arr.size();
    int tar = 3;

    cout << "The count is : " << CountSubsets(arr,n,tar);
    return 0;
}