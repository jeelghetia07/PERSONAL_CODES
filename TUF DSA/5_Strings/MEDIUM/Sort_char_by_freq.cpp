#include<bits/stdc++.h>
using namespace std;

/*      LC = 451
    Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
    Return the sorted string. If there are multiple answers, return any of them.
*/

class Solution {
public:
    string frequencySort(string s){     // TC = O(n + klogk)...the klogk is for pushing into the heap.
        int n = s.size();
        unordered_map<char, int> mpp;
        priority_queue<pair<int, char>> pq;
        for(int i = 0 ; i < n ; i++){
            mpp[s[i]]++;
        }

        for(auto it : mpp){
            pq.push({it.second, it.first});
        }

        string res = "";

        while(!pq.empty()){
            auto p = pq.top();
            int freq = p.first;
            char ch = p.second;
            pq.pop();

            res += string(freq, ch);
        }

        return res;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "tree"
        Output: "eert"
        Explanation: 'e' appears twice while 'r' and 't' both appear once.
        So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


        Example 2:

        Input: s = "cccaaa"
        Output: "aaaccc"
        Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
        Note that "cacaca" is incorrect, as the same characters must be together.

        
        Example 3:

        Input: s = "Aabb"
        Output: "bbAa"
        Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
        Note that 'A' and 'a' are treated as two different characters.
    */

    return 0;
}