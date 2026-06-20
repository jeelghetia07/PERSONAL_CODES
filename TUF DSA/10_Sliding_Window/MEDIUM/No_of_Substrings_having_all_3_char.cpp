#include<bits/stdc++.h>
using namespace std;

/*      LC = 1358
    Given a string s consisting only of characters a, b and c.

    Return the number of substrings containing at least one occurrence of all these characters a, b and c
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int ans = 0;
        vector<int> arr(3, -1);

        for(int i = 0 ; i < n ; i++){
            arr[s[i]-'a'] = i;
            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1){
                ans += 1 + min({arr[0], arr[1], arr[2]});       // this means the shortest valid substring from reverse and then add the remaining length cause each char on the left can be a valid substring.
            }
        }
        return ans;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "abcabc"
        Output: 10
        Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

        Example 2:

        Input: s = "aaacb"
        Output: 3
        Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

        Example 3:

        Input: s = "abc"
        Output: 1
    */

    return 0;
}