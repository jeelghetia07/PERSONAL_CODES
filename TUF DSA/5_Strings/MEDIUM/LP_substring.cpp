#include<bits/stdc++.h>
using namespace std;

/*      LC = 5
    Given a string s, return the longest palindromic substring in s.
*/

/*
    The idea is :-
        We start expanding from the window from both sides from every index, and see which gives the maxLen,
        and palindrome doesnt alone mean odd len like "aba / babab", they can be of even length too, so we have to check for even length also
         like "abaaba / abba" etc.
*/

class Solution {
public:
    void expand(int left, int right, string& s, int& start, int& maxLen){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            int len = right-left+1;     // window length.

            if(len > maxLen){
                start = left;
                maxLen = len;
            }

            left--, right++;
        }
    }

    string longestPalindrome(string s){
        int n = s.size();

        int start = 0, maxLen = 0;

        for(int center = 0; center < n ; center++){
            // for odd length palindromes.... eg :- "aba".
            expand(center, center, s, start, maxLen);

            // for even length palindromes....eg :- "abba".
            expand(center, center+1, s, start, maxLen);
        }

        return s.substr(start, maxLen);
    }




    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     vector<vector<bool>> dp(n, vector<bool>(n, false));

    //     int start = 0, maxLen = 1;

    //     for(int i = 0 ; i < n ; i++){
    //         dp[i][i] = true;            // the element itself is palindirome....in aba...a == a and b is plaindrome.
    //     }

    //     for(int len = 2 ; len <= n ; len++){
    //         for(int i = 0 ; i+len-1 < n ; i++){     // the checking of ele should be 01 12 23 34...so length is 2 and index checking is from i = 0  to j = 1.
    //             int j = i+len-1;
                
    //             if(s[i] == s[j]){
    //                 if(len == 2 || dp[i+1][j-1]){
    //                     dp[i][j] = true;
    //                     if(len > maxLen){
    //                         maxLen = len;
    //                         start = i;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(start, maxLen);
    // }
};

int main(){
    /*
        Example 1:

        Input: s = "babad"
        Output: "bab"
        Explanation: "aba" is also a valid answer.

        
        Example 2:

        Input: s = "cbbd"
        Output: "bb"
    */

    return 0;
}