#include<bits/stdc++.h>
using namespace std;

/*      LC = GFG
    You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

    Note : If no such substring exists, return -1. 
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        
        int l = 0, maxLen = 0;
        unordered_map<int, int> mpp;
        
        for(int r = 0 ; r < n ; r++){
            mpp[s[r]-'a']++;
            
            // while(mpp.size() > k){      // this will take a tc of O(n). totalling at O(2n). but if we want to trim it down, then just remove one left ele and keep expanding till its not valid.
            if(mpp.size() > k){
                mpp[s[l]-'a']--;
                if(mpp[s[l]-'a'] == 0) mpp.erase(s[l]-'a');
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
        }
        
        if(mpp.size() < k) return -1;       // in case the total disticnt letter are less than k.
        
        return maxLen;
    }
};

int main(){
    /*
        Input: s = "aabacbebebe", k = 3
        Output: 7
        Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

        Input: s = "aaaa", k = 2
        Output: -1
        Explanation: There's no substring with 2 distinct characters.

        Input: s = "aabaaab", k = 2
        Output: 7
        Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
    */

    return 0;
}