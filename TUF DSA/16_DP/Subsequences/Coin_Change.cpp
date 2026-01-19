#include<bits/stdc++.h>
using namespace std;

// Porblem : You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.You may assume that you have an infinite number of each kind of coin.

/* 1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104 */


                // MEMOIZATION APPROACH....

// int f(int ind, int T, vector<int> & arr, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(T % arr[0] == 0) return T/arr[0];    // to see how many coins of the same value do we need for the target.
//         return 1e9;
//     }
//     if(dp[ind][T] != -1) return dp[ind][T];

//     int nottake = 0 + f(ind-1, T, arr, dp);     // this says...) coins + f(next ele, T);
//     int take = 1e9;
//     if(arr[ind] <= T) take = 1 + f(ind, T-arr[ind], arr, dp);     // this shows we add 1 (quantity of coin we take rn)....and we remain at the same index to check the same value again.

//     return dp[ind][T] = min(take, nottake);
// }

// int minimumEle(vector<int>& arr, int tar){
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(tar+1, -1));
//     int ans = f(n-1, tar, arr, dp);
//     if(ans >= 1e9) return -1;
//     return ans;
// }



                // TABULATION APPROACH.


int minimumEle(vector<int>& arr, int tar){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));

    for(int T = 0 ; T <= tar ; T++){
        if(T % arr[0] == 0) dp[0][T] = T/arr[0];
        else{
            dp[0][T] = 1e9;
        }
    }

    for(int ind = 1 ; ind < n ; ind++){
        for(int T = 0 ; T <= tar ; T++){
            int nottake = 0 + dp[ind-1][T];     // this says...) coins + f(next ele, T);
            int take = 1e9;
            if(arr[ind] <= T) take = 1 + dp[ind][T-arr[ind]];     // this shows we add 1 (quantity of coin we take rn)....and we remain at the same index to check the same value again.
            dp[ind][T] = min(take, nottake);
        }
    }

    int ans = dp[n-1][tar];
    if(ans >= 1e9) return -1;
    return ans;
}

int main(){
    vector<int> arr = {2,1,3};
    int tar = 7;
    int n = arr.size();

    cout << "The min coins is : " << minimumEle(arr, tar);
    return 0;
}