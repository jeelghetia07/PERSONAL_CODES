#include<bits/stdc++.h>
using namespace std;

/*      LC = 647
    Given a string s, return the number of palindromic substrings in it.

    A string is a palindrome when it reads the same backward as forward.
    
    A substring is a contiguous sequence of characters within the string.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;

        for(int center = 0 ; center < n ; center++){

            int left = center, right = center;      // finding odd length palindromes becoz the odd palin start from one center ele.
            while(left >= 0 && right < n && s[left] == s[right]){
                cnt++;
                left--, right++;
            }


            left = center, right = center + 1;      // finding even length palindromes becoz the even palin start from two ele, one is center and other is center+1, and then keep expanding in all directions
            while(left >= 0 && right < n && s[left] == s[right]){
                cnt++;
                left--, right++;
            }
        }
        return cnt;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "abc"
        Output: 3
        Explanation: Three palindromic strings: "a", "b", "c".

        
        Example 2:

        Input: s = "aaa"
        Output: 6
        Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
    */

    return 0;
}