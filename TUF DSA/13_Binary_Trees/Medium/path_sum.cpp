#include<bits/stdc++.h>
using namespace std;

/*      LC = 112
    Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

    A leaf is a node with no children.
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
    bool find(TreeNode* node, int tar){
        if(node == NULL) return false;
        // check if the last node where the tar == ndde->val then it should bea leaf ofcourse.
        if(node->left == NULL && node->right == NULL && tar == node->val) return true;
    
        return find(node->left, tar - node->val) || find(node->right, tar - node->val);     // check both sides and try to find the sum if possible.
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return find(root, targetSum);
    }
};

int main(){
    /*
        Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
        Output: true
        Explanation: The root-to-leaf path with the target sum is shown.
    */

    return 0;
}