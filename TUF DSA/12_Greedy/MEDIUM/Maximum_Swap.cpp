#include<bits/stdc++.h>
using namespace std;

/*      LC = 670
    You are given an integer num. You can swap two digits at most once to get the maximum valued number.
    Return the maximum valued number you can get.
*/

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();

        vector<int> suffix(n);
        suffix[n-1] = n-1;

        // build suffix max index (RIGHTMOST max)
        for(int i = n-2; i >= 0; i--) {
            if(s[i] > s[suffix[i+1]]) {
                suffix[i] = i;
            } else {
                suffix[i] = suffix[i+1];
            }
        }

        // find first place to swap
        for(int i = 0; i < n; i++) {
            if(s[i] < s[suffix[i]]) {
                swap(s[i], s[suffix[i]]);
                break;
            }
        }

        return stoi(s);
    }
};

int main(){
    /*
        Example 1:
            Input: num = 2736
            Output: 7236
            Explanation: Swap the number 2 and the number 7.


        Example 2:
            Input: num = 9973
            Output: 9973
            Explanation: No swap.

            input : num = 98368         // nice test case.
            output : num = 98863;
    */

    return 0;
}