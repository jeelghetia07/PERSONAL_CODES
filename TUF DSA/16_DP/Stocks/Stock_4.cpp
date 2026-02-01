#include<bits/stdc++.h>
using namespace std;

/*
    We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed

    We can buy and sell the stock any number of times.
    In order to sell the stock, we need to first buy it on the same or any afterious day.
    We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any afteriously bought stock.
    We can do at most K transactions
*/

                // MEMOIZATION

// int f(int ind, int tranNo, vector<int>& arr, int n, int k, vector<vector<int>>& dp){
//     if(ind == n || tranNo == 2*k) return 0;
//     if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
//     int profit = 0;
//     if(tranNo % 2 == 0){
//         return dp[ind][tranNo] = max(-arr[ind] + f(ind+1, tranNo+1, arr, n, k, dp),
//                         0 + f(ind+1, tranNo, arr, n, k, dp));
//     }
//     return dp[ind][tranNo] = max(arr[ind] + f(ind+1, tranNo+1, arr, n, k, dp),
//                         0 + f(ind+1, tranNo, arr, n, k, dp));
// }

// int maxProfit(vector<int>& arr,int n, int k){
//     vector<vector<int>> dp(n+1, vector<int>(2*k, -1));
//     return f(0, 0, arr, n, k, dp);
// }




                // TABULATION.....reverse of memoization

// int maxProfit(vector<int>& arr,int n, int k){

//     vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

//     for(int ind = n-1; ind >= 0 ; ind--){
//         for(int tranNo = 2*k-1 ; tranNo >= 0 ; tranNo--){
//             if(tranNo % 2 == 0){
//                 dp[ind][tranNo] = max(-arr[ind] + dp[ind+1][tranNo+1],
//                                 0 + dp[ind+1][tranNo]);
//             }
//             else{
//                 dp[ind][tranNo] = max(arr[ind] + dp[ind+1][tranNo+1],
//                                 0 + dp[ind+1][tranNo]);
//             }                    
//         }
//     }
//     return dp[0][0];
// }             




                // SPACE OPTIMIZATION

int maxProfit(vector<int>& arr,int n, int k){
    vector<int> after(2*k+1, 0), curr(2*k+1, 0);

    for(int ind = n-1; ind >= 0 ; ind--){
        for(int tranNo = 2*k-1 ; tranNo >= 0 ; tranNo--){
            if(tranNo % 2 == 0){
                curr[tranNo] = max(-arr[ind] + after[tranNo+1],
                                0 + after[tranNo]);
            }
            else{
                curr[tranNo] = max(arr[ind] + after[tranNo+1],
                                0 + after[tranNo]);
            }                    
        }
        after = curr;
    }
    return after[0];
}  


                // TABULATION.


// int maxProfit(vector<int>& arr, int k){
//     int n = arr.size();
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

//     // not writing the base case becoz..the array is already initialized to 0.

//     // for(int ind = 0 ; ind <= n ; ind++){         // base cases.
//     //     for(int buy = 0 ; buy <= 1 ; buy++){
//     //         dp[ind][buy][0] = 0;
//     //     }
//     // }
//     // for(int buy = 0 ; buy <= 1 ; buy++){
//     //     for(int cap = 0 ; cap <= k ; cap++){
//     //         dp[n][buy][cap] = 0;
//     //     }
//     // }

//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int buy = 0 ; buy <= 1 ; buy++){
//             for(int cap = 1 ; cap <= k ; cap++){
//                 if(buy){
//                     dp[ind][buy][cap] = max(-arr[ind] + dp[ind+1][0][cap],
//                                     0 + dp[ind+1][1][cap]);
//                 }
//                 else{
//                     dp[ind][buy][cap] = max(arr[ind] + dp[ind+1][1][cap-1],
//                                     0 + dp[ind+1][0][cap]);
//                 }
//             }
//         }
//     }
//     return dp[0][1][k];
// }

int main(){
    vector<int> arr= {3,3,5,0,0,3,4,7,8};
    int k = 3;
    cout << "The max Profit : " << maxProfit(arr,arr.size(), k);
    return 0;
}