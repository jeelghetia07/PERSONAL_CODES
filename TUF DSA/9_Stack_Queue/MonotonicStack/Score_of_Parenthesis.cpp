#include<bits/stdc++.h>
using namespace std;

/*      LC = 856
    Given a balanced parentheses string s, return the score of the string.

    The score of a balanced parentheses string is based on the following rule:

    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        if(n == 2) return 1;
        stack<int> st;
        st.push(0);

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') st.push(0);
            else{
                int inside = st.top();
                st.pop();
                
                int score;

                // this means that just before ')' is definitely a '('.
                if(inside == 0){
                    score = 1;
                }
                else{
                    score = 2 * inside;
                }

                st.top() += score;
            }
        }

        return st.top();
    }
};

int main(){
    /*
        Example 1:

        Input: s = "()"
        Output: 1


        Example 2:

        Input: s = "(())"
        Output: 2


        Example 3:

        Input: s = "()()"
        Output: 2

        Constraints:

        2 <= s.length <= 50
        s consists of only '(' and ')'.
        s is a balanced parentheses string.
    */

    return 0;
}