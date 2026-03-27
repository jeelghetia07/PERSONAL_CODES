#include<bits/stdc++.h>
using namespace std;

/*      LC = 205
    Given two strings s and t, determine if they are isomorphic.

    Two strings s and t are isomorphic if the characters in s can be replaced to get t.

    All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> mpp1, mpp2;       // both the chars should map consistently.

        for(int i = 0 ; i < n ; i++){
            char c1 = s[i];
            char c2 = t[i];

            if(mpp1.find(c1) != mpp1.end()){        // this checks the mapping of c1 -> c2 should be maintained
                if(mpp1[c1] != c2) return false;
            }
            else{
                mpp1[c1] = c2;
            }


            if(mpp2.find(c2) != mpp2.end()){        // this checks the mapping of c2 -> c1 should be maintained
                if(mpp2[c2] != c1) return false;
            }
            else{
                mpp2[c2] = c1;
            }
        }

        return true;

    }
};

int main(){
        // we cannot simply create 2 maps and insert the freqs and compare the sizes because...try the examples...."bbbaaaba" and "aaabbbba" ..... here the first 6 indexes are mapped like b->a and a->b but in the last 2 indeces we can see b->b and a->a....this is false.


    /*
        Example 1:

        Input: s = "egg", t = "add"
        Output: true
        Explanation:
            The strings s and t can be made identical by:
            Mapping 'e' to 'a'.
            Mapping 'g' to 'd'.


        Example 2:

        Input: s = "f11", t = "b23"
        Output: false
        Explanation:
            The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

        Example 3:

        Input: s = "paper", t = "title"
        Output: true

    */

    return 0;
}