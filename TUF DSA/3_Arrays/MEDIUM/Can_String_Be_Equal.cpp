#include<bits/stdc++.h>
using namespace std;

/*      LC = 2840
    You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

    You can apply the following operation on any of the two strings any number of times:

    Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
    Return true if you can make the strings s1 and s2 equal, and false otherwise.
*/


class Solution {
public:
    /*
        very good logical thinking,
        its said that even diff pairs can swap that means.....it indexes still remain as it is, if even een swap they remain same and if odd odd swap then also they remain at odd odd....so the final string should also have the same index char but just at diff pos.

        so insted of seeing which ele are there, we simply just store the ele which occur at even or odd pos in     both the strings so then we match it at last.
    */

    bool checkStrings(string s1, string s2) {
        int n1 = s1.size();

        vector<int> s1_even(26,0), s1_odd(26,0), s2_even(26,0), s2_odd(26,0);       

        for(int i = 0 ; i < n1 ; i++){
            if(i % 2 == 0){
                s1_even[s1[i]-'a']++;
                s2_even[s2[i]-'a']++;
            }
            else{
                s1_odd[s1[i]-'a']++;
                s2_odd[s2[i]-'a']++;
            }
        }

        return(s1_even == s2_even) && (s1_odd == s2_odd);
    }
};


int main(){
    /*
        Example 1:

        Input: s1 = "abcdba", s2 = "cabdab"
        Output: true
        Explanation: We can apply the following operations on s1:
        - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
        - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
        - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.



        Example 2:

        Input: s1 = "abe", s2 = "bea"
        Output: false
        Explanation: It is not possible to make the two strings equal.
        

        Constraints:

        n == s1.length == s2.length
        1 <= n <= 105
        s1 and s2 consist only of lowercase English letters.
    */

    return 0;
}