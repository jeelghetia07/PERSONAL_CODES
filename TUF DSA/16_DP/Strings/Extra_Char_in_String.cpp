#include<bits/stdc++.h>
using namespace std;

/*      LC = 2707
    You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

    Return the minimum number of extra characters left over if you break up s optimally.
*/

class Solution {
public:
    // int func(int start, string& s, int n, unordered_set<string>& st, vector<int>& dp){
    //     if(start == n) return 0;

    //     if(dp[start] != -1) return dp[start];

    //     int ans = 1 + func(start+1, s, n, st, dp);
    //     string temp = "";
    //     for(int end = start ; end < n ; end++){
    //         temp += s[end];
    //         if(st.find(temp) != st.end()){
    //             ans = min(ans, func(end+1, s, n, st, dp));
    //         }
    //     }
    //     return dp[start] = ans;
    // }
    // int minExtraChar(string s, vector<string>& dict) {
    //     int n = s.size();
    //     unordered_set<string> st(dict.begin(), dict.end());

    //     vector<int> dp(n, -1);

    //     return func(0, s, n, st, dp);
    // }


    int minExtraChar(string s, vector<string>& dict){
        int n = s.size();
        unordered_set<string> st(dict.begin(), dict.end());

        vector<int> dp(n, 0);


        for(int start = n-1 ; start >= 0 ; start--){
            int ans = 1 + dp[start+1];
            string temp = "";
            for(int end = start ; end < n ; end++){
                temp += s[end];
                if(st.find(temp) != st.end()){
                    ans = min(ans, dp[end+1]);
                }
            }
            dp[start] = ans;
        }
        return dp[0];
    }

};

int main(){
    string s = "leetscode";
    vector<string> dictionary = {"leet","code","leetcode"};     // ans = 1;
    // Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

    // string s = "sayhelloworld";
    // vector<string> dictionary = {"hello","world"};   // ans = 3
    // Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.

    Solution obj;
    int ans = obj.minExtraChar(s,dictionary);

    cout << ans;

    return 0;
}