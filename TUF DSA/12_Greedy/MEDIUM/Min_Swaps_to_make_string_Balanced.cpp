#include<bits/stdc++.h>
using namespace std;

/*      LC = 1963
    You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

    A string is called balanced if and only if:

    It is the empty string, or
    It can be written as AB, where both A and B are balanced strings, or
    It can be written as [C], where C is a balanced string.
    You may swap the brackets at any two indices any number of times.

    Return the minimum number of swaps to make s balanced.
*/

class Solution {
public:
                        // OPTIMAL SOL
    int minSwaps(string s) {
        int balance = 0;
        int invalid = 0;

        for(char ch : s) {
            if(ch == '[') {
                balance++;
            }
            else {
                balance--;

                if(balance < 0) {
                    invalid++;              // this represents the ']' braces.
                    balance = 0;
                }
            }
        }

        return (invalid + 1) / 2;
    }


                        // MY THINKING.

            /* The cycle repeats for length of invalid sequ "]][["  etc:- 
                            for len = 2 --> 1 swap req 
                            for len = 4 --> 1 swap req 
                            for len = 6 --> 2 swap req 
                            for len = 8 --> 2 swap req 
                            for len = 10 --> 3 swap req 
                            for len = 12 --> 3 swap req 

                            means, we can find the stack size and return ceil value of size / 4.
            */

    // int minSwaps(string s) {
    //     stack<char> st;

    //     // This gives the invalid seq of braces, like ]][[ format,
    //     for(char ch : s){
    //         if(ch == '[') st.push(ch);
    //         else{
    //             if(st.empty() || (st.top() == ']')) st.push(ch);
    //             if(st.top() == '[') st.pop();
    //         }
    //     }

    //     int n = st.size();

    //     if(n == 0) return 0;

    //     return ceil((double)n / 4);
    // }
};

int main(){
    /*
        Example 1:

        Input: s = "][]["
        Output: 1
        Explanation: You can make the string balanced by swapping index 0 with index 3.
        The resulting string is "[[]]".


        Example 2:

        Input: s = "]]][[["
        Output: 2
        Explanation: You can do the following to make the string balanced:
        - Swap index 0 with index 4. s = "[]][][".
        - Swap index 1 with index 5. s = "[[][]]".
        The resulting string is "[[][]]".

        
        Example 3:

        Input: s = "[]"
        Output: 0
        Explanation: The string is already balanced.
        

        Constraints:

        n == s.length
        2 <= n <= 106
        n is even.
        s[i] is either '[' or ']'.
        The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
    */

    return 0;
}