#include<bits/stdc++.h>
using namespace std;

// we can not buy after sell....but we have unlimited transactions.


                    // MEMOIZATION 

// int f(int ind, int buy, vector<int>& arr, int n, vector<vector<int>>& dp){
//     if(ind >= n) return 0;
//     if(dp[ind][buy] != -1) return dp[ind][buy];

//     if(buy){
//         return dp[ind][buy] = max(-arr[ind] + f(ind+1, 0, arr, n, dp),
//                     0 + f(ind+1, 1, arr, n, dp));
//     }
//     return dp[ind][buy] = max(arr[ind] + f(ind+2, 1, arr, n, dp),
//                 0 + f(ind+1, 0, arr, n, dp));
// }

// int maxProfit(vector<int>& arr){
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     return f(0,1, arr, n, dp);
// }



                // TABULATION APPROACH


// int maxProfit(vector<int>& arr){
//     int n = arr.size();
//     vector<vector<int>> dp(n+2, vector<int>(2, 0));

//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int buy = 0 ; buy <= 1 ; buy++){
//             if(buy){
//                 dp[ind][buy] = max(-arr[ind] + dp[ind+1][0],
//                             0 + dp[ind+1][1]);
//             }
//             else{
//                 dp[ind][buy] = max(arr[ind] +dp[ind+2][1],
//                             0 + dp[ind+1][0]);
//             }
//         }
//     }
//     return dp[0][1];
// }



                // SPACE OPTMIZED

int maxProfit(vector<int>& arr){
    int n = arr.size();
    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> curr(2, 0);

    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int buy = 0 ; buy <= 1 ; buy++){
            if(buy){
                curr[buy] = max(-arr[ind] + front1[0],
                            0 + front1[1]);
            }
            else{
                curr[buy] = max(arr[ind] + front2[1],
                            0 + front1[0]);
            }
        }
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}


int main(){
    vector<int> arr = {1,2,3,0,2};
    int n = arr.size();
    cout << "The max profit is : " << maxProfit(arr) << endl;
}