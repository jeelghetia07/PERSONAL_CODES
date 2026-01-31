#include<bits/stdc++.h>
using namespace std;

/* 
    We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

    We can buy and sell the stock any number of times.
    In order to sell the stock, we need to first buy it on the same or any previous day.
    We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
    We can do at most 2 transactions.

*/



                    // MEMOIZATION


// int f(int ind, int buy, int cap, vector<int>& arr, vector<vector<vector<int>>>& dp){
//     int n = arr.size();
//     if(cap == 0 || ind == n) return 0;
//     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

//     int profit = 0;
//     if(buy){
//         profit = max(-arr[ind] + f(ind+1, 0, cap, arr, dp),
//                         0 + f(ind+1, 1, cap, arr, dp));
//     }
//     else{
//         profit = max(arr[ind] + f(ind+1, 1, cap-1, arr, dp),
//                         0 + f(ind+1, 0, cap, arr, dp));
//     }
//     return dp[ind][buy][cap] = profit;
// }

// int maxProfit(vector<int>& arr) {
//     int n = arr.size();
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//     return f(0, 1, 2, arr, dp);
// }




                    // TABULATION


// int maxProfit(vector<int>& arr) {
//     int n = arr.size();
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int buy = 0 ; buy <= 1 ; buy++){
//             for(int cap = 1 ; cap <= 2 ; cap++){
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
//     return dp[0][1][2];
// }



                // SPACE OPTIMIZED

int maxProfit(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            for(int cap = 1 ; cap <= 2 ; cap++){
                if(buy){
                    curr[buy][cap] = max(-arr[ind] + after[0][cap],
                                    0 + after[1][cap]);
                }
                else{
                    curr[buy][cap] = max(arr[ind] + after[1][cap-1],
                                    0 + after[0][cap]);
                }
            }
        }
        after = curr;
    }
    return after[1][2];
}

int main(){
    vector<int> arr= {3,3,5,0,0,3,4,7};
    cout << "The max Profit : " << maxProfit(arr);
    return 0;
}