#include<bits/stdc++.h>
using namespace std;

/*      LC = 
    You are given two binary strings s1 and s2 of the same length n.

You can perform the following operations on s1 any number of times, in any order:

Choose an index i such that s1[i] == '0', and change it to '1'.
Choose an index i such that 0 <= i < n - 1, and both s1[i] and s1[i + 1] are '1'. Change both characters to '0'.
Return the minimum number of operations required to make s1 equal to s2. If it is impossible, return -1.
*/

class Solution {
public:
    int minOperations(string s, string t) {
        int n = s.size();
        if(s == t) return 0;

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == t[i]) continue;
            if(s[i] == '0'){
                s[i] = '1';
                ans++;
                continue;
            }

            // s[i] == '1', t[i] == '0'

            // if there is a '1' at right, pair with it and change the states.
            if(i+1 < n && s[i+1] == '1'){           //  1100 ---> 0000
                s[i] = t[i];
                s[i+1] = '0';       // set this to 0.
                ans++;
                continue;
            }

            // if there is '1' at left, pair it and then form.
            if(i-1 >= 0 && s[i-1] == '1'){
                s[i] = t[i];
                ans++;
                ans += ('1' == t[i-1]);
                s[i-1] = t[i-1];
                continue;
            }

            // if '1' is not present at right, we create it.
            if(i+1 < n && s[i+1] == '0'){
                s[i] = t[i];
                ans += 2;
                ans += ('1' == t[i+1]);
                s[i+1] = t[i+1];
                continue;
            }

            // if '1' is not present at left, we create it.
            if(i-1 >= 0 && s[i-1] == '0'){
                s[i] = t[i];
                ans += 2;
                ans += ('1' == t[i-1]);         // try doing 01 ---> 10 / 00, and see this statement if not needed, cause it the previous target was 1, it would already have been solved cause we are traversing left to right.
                s[i-1] = t[i-1];        // similarly this is also not needed.
                continue;
            }
        }

        if(s != t) return -1;
        return ans;
    }
};

int main(){
    /*
        Example 1:

        Input: s1 = "11", s2 = "00"
        Output: 1
        Explanation:
            Change indices 0 and 1 from '1' to '0' in one operation, so "11" becomes "00". Thus, the answer is 1.


        Example 2:

        Input: s1 = "01", s2 = "10"
        Output: 3
        Explanation:
            Change index 0 from '0' to '1', so "01" becomes "11".
            Change indices 0 and 1 from '1' to '0', so "11" becomes "00".
            Change index 0 from '0' to '1', so "00" becomes "10".
            Thus, the answer is 3.


        Example 3:

        Input: s1 = "1", s2 = "0"
        Output: -1
        Explanation:

            The first operation cannot change '1' to '0', and the second operation requires two adjacent characters. Therefore, it is impossible.

        Constraints:

        1 <= n == s1.length == s2.length <= 105
        s1 and s2 consist only of '0' and '1'.
    */

    return 0;
}