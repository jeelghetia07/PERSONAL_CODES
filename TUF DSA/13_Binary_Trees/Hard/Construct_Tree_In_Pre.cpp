#include<bits/stdc++.h>
using namespace std;

/*      LC = 105
    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd,  map<int, int>& inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;        // this is to seperate the ele in the INORDER....like     [left, root, right].

        root->left = buildTree(preorder, preStart+1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        map<int, int> inMap;

        for(int i = 0 ; i < n ; i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, n-1, inorder, 0, m-1, inMap);

        return root;
    }
};

int main(){
    

    return 0;
}