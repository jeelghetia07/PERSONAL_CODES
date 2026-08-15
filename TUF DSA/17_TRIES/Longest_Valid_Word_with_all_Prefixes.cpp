#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one.

    If no such string is found, return an empty string.
*/

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return links[ch - 'a'];
    }
    
    Node* next(char ch){
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie{ 
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->next(word[i]);
        }
        node->setEnd();
    }
    
    bool checkIfPrefixExists(string word){
        Node* node = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            if(node->containsKey(word[i])){
                node = node->next(word[i]);
                if(node->isEnd() == false) return false;
            }
            else
                return false;
        }
        
        return true;
    }
};

class Solution {
  public:    
    string longestValidWord(vector<string>& words) {
        int n = words.size();
        Trie trie;
        
        // This creates the whole Trie first.
        for(auto &it : words){
            trie.insert(it);
        }
        
        string longest = "";
        
        for(auto it : words){
            // if the word is found in the trie, then is it the longest??
            if(trie.checkIfPrefixExists(it)){
                if(it.length() > longest.length()){
                    longest = it;
                }
                else if(it.length() == longest.length() && it < longest){           // if length are equal, then we have to find the lexicographically smallest string.
                    longest = it;
                }
            }
        }
        
        if(longest == "") return "";
        return longest;
    }
};


int main(){


    return 0;
}