#include<bits/stdc++.h>
using namespace std;

/*      LC = 1373
    Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
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


class NodeValue{
public:
    int sum, maxLeft, minRight;
    bool isBST;
    NodeValue(int sum, bool isBST, int maxLeft, int minRight){
        this->sum = sum;
        this->isBST = isBST;
        this->maxLeft = maxLeft;
        this->minRight = minRight;
    }
};

class Solution {
public:
    int ans = 0;
    NodeValue helper(TreeNode* root){
        if(!root) return NodeValue(0, true, INT_MIN, INT_MAX);

        auto left = helper(root->left);
        auto right = helper(root->right);

        if(left.maxLeft < root->val && root->val < right.minRight && (left.isBST && right.isBST)){
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return NodeValue(currSum, true, max(root->val, right.maxLeft), min(root->val, left.minRight));
        }

        return NodeValue(0, false, INT_MAX, INT_MIN);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);

        return ans;
    }
};

int main(){
    /*
        Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
        Output: 20
        Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
    */

    return 0;
}