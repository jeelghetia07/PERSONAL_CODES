#include<bits/stdc++.h>
using namespace std;

/*      LC = 139
    Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
    Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Solution{
public:
    // bool solve(int start, string& s, unordered_set<string>& set, int n, vector<int>& dp){
    //     if(start == n){
    //         return true;
    //     }

    //     if(dp[start] != -1) return dp[start];

    //     for(int end = start ; end < n ; end++){
    //         // string word = s.substr(start, end - start + 1);      // this is has a TC = O(n)....substr(starting ind, length);
    //         string word = "";
    //         int k = start;
    //         while(k <= end){
    //             word += s[k];
    //             k++;
    //         }
    //         if(set.find(word) != set.end()){
    //             if(solve(end+1, s, set, n, dp)) return dp[start] = true;
    //         }
    //     }
    //     return dp[start] = false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     int n = s.size();
    //     unordered_set<string> set;

    //     vector<int> dp(n, -1);
    //     for(auto it : wordDict){
    //         set.insert(it);
    //     }
    //     return solve(0, s, set, n, dp);
    // }



    bool wordBreak(string s, vector<string>& dict){
        int n = s.size();
        unordered_set<string> set(dict.begin(), dict.end());
        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int start = n-1 ; start >= 0 ; start--){
            for(int end = start ; end < n ; end++){
                string word = s.substr(start, end - start + 1);      // this is has a TC = O(n)....substr(starting ind, length);
                if(set.find(word) != set.end()){
                    if(dp[end+1]){
                        dp[start] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};      // true

    string s1 = "applepenapple";
    vector<string> wordDict = {"apple","pen"};      //true;

    string s2 = "catsandog";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};

    return 0;
}