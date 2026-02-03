// L_Increasing_Subseq.cpp
#include<bits/stdc++.h>
using namespace std;


            // RECURSIVE APPROACH

// int func(int ind, int prev_ind, vector<int>& arr, int n){
//     if(ind == n) return 0;

//     int len = 0 + func(ind+1, prev_ind, arr, n);
//     if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
//         len = max(len, 1 + func(ind+1, ind, arr, n));
//     }

//     return len;
// }

// int longestIncrSubseq(vector<int>& arr, int n){
//     return func(0, -1, arr, n);
// }



            // MEMOIZATION

// int func(int ind, int prev_ind, vector<int>& arr, int n, vector<vector<int>>& dp){
//     if(ind == n) return 0;
//     if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];      // dp[ind][-1] not valid...so we store it in dp[ind][0].

//     int len = 0 + func(ind+1, prev_ind, arr, n, dp);
//     if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
//         len = max(len, 1 + func(ind+1, ind, arr, n, dp));
//     }

//     return dp[ind][prev_ind+1] = len;
// }

// int longestIncrSubseq(vector<int>& arr, int n){
//     vector<vector<int>> dp(n, vector<int>(n+1, -1));       // we are caling index normally form 0 to n-1 so dp[n]    but the prev_ind is stored at -1 so we shift it to 0....hence dp[n][n+1];
//     return func(0, -1, arr, n, dp);
// }




            // TABULATION

// int longestIncrSubseq(vector<int>& arr, int n){
//     // here for ind also we did n+1...becoz we are calling dp[ind+1]...and if there is only n-1 indexes....we cant have n....so we do n+1.
//     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));       // we are caling index normally form 0 to n-1 so dp[n]    but the prev_ind is stored at -1 so we shift it to 0....hence dp[n][n+1];
//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind--){
//             int len = 0 + dp[ind+1][prev_ind+1];
//             if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
//                 len = max(len, 1 + dp[ind+1][ind+1]);
//             }
//             dp[ind][prev_ind+1] = len;
//         }
//     }
//     return dp[0][-1+1];
// }




            // SPACE OPTIMIZED

// int longestIncrSubseq(vector<int>& arr, int n){
//     // here for ind also we did n+1...becoz we are calling dp[ind+1]...and if there is only n-1 indexes....we cant have n....so we do n+1.
//     vector<int> ahead(n+1, 0);       // we are caling index normally form 0 to n-1 so dp[n]    but the prev_ind is stored at -1 so we shift it to 0....hence dp[n][n+1];
//     vector<int> curr(n+1, 0);       // we are caling index normally form 0 to n-1 so dp[n]    but the prev_ind is stored at -1 so we shift it to 0....hence dp[n][n+1];
//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind--){
//             int len = 0 + ahead[prev_ind+1];
//             if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
//                 len = max(len, 1 + ahead[ind+1]);
//             }
//             curr[prev_ind+1] = len;
//         }
//         ahead = curr;
//     }
//     return curr[-1+1];
// }




            // OTHER TABULATION APPROACH

// int longestIncrSubseq(vector<int>& arr, int n){
//     vector<int> dp(n, 1);    // initially the longest incre subseq of a particular ele will be itself...so len = 1;
//     int maxi = 1;
//     for(int i = 0 ; i < n ; i++){
//         for(int prev = 0 ; prev < i ; prev++){
//             if(arr[prev] < arr[i]){
//                 dp[i] = max(dp[i], 1 + dp[prev]);
//             }
//         }
//         maxi = max(maxi, dp[i]);
//     }
//     return maxi;
// }




            // USING BINARY SEARCH.....TC = O(nlogn)....SC = O(n).

int longestIncrSubseq(vector<int>& arr, int n){
    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i = 1 ; i < n ; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main(){
    vector<int> arr = {10, 9, 2, 3, 5, 101, 18};
    int n = arr.size();

    cout << "The max Length of LIS is : " << longestIncrSubseq(arr, n);
    return 0;
}