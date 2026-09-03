#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
    Note: The input strings may contain leading zeros but the output string should not have any leading zeros.
*/

class Solution {
  public:
    string addBinary(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        
        int carry = 0;
        int i = n-1, j = m-1;
        
        string str = "";
        
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0)
                sum += s[i--] - '0';

            if(j >= 0)
                sum += t[j--] - '0';

            str += (sum % 2) + '0';
            carry = sum / 2;
        }
        
        reverse(str.begin(), str.end());
        
        i = 0;
        while(i < str.size()-1 && str[i] == '0'){
            i++;
        }
        
        return str.substr(i);
    }
};

int main(){
    /*
        Input: s1 = "1101", s2 = "111"
        Output: 10100
        Explanation:
        1101
        + 111
        10100


        Input: s1 = "00100", s2 = "010"
        Output: 110
        Explanation: 
        100
        + 10
        110

        
        Constraints:
        1 ≤s1.size(), s2.size()≤ 106
    */

    return 0;
}