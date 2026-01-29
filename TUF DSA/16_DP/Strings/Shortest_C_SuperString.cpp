// Shortest_C_SuperString.cpp
#include<bits/stdc++.h>
using namespace std;

//Problem Statement: We are given two strings ‘S1’ and ‘S2’. We need to return their shortest common supersequence. A supersequence is defined as the string which contains both the strings S1 and S2 as subsequences.

string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int j = 0 ; j <= m ; j++) dp[0][j] = 0;       // this is for the negative index base cases.
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[n][m];    
    string ans = "";

    // int index = len-1;
    int i = n, j = m;

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans += s1[i-1];
            i--;
        }
        else{
            ans += s2[j-1];
            j--;
        }
    }

    while(i > 0){
        ans += s1[i-1];
            i--;
    }
    while(j > 0){
        ans += s2[j-1];
            j--;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1 = "abcd", s2 = "anc";
    string ans = shortestCommonSupersequence(s1, s2);
    cout << ans << endl;
    return 0;
}