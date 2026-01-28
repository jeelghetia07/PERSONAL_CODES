#include<bits/stdc++.h>
using namespace std;

                // TABULATIONS APPROACH 

// int LCS(string &s1, string &s2){
//     int n = s1.size();
//     int m = s2.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

//     for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
//     for(int j = 0 ; j <= m ; j++) dp[0][j] = 0;

//     int ans = 0;

//     for(int i = 1 ; i <= n ; i++){
//         for(int j = 1 ; j <= m ; j++){
//             if(s1[i-1] == s2[j-1]){
//                 dp[i][j] = 1 + dp[i-1][j-1];
//                 ans = max(ans, dp[i][j]);
//             }
//             else dp[i][j] = 0;     // becoz we have to find the consecutive string....not subsequence.
//         }
//     }
//     return ans;
// }


                // SPACE OPTIMIZED


int LCS(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    // for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;
    // for(int j = 0 ; j <= m ; j++) dp[0][j] = 0;

    int ans = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            }
            else curr[j] = 0;     // becoz we have to find the consecutive string....not subsequence.
        }
        prev = curr;
    }
    return ans;
}

int main(){
    string s1 = "aptedz";
    string s2 = "abtedy";

    cout << "The LC substring has len = " << LCS(s1, s2);
    return 0;
}