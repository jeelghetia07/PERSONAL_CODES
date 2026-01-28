// Min_Ins_Dlt_A2B.cpp
#include<bits/stdc++.h>
using namespace std;

int LCS(string& s1, string& s2){
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
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int Min_Ins_Dlt(string& s1, string& s2){
    int n = s1.size();
    int m = s2.size();
    return n + m - 2 * LCS(s1,s2);
}

int main(){
    string s1 = "abcd", s2 = "anc";
    cout << "The total operations will be : " <<Min_Ins_Dlt(s1,s2);
    return 0;
}