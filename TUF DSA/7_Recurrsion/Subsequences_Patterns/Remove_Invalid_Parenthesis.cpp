#include<bits/stdc++.h>
using namespace std;

/*      LC = 301
    Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

    Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
*/

class Solution {
public:
    int findWaste(string &s) {
        int open = 0;
        int waste = 0;

        for (char ch : s) {
            if (ch == '(') {
                open++;
            }
            else if (ch == ')') {
                if (open > 0)
                    open--;
                else
                    waste++;
            }
        }
        return waste + open;
    }

    bool isValid(string &s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void func(int ind, string &temp, set<string>& st, string &s, int sz, int n, int removed) {

        // Already removed too many chars
        if (removed < 0)
            return;

        // Even taking the rest of the remaining string can't reach sz...then return before.
        if (temp.size() + (n - ind) < sz)
            return;

        // Base case.
        if (ind == n) {
            if (temp.size() == sz && isValid(temp)) {
                st.insert(temp);
            }
            return;
        }

        // Take current character
        temp.push_back(s[ind]);
        func(ind + 1, temp, st, s, sz, n, removed);
        temp.pop_back();

        // Don't remove letters
        if (s[ind] >= 'a' && s[ind] <= 'z')
            return;

        // Remove current parenthesis
        func(ind + 1, temp, st, s, sz, n, removed - 1);
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();

        int waste = findWaste(s);

        set<string> st;
        string temp = "";

        func(0, temp, st, s, n - waste, n, waste);

        return vector<string>(st.begin(), st.end());

        // O(2^p*n + R*n*logR) = O(2^p * n)....p = no of parenthesis.
    }
};

int main(){
    /*
        Example 1:

        Input: s = "()())()"
        Output: ["(())()","()()()"]


        Example 2:

        Input: s = "(a)())()"
        Output: ["(a())()","(a)()()"]


        Example 3:

        Input: s = ")("
        Output: [""]
        

        Constraints:

        1 <= s.length <= 25
        s consists of lowercase English letters and parentheses '(' and ')'.
        There will be at most 20 parentheses in s.
    */

    return 0;
}