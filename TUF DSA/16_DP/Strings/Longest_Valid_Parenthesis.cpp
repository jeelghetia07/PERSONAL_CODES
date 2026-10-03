#include<bits/stdc++.h>
using namespace std;

/*      LC = 32
    Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
*/

class Solution {
public:
    // The LVP_substring exactly ending at index ind.
    int func(int i, string& s, vector<int>& dp, int n){
        if(i <= 0) return 0;
        if(s[i] == '(') return 0;   // This can never be the ending of a substring.
        if(dp[i] != -1) return dp[i];

        int ans = 0;

        if(s[i] == ')'){
            if(s[i-1] == '('){
                ans = 2;
                if(i >= 2) ans += func(i-2, s, dp, n);
            }
            else if(s[i-1] == ')'){
                int prev = func(i-1, s, dp, n);     // this will give the length of the maximum valid substring ending at i.
                int index = i - prev - 1;       // and this will give the prev index where the whole substring started which is definitely '('

                if(index >= 0 && s[index] == '('){
                    ans = 2 + prev;         // this means adding the current ')' and the starting '(' that forms the full substring including prev, and the prev thats the middle valid substring length.
                    if(index-1 >= 0){
                        ans += func(index-1, s, dp, n);
                    }
                }
            }

        }
        return dp[i] = ans;
    }
    int longestValidParentheses(string s) {
        int n = s.size();

        vector<int> dp(n, -1);
        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi, func(i, s, dp, n));
        }

        return maxi;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "(()"
        Output: 2
        Explanation: The longest valid parentheses substring is "()".


        Example 2:

        Input: s = ")()())"
        Output: 4
        Explanation: The longest valid parentheses substring is "()()".


        Example 3:

        Input: s = ""
        Output: 0
        
        Constraints:

        0 <= s.length <= 3 * 104
        s[i] is '(', or ')'.
    */

    return 0;
}