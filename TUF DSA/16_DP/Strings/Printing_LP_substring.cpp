// Printing_LP_substring.cpp
#include<bits/stdc++.h>
using namespace std;

string LongestPali(string& s){
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0, maxLen = 1;

    for(int i = 0 ; i < n ; i++){
        dp[i][i] = true;            // the element itself is palindirome....in aba...a == a and b is plaindrome.
    }

    for(int len = 2 ; len <= n ; len++){
        for(int i = 0 ; i+len-1 < n ; i++){     // the checking of ele should be 01 12 23 34...so length is 2 and index checking is from i = 0  to j = 1.
            int j = i+len-1;

            if(s[i] == s[j]){
                if(len == 2 || dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(len > maxLen){
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
    }
    return s.substr(start, maxLen);
}

int main(){
    string s = "babad";
    cout << LongestPali(s);
}