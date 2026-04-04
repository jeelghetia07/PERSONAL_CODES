#include<bits/stdc++.h>
using namespace std;

/*      LC = 226
    Given the root of a binary tree, invert the tree, and return its root.
*/

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        return root;
    }
};

int main(){
    

    return 0;
}