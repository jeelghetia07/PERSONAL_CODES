#include<bits/stdc++.h>
using namespace std;

/*      LC = 617
    You are given two binary trees root1 and root2.

    Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

    Return the merged tree.

    Note: The merging process must start from the root nodes of both trees.
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

TreeNode* buildTree(TreeNode* r1, TreeNode* r2){
    if(r1 == NULL && r2 == NULL) return 0;
    if(r1 == NULL) return r2;       // if one is NULL, it might be that there is a huge tree on the other tree...so simply return the remaining full tree as the return type of the func is TreeNode.
    if(r2 == NULL) return r1;

    TreeNode* newNode = new TreeNode(r1->val + r2->val);        // simple r1->val + r2->val doesnt create the nodes value, we first have to create a node using this format, and then asign its values.

    newNode->left = buildTree(r1->left, r2->left);
    newNode->right = buildTree(r1->right, r2->right);

    return newNode;
}
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    return buildTree(root1, root2);
}

int main(){
    /*
        Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
        Output: [3,4,5,5,4,null,7]
        Example 2:

        Input: root1 = [1], root2 = [1,2]
        Output: [2,2]
    */

    return 0;
}