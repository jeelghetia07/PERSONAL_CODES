#include<bits/stdc++.h>
using namespace std;

/*      LC = 1021
    
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int depth = 0;

        for(char ch : s){
            if(ch == '('){
                if(depth > 0) res += ch;
                depth++;
            }
            else if(ch == ')'){
                depth--;
                if(depth > 0) res += ch;
            }
        }

        return res;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "(()())(())"
        Output: "()()()"
        Explanation: 
        The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
        After removing outer parentheses of each part, this is "()()" + "()" = "()()()".


        Example 2:

        Input: s = "(()())(())(()(()))"
        Output: "()()()()(())"
        Explanation: 
        The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
        After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

        
        Example 3:

        Input: s = "()()"
        Output: ""
        Explanation: 
        The input string is "()()", with primitive decomposition "()" + "()".
        After removing outer parentheses of each part, this is "" + "" = "".
    */

    return 0;
}