#include<bits/stdc++.h>
using namespace std;

/*      LC = 1781
    The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

    For example, the beauty of "abaacc" is 3 - 1 = 2.
    Given a string s, return the sum of beauty of all of its substrings.
*/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for(int i = 0 ; i < n ; i++){
            unordered_map<char, int> freq;
            for(int j = i ; j < n ; j++){
                freq[s[j]]++;

                int maxi = INT_MIN, mini = INT_MAX;

                for(auto it : freq){
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "aabcb"
        Output: 5
        Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.


        
        Example 2:

        Input: s = "aabcbaa"
        Output: 17
    */

    return 0;
}