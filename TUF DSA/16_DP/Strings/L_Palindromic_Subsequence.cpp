#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given a string, Find the longest palindromic subsequence length in given string. A palindrome is a sequence that reads the same backwards as forward. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

int LCS(string& s1, string&s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j = 0 ; j <= m ; j++) dp[0][j] = 0;         // this is for the negative index base cases.
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[n][m];     // fining the lenght of the LCS and then make a string.
    string ans = "";

    for(int i = 0 ; i < len ; i++){       // just add anything in the string.
        ans += '$';
    }

    int index = len-1;
    int i = n, j = m;

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            index--;
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else j--;
    }

    cout << ans << endl; 
    return dp[n][m];
}

int LPS(string& s1){
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return LCS(s1,s2);
}

int main(){
    string s1 = "bbabcbcab";
    cout << "The max LPS is : " << LPS(s1);
    return 0;
}