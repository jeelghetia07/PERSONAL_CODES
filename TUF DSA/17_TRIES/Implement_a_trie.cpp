#include<bits/stdc++.h>
using namespace std;

/*      LC = 208
    A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

    Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 
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
        return (links[ch - 'a'] != NULL);       // this means, it does exist.
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;         // for the ch character, the "node" is the new trie.
    }
    Node* next(char ch){
        return links[ch- 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    Node* root;

    // initializes your data structure here.
    Trie() {
        root = new Node();
    }
    
    // TC -> O(word.size());
    void insert(string word) {
        Node* node = root;      // dummy varibale node, that initially pointing to root, cause we start from there.
        for(int i = 0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i])){        // does it contain inside that particular node, if not then we put it inside the node and move to the refrence.
                Node* newRefrenceTrie = new Node();
                node->put(word[i], newRefrenceTrie);
            }
            // move to the refrence trie.
            node = node->next(word[i]);
        }

        node->setEnd();
    }

    
    bool search(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->next(word[i]);
        }

        return node->isEnd();
    }
    

    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0 ; i < prefix.size() ; i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->next(prefix[i]);
        }

        return true;
    }
};

int main(){
    /*
        Example 1:

        Input
        ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
        [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
        Output
        [null, null, true, false, true, null, true]

        Explanation
        Trie trie = new Trie();
        trie.insert("apple");
        trie.search("apple");   // return True
        trie.search("app");     // return False
        trie.startsWith("app"); // return True
        trie.insert("app");
        trie.search("app");     // return True
        

        Constraints:

        1 <= word.length, prefix.length <= 2000
        word and prefix consist only of lowercase English letters.
        At most 3 * 104 calls in total will be made to insert, search, and startsWith.
    */

    return 0;
}