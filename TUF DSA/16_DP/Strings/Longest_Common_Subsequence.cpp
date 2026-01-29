// Longest_Common_Subsequence.cpp
#include<bits/stdc++.h>
using namespace std;

//Problem Statement: Given two strings str1 and str2, find the length of their longest common subsequence. A subsequence is a sequence that appears in the same relative order but not necessarily contiguous and a common subsequence of two strings is a subsequence that is common to both strings.

// int func(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp){
//     if(ind1 < 0 || ind2 < 0){
//         return 0;
//     }
//     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//     if(s1[ind1] == s2[ind2]){
//         return dp[ind1][ind2] = 1 + func(ind1-1, ind2-1, s1, s2, dp);
//     }
//     return  dp[ind1][ind2] = 0 + max(func(ind1-1, ind2, s1, s2, dp), func(ind1, ind2-1, s1, s2, dp));
// }

// int LCS(string& s1, string& s2){
//     int n = s1.length();
//     int m = s2.length();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return func(n-1, m-1, s1,s2,dp);
// }


                // RIGHT SHIFTING OF INDEXES WHERE 0 means -1 .....n means n-1;

// int func(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp){
//     if(ind1 == 0 || ind2 == 0){
//         return 0;
//     }
//     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//     if(s1[ind1-1] == s2[ind2-1]){               // as i said....above.
//         return dp[ind1][ind2] = 1 + func(ind1-1, ind2-1, s1, s2, dp);
//     }
//     return  dp[ind1][ind2] = 0 + max(func(ind1-1, ind2, s1, s2, dp), func(ind1, ind2-1, s1, s2, dp));
// }

// int LCS(string& s1, string& s2){
//     int n = s1.length();
//     int m = s2.length();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));            // creating a bigger dp array.
//     return func(n, m, s1,s2,dp);      // calling the n and m indexes...means whats actually called is n-1 and m-1.
// }



                            // TABULATION METHOD

// int LCS(string& s1, string& s2){
//     int n = s1.length();
//     int m = s2.length();

//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));            

//     for(int j = 0 ; j < m ; j++) dp[0][j] = 0;
//     for(int i = 0 ; i < n ; i++) dp[i][0] = 0;

//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 1 ; j <= m ; j++){
//             if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     return dp[n][m];      
// }


                    // SPACE OPTIMZED.

int LCS(string& s1, string& s2){
    int n = s1.length();
    int m = s2.length();

    vector<int> prev(m+1, 0), curr(m+1, 0);            

    for(int j = 0 ; j < m ; j++) prev[j] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];      
}

int main(){
    string s1 = "acd";
    string s2 = "ced";

    cout << "The LCS is : " << LCS(s1,s2);
    return 0;
}