#include<bits/stdc++.h>
using namespace std;

/*      LC = 140
    Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

    Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Solution {
public:
    void solve(string s, vector<string>& ans, unordered_set<string>& st, vector<string> &temp){
        // if the complete string s is traversed, then we simply add the temp to the ans.
        if(s.size() == 0){
            string str = "";
            for(auto it : temp){
                str += it + " ";
            }
            str.pop_back();
            ans.push_back(str);
            return;
        }

        for(int i = 0 ; i < s.size() ; i++){
            if(st.count(s.substr(0, i+1))){
                temp.push_back(s.substr(0, i+1));
                solve(s.substr(i+1), ans, st, temp);            // here the sent string starts from index i+1.
                temp.pop_back();        // remove the last string added to temp and continue adding the other chars from i+1 to temp and start searching.
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       vector<string> ans, temp;

       unordered_set<string> st(wordDict.begin(), wordDict.end());

       solve(s, ans, st, temp);

       return ans;
    }
};

int main(){
    /*
        Example 1:

        Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
        Output: ["cats and dog","cat sand dog"]


        Example 2:

        Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
        Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
        Explanation: Note that you are allowed to reuse a dictionary word.

        
        Example 3:

        Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
        Output: []
        

        Constraints:

        1 <= s.length <= 20
        1 <= wordDict.length <= 1000
        1 <= wordDict[i].length <= 10
        s and wordDict[i] consist of only lowercase English letters.
        All the strings of wordDict are unique.
        Input is generated in a way that the length of the answer doesn't exceed 105.
    */

    return 0;
}