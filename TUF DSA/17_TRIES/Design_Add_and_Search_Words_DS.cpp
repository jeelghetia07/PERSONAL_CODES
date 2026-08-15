#include<bits/stdc++.h>
using namespace std;

/*      LC = 211
    Design a data structure that supports adding new words and finding if a string matches any previously added string.

    Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
*/

struct Node{
    Node *links[26];
    bool flag;

    Node(){
        for(int i = 0 ; i < 26 ; i++){
            links[i] = NULL;
        }
        flag = false;
    }

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* next(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root = new Node();
    }

    // bool helper(Node* root, int ind, string& word){
    //     // if(ind == word.size()) return root->isEnd();

    //     Node* node = root;

    //     for(int i = ind ; i < word.size() ; i++){
    //         if(word[i] != '.'){
    //             if(!node->containsKey(word[i])){
    //                 return false;
    //             }
    //             node = node->next(word[i]);
    //         }
    //         else{
    //             for(int j = 0 ; j < 26 ; j++){
    //                 if(node->containsKey(j + 'a')){
    //                     if(helper(node->next(j + 'a'), i+1, word)) return true;
    //                 }
    //             }
    //             return false;
    //         }
    //     }
    //     return node->isEnd();
    // }

    bool helper(Node *node, int ind, string &word){
        if(ind == word.size()){
            return node->isEnd();
        }

        char ch = word[ind];
        
        if(ch != '.'){
            if(!node->containsKey(ch)) return false;
            return helper(node->next(ch), ind+1, word);
        }
        else{
            for(int i = 0 ; i < 26 ; i++){
                char c = 'a' + i;
                if(node->containsKey(c)){
                    if(helper(node->next(c), ind+1, word)) return true;
                }
            }
            return false;
        }

        return false;
    }
    
    void addWord(string word) {
        Node *node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->next(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return helper(root, 0, word);
    }
};

int main(){
    /*
        Example:

        Input
        ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
        [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
        Output
        [null,null,null,null,false,true,true,true]

        Explanation
        WordDictionary wordDictionary = new WordDictionary();
        wordDictionary.addWord("bad");
        wordDictionary.addWord("dad");
        wordDictionary.addWord("mad");
        wordDictionary.search("pad"); // return False
        wordDictionary.search("bad"); // return True
        wordDictionary.search(".ad"); // return True
        wordDictionary.search("b.."); // return True
        

        Constraints:

        1 <= word.length <= 25
        word in addWord consists of lowercase English letters.
        word in search consist of '.' or lowercase English letters.
        There will be at most 2 dots in word for search queries.
        At most 104 calls will be made to addWord and search.
    */

    return 0;
}