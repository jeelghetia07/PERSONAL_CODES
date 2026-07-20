#include<bits/stdc++.h>
using namespace std;

/*      LC = 844
    Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

    Note that after backspacing an empty text, the text will continue empty.
*/

class Solution {
    int get_next_valid_char_ind(string& str, int end){
        int backspace_cnt = 0;

        while(end >= 0){
            if(str[end] == '#') backspace_cnt++;
            else if(backspace_cnt > 0) backspace_cnt--;
            else break;
            end--;
        }
        return end;
    }
public:
    bool backspaceCompare(string s, string t) {
        int ps = s.size()-1;
        int pt = t.size()-1;

        while(ps >= 0 || pt >= 0){
            ps = get_next_valid_char_ind(s, ps);
            pt = get_next_valid_char_ind(t, pt);

            if(ps < 0 && pt < 0) return true;
            if(ps < 0 || pt < 0) return false;
            else if(s[ps] != t[pt]) return false;

            ps--, pt--;
        }

        return true;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "ab#c", t = "ad#c"
        Output: true
        Explanation: Both s and t become "ac".

        Example 2:

        Input: s = "ab##", t = "c#d#"
        Output: true
        Explanation: Both s and t become "".
        
        Example 3:

        Input: s = "a#c", t = "b"
        Output: false
        Explanation: s becomes "c" while t becomes "b".
    */

    return 0;
}