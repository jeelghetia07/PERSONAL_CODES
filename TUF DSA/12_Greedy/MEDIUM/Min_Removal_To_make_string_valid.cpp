#include<bits/stdc++.h>
using namespace std;

/*      LC = 1249
    Given a string s of '(' , ')' and lowercase English characters.

    Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

    Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string temp = "";
        int open = 0;

        // Remove ')'
        for(char ch : s){
            if(ch == '('){
                open++;
                temp += ch;
            }
            else if(ch == ')'){
                if(open > 0){
                    open--;
                    temp += ch;
                }
            }
            else temp += ch;
        }

        string ans = "";

        // remove extra '(' if there.
        for(int i = temp.size()-1 ; i >= 0 ; i--){
            if(temp[i] == '(' && open > 0) open--;
            else ans += temp[i];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "lee(t(c)o)de)"
        Output: "lee(t(c)o)de"
        Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.


        Example 2:

        Input: s = "a)b(c)d"
        Output: "ab(c)d"

        
        Example 3:

        Input: s = "))(("
        Output: ""
        Explanation: An empty string is also valid.
        

        Constraints:

        1 <= s.length <= 105
        s[i] is either '(' , ')', or lowercase English letter.
    */

    return 0;
}