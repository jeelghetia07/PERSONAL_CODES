#include<bits/stdc++.h>
using namespace std;

/* Problem Statement : Given two strings s and t, return the number of distinct subsequences of s that equal t.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.

The task is to count how many different ways we can form t from s by deleting some (or no) characters from s. */ 



// int func(int i, int j, string s1, string s2){
//     if(j < 0) return 1;     // this means...the s2 is completed means we found the full s2 into the s1...so increase the count by 1.
//     if(i < 0) return 0;     // the s1 string completed but we didnt find the s2 in s1.

//     if(s1[i] == s2[j]){
//         return func(i-1, j-1, s1, s2) + func(i-1, j, s1, s2);
//     }
//     return func(i-1, j, s1, s2);
// }

// int numDistinct(string s1, string s2){
//     int n = s1.size();
//     int m = s2.size();

//     return func(n-1, m-1, s1, s2);
// }


                // MEMOIZATION

// int func(int i, int j, string s1, string s2, vector<vector<int>>& dp){
//     if(j < 0) return 1;     // this means...the s2 is completed means we found the full s2 into the s1...so increase the count by 1.
//     if(i < 0) return 0;     // the s1 string completed but we didnt find the s2 in s1.

//     if(dp[i][j] != -1) return dp[i][j];

//     if(s1[i] == s2[j]){
//         return dp[i][j] = func(i-1, j-1, s1, s2, dp) + func(i-1, j, s1, s2, dp);
//     }
//     return dp[i][j] = func(i-1, j, s1, s2, dp);
// }

// int numDistinct(string s1, string s2){
//     int n = s1.size();
//     int m = s2.size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return func(n-1, m-1, s1, s2, dp);
// }



                // MEMOIZATION (1 BASED INDEXING)

// int func(int i, int j, string s1, string s2, vector<vector<int>>& dp){
//     if(j == 0) return 1;     // this means...the s2 is completed means we found the full s2 into the s1...so increase the count by 1.
//     if(i == 0) return 0;     // the s1 string completed but we didnt find the s2 in s1.

//     if(dp[i][j] != -1) return dp[i][j];

//     if(s1[i-1] == s2[j-1]){
//         return dp[i][j] = func(i-1, j-1, s1, s2, dp) + func(i-1, j, s1, s2, dp);
//     }
//     return dp[i][j] = func(i-1, j, s1, s2, dp);
// }

// int numDistinct(string s1, string s2){
//     int n = s1.size();
//     int m = s2.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//     return func(n, m, s1, s2, dp);
// }



                // TABULATION

// int numDistinct(string s1, string s2){
//     int n = s1.size();
//     int m = s2.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

//     for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;    
//     for(int j = 1 ; j <= m ; j++) dp[0][j] = 0;     // this is imp...if i run the loop from j = 0...then it will modify the upper loop output.

//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 1; j <= m ; j++){
//             if(s1[i-1] == s2[j-1]){
//                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//             }
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     return dp[n][m];
// }





                    // SPACE OPTIMIZED

// int numDistinct(string s1, string s2){
//     int n = s1.size();
//     int m = s2.size();
//     vector<int> prev(m+1, 0), curr(m+1, 0);

//     prev[0] = curr[0] = 1;

//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 1; j <= m ; j++){
//             if(s1[i-1] == s2[j-1]){
//                 curr[j] = prev[j-1] + prev[j];
//             }
//             else curr[j] = prev[j];
//         }
//         prev = curr;
//     }
//     return prev[m];
// }




                    // ULTRA SPACE OPTIMIZED

int numDistinct(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1, 0);

    prev[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        for(int j = m; j >= 0 ; j--){
            if(s1[i-1] == s2[j-1]){
                prev[j] = prev[j-1] + prev[j];
            }
            else prev[j] = prev[j];
        }
    }
    return prev[m];
}

int main(){
    string s1 = "babgbag", s2 = "bag";
    cout << "The distinct subseq are : " << numDistinct(s1,s2);
    return 0;
}