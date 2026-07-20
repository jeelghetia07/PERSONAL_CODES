#include<bits/stdc++.h>
using namespace std;

/*      LC = 76
    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

    The testcases will be generated such that the answer is unique.
*/

class Solution {
public:
    string func(string& s, string& t, int n, int m){
        int minLen = 1e9, startInd = -1;        // to find the substring using the inbuilt func.
        
        vector<int> hash(256, 0);       // stores the freq.

        for(int i = 0 ; i < m ; i++){       // initially pushing all the ele freq into the map.
            hash[t[i]]++;
        }

        int l = 0, r = 0, cnt = 0;      // this cnt represents that if cnt = 1, means we found one ele from t in s.
        
        while(r < n){
            if(hash[s[r]] > 0) cnt++;       // found a same char as t.
            hash[s[r]]--;

            while(cnt == m){        // this means we found all the 3 chars in a particular substring, now we have to shrink the left to check for a smaller substring.
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    startInd = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return (startInd == -1) ? "" : s.substr(startInd, minLen);
    }
    string minWindow(string s, string t){
        int n = s.size(), m = t.size();

        return func(s,t,n,m);
    }




    // string minWindow(string s, string t) {
    //     int n = s.size(), m = t.size();
    //     int minLen = 1e9, startInd = -1;

    //     for(int i = 0 ; i < n ; i++){
    //         vector<int> hash(256, 0);
    //         int cnt = 0;
    //         for(int j = 0 ; j < m ; j++) hash[t[j]]++;
            
    //         for(int j = i ; j < n ; j++){
    //             if(hash[s[j]] > 0) cnt++;
    //             hash[s[j]]--;
    //             if(cnt == m){
    //                 if(j-i+1 < minLen){
    //                     minLen = j-i+1;
    //                     startInd = i;
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    //     if(startInd == -1) return "";
    //     return s.substr(startInd, minLen);

    // }
};

int main(){
    /*
        Example 1:

        Input: s = "ADOBECODEBANC", t = "ABC"
        Output: "BANC"
        Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


        Example 2:

        Input: s = "a", t = "a"
        Output: "a"
        Explanation: The entire string s is the minimum window.

        
        Example 3:

        Input: s = "a", t = "aa"
        Output: ""
        Explanation: Both 'a's from t must be included in the window.
        Since the largest window of s only has one 'a', return empty string.
    */

    return 0;
}