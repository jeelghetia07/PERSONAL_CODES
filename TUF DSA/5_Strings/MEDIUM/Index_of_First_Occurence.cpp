#include<bits/stdc++.h>
using namespace std;

/*      LC = 28
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.   
*/

class Solution {
public:
    int func(int i, int j, int n1, int n2, string& s1, string& s2){
        if(j == n2) return i-j;
        if(i == n1) return -1;
        
        if(s1[i] == s2[j]){
            return func(i+1, j+1, n1, n2, s1, s2);
        }
        else{
            if(j > 0){
                return func(i-j+1, 0, n1, n2, s1, s2);      // this i-j+1 is most crucial part in this....to know why we did this....try the example "aaaab" "aaab".
            }
            else
                return func(i+1, 0, n1, n2, s1, s2);
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();           // this has a SC of O(1). and the recursion has a stack space of O(m).
        for (int i = 0; i <= n - m; i++) {              // TC = O(n*m);
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {         
                j++;
            }
            if (j == m) return i;
        }

        return -1;

        // int startIndex = -1;
        // int n1 = haystack.size(), n2 = needle.size();

        // if(n1 < n2) return -1;

        // return func(0, 0, n1, n2, haystack, needle);
    }
};

int main(){
    /*
        Example 1:

        Input: haystack = "sadbutsad", needle = "sad"
        Output: 0
        Explanation: "sad" occurs at index 0 and 6.
        The first occurrence is at index 0, so we return 0.


        Example 2:

        Input: haystack = "leetcode", needle = "leeto"
        Output: -1
        Explanation: "leeto" did not occur in "leetcode", so we return -1.
    */

    return 0;
}