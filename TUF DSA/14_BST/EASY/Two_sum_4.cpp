#include<bits/stdc++.h>
using namespace std;

/*      LC = 653
    Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/

class TreeNode{
public:
    int val;
    TreeNode(int v){
        val = v;
    }
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Solution {
public:
    bool solve(TreeNode* root, int k, unordered_set<int>& st){
        if(root == NULL) return false;
        if(solve(root->left, k , st)) return true;

        int rem = k - root->val;
        if(st.find(rem) != st.end()) return true;
        
        st.insert(root->val);

        return solve(root->right, k , st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return solve(root, k, st);
    }
};

int main(){


    return 0;
}