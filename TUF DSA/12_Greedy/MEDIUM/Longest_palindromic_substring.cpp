#include<bits/stdc++.h>
using namespace std;

/*      LC = 5
    Given a string s, return the longest palindromic substring in s.
*/

class Solution {
public:
    void expand(int l, int r, string &s, int& start, int& maxLen){
        while(l >= 0 && r < s.size() && (s[l] == s[r])){
            int len = r-l+1;        // window length.
            
            if(len > maxLen){
                start = l;
                maxLen = len;
            }
            
            l--, r++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        
        int maxLen = 0, start = 0; 
        
        for(int center = 0 ; center < n ; center++){
            // for odd length palindromes.... eg :- "aba".
            expand(center, center, s, start, maxLen);
            
            // for even length palindromes....eg :- "abba".
            expand(center, center+1, s, start, maxLen);
        }
        
        return s.substr(start, maxLen);
    }
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
        
        Constraints:

        1 <= s.length <= 1000
        s consist of only digits and English letters.
    */

    return 0;
}