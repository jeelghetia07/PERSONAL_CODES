#include<bits/stdc++.h>
using namespace std;

/*      LC = 2472
    You are given a string s and a positive integer k.

    Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

    The length of each substring is at least k.
    Each substring is a palindrome.
    Return the maximum number of substrings in an optimal selection.

    A substring is a contiguous sequence of characters within a string.
*/

class Solution {
public:
    bool isPalindrome(int l, int r, string& s){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }

        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        
        int cnt = 0;
        int last = -1;      // the last index where a palindrome ended.

        for(int i = k-1 ; i < n ; i++){
            for(int l = last+1 ; l <= i-k+1 ; l++){
                if(isPalindrome(l, i, s)){
                    cnt++;
                    last = i;
                    break;
                }
            }
        }

        return cnt;
    }
};



                    // THIS IS THE DP SOLUTION.



/*
    bool isPalindrome(int l, int r, string& s){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }

        return true;
    }

    // max no. of valid non-overlapping palindromes we can select from s[i.....n-1].
    // means the best answer from i to the end.
    int func(int ind, string &s, int n, int k, vector<int>& dp){
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];
        
        // Skip the ith index., Maybe the next useful palindrome starts at i+1, i+2, etc.
        int ans = func(ind+1, s, n, k, dp);    

        for(int j = ind+k-1 ; j < n ; j++){
            if(isPalindrome(ind,j,s)){
                ans = max(ans, 1+func(j+1, s, n, k, dp));
            }
        }

        return dp[ind] = ans;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n, -1);

        return func(0, s, n, k, dp);
    }
*/

int main(){
    /*
        Example 1:

        Input: s = "abaccdbbd", k = 3
        Output: 2
        Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
        It can be shown that we cannot find a selection with more than two valid substrings.

        
        Example 2:

        Input: s = "adbcda", k = 2
        Output: 0
        Explanation: There is no palindrome substring of length at least 2 in the string.
        

        Constraints:

        1 <= k <= s.length <= 2000
        s consists of lowercase English letters.
    */

    return 0;
}