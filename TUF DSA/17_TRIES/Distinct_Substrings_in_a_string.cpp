#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given a string s consisting of lowercase English letters, find the total number of distinct non-empty substrings of s.

    Note: A substring is a contiguous sequence of characters within a string. Two substrings are considered distinct if they have different character sequences, regardless of their positions in the string.
*/

struct Node{
    Node *links[26];
    bool flag = false;  
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    Node* next(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }  
    bool isEnd(){
        return flag;
    }    
    void setEnd(){
        flag = true;
    }
};

class Trie{
    Node* root;
    int cnt;
public:
    Trie(){
        root = new Node();
        cnt = 0;
    }
    void insert(string &s){
        int n = s.size();
        
        for(int i = 0 ; i < n ; i++){
            Node* node = root;
            for(int j = i ; j < n ; j++){
                // doesnt exists in the trie.
                if(!node->containsKey(s[j])){
                    node->put(s[j], new Node());
                    cnt++;
                }
                node = node->next(s[j]);
            }
            node->setEnd();
        }
    }
    
    int getCnt(){
        return cnt;
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int n = s.size();
        Trie trie;
        
        trie.insert(s);
        int ans = trie.getCnt();
        
        return ans;
    }
};

int main(){
    /*
        Input: s = "ababa"
        Output: 9
        Explanation: All distinct substrings of "ababa" are: "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa".


        Input: s = "aaa"
        Output: 3
        Explanation: The distinct substrings of "aaa" are: "a", "aa", "aaa".


        Constraints:
        1 ≤ s.size() ≤ 3000
    */

    return 0;
}