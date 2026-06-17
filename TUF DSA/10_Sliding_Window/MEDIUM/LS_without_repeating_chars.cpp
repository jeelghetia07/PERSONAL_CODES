#include<bits/stdc++.h>
using namespace std;

/*      LC = 3
    Given a string s, find the length of the longest substring without duplicate characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        vector<int> hash(256, -1);      // this hashtable stores 

        int l = 0, r = 0;
        int maxLen = 0;

        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){       // this is a repeating char found in the given range.
                    l = hash[s[r]] + 1;

                }
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "abcabcbb"
        Output: 3
        Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

        Example 2:

        Input: s = "bbbbb"
        Output: 1
        Explanation: The answer is "b", with the length of 1.
        
        Example 3:

        Input: s = "pwwkew"
        Output: 3
        Explanation: The answer is "wke", with the length of 3.
        Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
    */

    return 0;
}