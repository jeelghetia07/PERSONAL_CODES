#include<bits/stdc++.h>
using namespace std;

/*     GFG
    Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

    The two identified subsequences A and B can use the same ith character from string s if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of the first "x" must be different in the original string for A and B.
*/

class Solution {
  public:
    int LCS(int i, int j, string& s, string& t, int n){
        if(i == n || j == n) return 0;
        
        if(s[i] == t[j] && i != j){
            return 1 + LCS(i+1, j+1, s, t, n);
        }
        return 0 + max(LCS(i+1, j, s, t, n), LCS(i, j+1, s, t, n));
    }
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        string t = s;
        int n = s.size();
        return LCS(0, 0, s, t, n);
    }
};

int main(){
    string s = "axxzxy", s1 = "axxxy", s3 = "xyxxzx";   // ans are 2 2 3
    Solution obj;
    int ans = obj.LongestRepeatingSubsequence(s);       // ans 2.

    return 0;
}