#include<bits/stdc++.h>
using namespace std;

/*      LC = 8
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

    The algorithm for myAtoi(string s) is as follows:

    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
    Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
    Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
    Return the integer as the final result.
*/

using ll = long long;
class Solution {
public:
    const int min_value = INT_MIN;
    const int max_value = INT_MAX;
    int func(const string& s, int i, ll num, int sign){
        if(i >= s.size() || !isdigit(s[i])) return (int)(sign * num);

        num = num * 10 + (s[i]-'0');

        if(sign * num <= min_value) return INT_MIN;
        if(sign * num >= max_value) return INT_MAX;

        return func(s, i+1, num, sign);
    }
    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        int sign = 1;

        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return func(s, i, 0, sign);
    }
};

int main(){
    string s = "1337c0d3";
    Solution obj;
    cout << obj.myAtoi(s);      // 1337

    return 0;
}