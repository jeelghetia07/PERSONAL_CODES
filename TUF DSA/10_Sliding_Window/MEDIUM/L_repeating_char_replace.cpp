#include<bits/stdc++.h>
using namespace std;

/*      LC = 424
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
    Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0, r = 0;
        int maxFreq = 0, maxLen = 0;

        vector<int> hash(26, 0);        // this keeps the freq.

        for(int r = 0 ; r < n ; r++){
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq, hash[s[r]-'A']);     // this updates the max freq.

            while((r-l+1) - maxFreq > k){
                hash[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "ABAB", k = 2
        Output: 4
        Explanation: Replace the two 'A's with two 'B's or vice versa.
        Example 2:

        Input: s = "AABABBA", k = 1
        Output: 4
        Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
        The substring "BBBB" has the longest repeating letters, which is 4.
        There may exists other ways to achieve this answer too.
    */

    return 0;
}