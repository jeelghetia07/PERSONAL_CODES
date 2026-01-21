#include<bits/stdc++.h>
using namespace std;

// PROBLEM :
/* 
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
    You may assume that you have an infinite number of each kind of coin.
    The answer is guaranteed to fit into a signed 32-bit integer. 

    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000
*/


                // MEMOIZATION APPROACH      ..TC = exponantial...due to standing on the same ind for take conditiions.

// int f(int ind, int k, vector<int> &arr){
//     if(ind == 0){
//         if(k % arr[ind] == 0) return 1;
//         else return 0;
//     }

//     int nontake = f(ind-1, k, arr);
//     int take = 0;
//     if(k >= arr[ind]) take = f(ind, k-arr[ind], arr);

//     return take + nontake;
// }



                // TABULATION APPROACH.

// int change(int k, vector<int>& arr){
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));

//     for(int t = 0 ; t <= k ; t++){
//         dp[0][t] = (t % arr[0] == 0);
//     }

//     for(int ind = 1 ; ind < n ; ind++){
//         for(int tar = 0 ; tar <= k ; tar++){
//             int nontake = dp[ind-1][tar];
//             int take = 0;
//             if(tar >= arr[ind]) take = dp[ind][tar-arr[ind]];

//             dp[ind][tar] = nontake + take;
//         }
//     }
//     return dp[n-1][k];
//     // return f(n-1, tar, arr);
// }



                    // SPACE OPTIMIZED

int change(int k, vector<int>& arr){
    int n = arr.size();
    vector<int> prev(k+1, -1), curr(k+1, -1);

    for(int t = 0 ; t <= k ; t++){
        prev[t] = (t % arr[0] == 0);
    }

    for(int ind = 1 ; ind < n ; ind++){
        for(int tar = 0 ; tar <= k ; tar++){
            int nontake = prev[tar];
            int take = 0;
            if(tar >= arr[ind]) take = curr[tar-arr[ind]];

            curr[tar] = nontake + take;
        }
        prev = curr;
    }
    return prev[k];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << "The number of combinations : " << change(amount, coins);
    return 0;
}