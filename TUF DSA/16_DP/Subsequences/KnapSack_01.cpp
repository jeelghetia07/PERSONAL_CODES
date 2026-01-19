#include<bits/stdc++.h>
using namespace std;

// Problem Statement : We are given knapsack weight to be atmost maxweight....weight and value arrays are given of different items....we have to find the maximum value of items...said that we have limited weight in the knapsack...here..MaxWeight.

                        // MEMOIZATION APPROACH


// int f(int ind, int W, vector<int> &wt, vector<int>& val, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(wt[0] <= W) return val[0];
//         return 0;
//     }
//     if(dp[ind][W] != -1) return dp[ind][W];

    // int nontake = 0 + f(ind-1, W, wt, val, dp);
    // int take = INT_MIN;
    // if(wt[ind] <= W) take = val[ind] + f(ind-1, W-wt[ind], wt, val, dp);

//     return dp[ind][W] = max(take, nontake);
// }

// int knapsack(vector<int> &weight, vector<int>& value, int n, int maxWeight){
//     vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
//     return f(n-1, maxWeight, weight, value, dp);
// }


                        // TABULATION APPROACH

// int knapsack(vector<int> &wt, vector<int>& val, int n, int maxWeight){
//     vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
//     for(int W = wt[0] ; W <= maxWeight ; W++){      // very confusing
//         dp[0][W] = val[0]; 
//     }

//     for(int ind = 1 ; ind < n ; ind++){
//         for(int W = 0 ; W <= maxWeight ; W++){
//             int nontake = 0 + dp[ind-1][W];
//             int take = INT_MIN;
//             if(wt[ind] <= W) take = val[ind] + dp[ind-1][W-wt[ind]];

//             dp[ind][W] = max(nontake, take);
//         }
//     }
//     return dp[n-1][maxWeight];
// }



                    // TABULATION APPROACH SPACE OPTIMIZED...ONE ARRAY.

int knapsack(vector<int> &wt, vector<int>& val, int n, int maxWeight){
    vector<int> prev(maxWeight+1, 0);
    for(int W = wt[0] ; W <= maxWeight ; W++){     
        prev[W] = val[0]; 
    }

    for(int ind = 1 ; ind < n ; ind++){
        for(int W = maxWeight ; W >= 0 ; W--){
            int nontake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W) take = val[ind] + prev[W-wt[ind]];

            prev[W] = max(nontake, take);
        }
    }
    return prev[maxWeight];
}

int main(){
    vector<int> weight = {3,2,5};
    vector<int> value = {30,40,60};
    int n = weight.size();
    int maxWeight = 6;

    cout << "The maximum value is : " << knapsack(weight, value, n, maxWeight);
    return 0;
}