#include<bits/stdc++.h>
using namespace std;

/*      LC = 988
    You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

    Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

    As a reminder, any shorter prefix of a string is lexicographically smaller.

    For example, "ab" is lexicographically smaller than "aba".
    A leaf of a node is a node that has no children.
*/

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void dfs(TreeNode* root, string path, string &ans){
        if(root == NULL) return ;

        // append current node's char to the path.
        path += char('a' + root->val);

        // if its a leaf node, compare and update the smallest.
        if(root->left == nullptr && root->right == nullptr){
            reverse(path.begin(), path.end());
            if(ans.empty() || path < ans){
                ans = path;
            }
            reverse(path.begin(), path.end());
        }

        // Recursively traverse left and right subtrees.
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);

        return ;
    }   
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", temp = "";

        dfs(root, temp, ans);

        return ans;
    }
};

int main(){
    /*
        
    */

    return 0;
}