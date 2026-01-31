#include<bits/stdc++.h>
using namespace std;

/* 
    Buy and Sell Stock - II 
    We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
    We can buy and sell the stock any number of times.
    In order to sell the stock, we need to first buy it on the same or any previous day.
    We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
*/


                    // SIMPLE METHOD


// int maxProfit(vector<int>& prices) {
//     int profit=0;

//     for(int i=1;i<prices.size();i++)
//     {
//         if(prices[i]>prices[i-1])
//         {
//             profit+=prices[i]-prices[i-1];
//         }
//     }
//     return profit;
// }



                    // MEMOIZATION


// int f(int ind, int buy, vector<int>& arr, int n, vector<vector<int>>& dp){
//     if(ind == n){
//         return 0;
//     }
//     if(dp[ind][buy] != -1) return dp[ind][buy];
//     int profit = 0;

//     if(buy){
//         profit = max(-arr[ind] + f(ind+1, 0, arr, n, dp),
//                         0 + f(ind+1, 1, arr, n, dp));
//     }
//     else{
//         profit = max(arr[ind] + f(ind+1, 1, arr, n, dp),
//                         0 + f(ind+1, 0, arr, n, dp));
//     }
//     return dp[ind][buy] = profit;
// }

// int maxProfit(vector<int>& arr){
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     return f(0, 1, arr, n, dp);
// }





                    // TABULATION


// int maxProfit(vector<int>& arr){
//     int n = arr.size();
//     vector<vector<int>> dp(n+1, vector<int>(2, 0));

//     dp[n][0] = dp[n][1] = 0;

//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int buy = 0 ; buy <= 1 ; buy++){
//             int profit = 0;
//             if(buy){
//                 profit = max(-arr[ind] + dp[ind+1][0],
//                                 0 + dp[ind+1][1]);
//             }
//             else{
//                 profit = max(arr[ind] + dp[ind+1][1],
//                                 0 + dp[ind+1][0]);
//             }
//             dp[ind][buy] = profit;
//         }
//     }
//     return dp[0][1];
// }





                        // SPACE OPTIMIZED

int maxProfit(vector<int>& arr){
    int n = arr.size();
    vector<int> ahead(2, 0), curr(2, 0);

    ahead[0] = ahead[1] = 0;

    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            int profit = 0;
            if(buy){
                profit = max(-arr[ind] + ahead[0],
                                0 + ahead[1]);
            }
            else{
                profit = max(arr[ind] + ahead[1],
                                0 + ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    cout << "The max Profit is : " << maxProfit(arr);
    return 0;
}