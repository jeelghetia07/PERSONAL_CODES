#include<bits/stdc++.h>
using namespace std;

/*      LC = 3863
    You are given a string s consisting of lowercase English letters.

    In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.

    Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.
*/

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end()))
            return 0;

        if (n == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // if either the max ele comes at the last, or the min comes at the first, then we can sort the remaining substring in 1 pass.
        if(s[0] == mn || s[n-1] == mx) return 1;

        bool mnPrefix = false, mxSuffix = false;

        for(int i = 0 ; i < n-1 ; i++){
            if(s[i] == mn) mnPrefix = true;
        }

        for(int i = 1 ; i < n ; i++){
            if(s[i] == mx) mxSuffix = true;
        }

        if(!mnPrefix && !mxSuffix) return 3;

        return 2;
        
        return -1;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "dog"
        Output: 1
        Explanation:​​​​​​​

        Sort substring "og" to "go".
        Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.


        Example 2:

        Input: s = "card"
        Output: 2
        Explanation:

        Sort substring "car" to "acr", so s = "acrd".
        Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending order. Thus, the answer is 2.


        Example 3:

        Input: s = "gf"
        Output: -1
        Explanation:

        It is impossible to sort s under the given constraints. Thus, the answer is -1.
        

        Constraints:

        1 <= s.length <= 105
        s consists of only lowercase English letters.
    */

    return 0;
}