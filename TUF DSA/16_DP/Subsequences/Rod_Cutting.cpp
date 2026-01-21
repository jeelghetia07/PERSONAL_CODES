#include<bits/stdc++.h>
using namespace std;

// PROBLEM : 


                // recurrsion APPROACH.

// int f(int ind, int FinalRL, vector<int>& price){    // here N is the rod length we are searching for.
//     if(ind == 0){
//         return FinalRL * price[0];
//     }
//     int nontake = 0 + f(ind-1, FinalRL, price);
//     int take = INT_MIN;
//     int currRL = ind+1;  // the current rod length would be the ind+1 becoz the last index has lenght 5.
//     if(FinalRL >= currRL) take = price[ind] + f(ind, FinalRL-currRL, price);
//     return max(take, nontake);
// }

// int calc(vector<int>& price, int n){
//     return f(n-1, n, price);
// }



                // TABULATION APPROACH

// int calc(vector<int>& price, int n){
//     vector<vector<int>> dp(n, vector<int>(n+1, -1));

//     for(int currRL = 0 ; currRL <= n ; currRL++){
//         dp[0][currRL] = currRL * price[0];
//     }

//     for(int ind = 1 ; ind < n ; ind++){
//         for(int tarRL = 0 ; tarRL <= n ; tarRL++){
//             int nontake = 0 + dp[ind-1][tarRL];
//             int take = INT_MIN;
//             int currRL = ind+1;  
//             if(currRL <= tarRL) take = price[ind] + dp[ind][tarRL-currRL];

//             dp[ind][tarRL] = max(take, nontake);
//         }
//     }
//     return dp[n-1][n];
// }



                // SPACE OPTIMIZED

int calc(vector<int>& price, int n){
    vector<int> prev(n+1, 0), curr(n+1, 0);

    for(int currRL = 0 ; currRL <= n ; currRL++){
        prev[currRL] = currRL * price[0];
    }

    for(int ind = 1 ; ind < n ; ind++){
        for(int tarRL = 0 ; tarRL <= n ; tarRL++){
            int nontake = 0 + prev[tarRL];
            int take = INT_MIN;
            int currRL = ind+1;  
            if(currRL <= tarRL) take = price[ind] + curr[tarRL-currRL];

            curr[tarRL] = max(take, nontake);
        }
        prev = curr;
    }
    return prev[n];
}

int main(){
    vector<int> price = {2,5,7,8,10};
    int n = price.size();

    cout << "The max price is : " << calc(price, n);
    return 0;
}