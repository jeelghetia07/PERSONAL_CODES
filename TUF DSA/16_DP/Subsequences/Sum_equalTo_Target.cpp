#include<bits/stdc++.h>
using namespace std;


                // MEMOIZATION USING RECURRSION .

// bool f(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp){
//     if(tar == 0) return true;
//     if(ind == 0) return (arr[0] == tar);
//     if(dp[ind][tar] != -1) return dp[ind][tar];

    // bool nontake = f(ind-1, tar, arr, dp);
    // bool take = false;
    // if(tar >= arr[ind]){
    //     take = f(ind-1, tar-arr[ind], arr, dp);
    // }
//     return dp[ind][tar] = take | nontake;
// }

// bool subsetSumk(int n, int k, vector<int> &arr){
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));
//     return f(n-1, k, arr, dp);
// }



                // TABULATION METHOD....BOTTOM UP APPROACH.

// bool subsetSumk(int n, int k, vector<int> &arr){
//     vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
//     for(int i = 0 ; i < n ; i++) dp[i][0] = true;
//     dp[0][arr[0]] = true;

//     for(int ind = 0 ; ind < n ; ind++){
//         for(int tar = 1 ; tar <= k ; tar++){
//             bool nontake = dp[ind-1][tar];
//             bool take = false;
//             if(tar >= arr[ind]){
//                 take = dp[ind-1][tar-arr[ind]];
//             }
//             dp[ind][tar] = take | nontake;
//         }
//     }
//     return dp[n-1][k];
// }



                // SPACE OPTIMIZED.


bool subsetSumk(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    prev[0] = true;
    curr[0] = true;
    prev[arr[0]] = true;

    for(int ind = 0 ; ind < n ; ind++){
        for(int tar = 1 ; tar <= k ; tar++){
            bool nontake = prev[tar];
            bool take = false;
            if(tar >= arr[ind]){
                take = prev[tar-arr[ind]];
            }
            curr[tar] = take | nontake;
        } 
        prev = curr;
    }
    return prev[k];
}

int main(){
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    int tar = 4;
    bool ans = subsetSumk(n,tar,arr);

    cout << "The ans is : " << ans;
    return 0;
}