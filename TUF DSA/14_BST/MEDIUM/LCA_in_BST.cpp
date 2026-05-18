#include<bits/stdc++.h>
using namespace std;

/*      LC = 235
    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    int curr = root->val;

    // if both are on the left side, then move left.
    if(curr > p->val && curr > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    // same as above.
    if(curr < p->val && curr < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }

    // if they split in between, that means it will definitely be the lowest common ansestor of the tree.
    return root;
}

int main(){


    return 0;
}