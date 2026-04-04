#include<bits/stdc++.h>
using namespace std;

/*      LC = 112
    Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

    A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
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
    void find(TreeNode* node, int tar, vector<int>& temp, vector<vector<int>>& ans){
            if(node == NULL){
                return;
            }
            
            if(node->left == NULL && node->right == NULL && tar == node->val){
                temp.push_back(node->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }

            temp.push_back(node->val);
            find(node->left, tar - node->val, temp, ans);
            find(node->right, tar - node->val, temp, ans);
            temp.pop_back();
            return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;

        find(root, targetSum, temp, ans);

        return ans;
    }
};

int main(){


    return 0;
}