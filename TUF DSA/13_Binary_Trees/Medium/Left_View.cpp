#include<bits/stdc++.h>
using namespace std;

/*      GFG
    
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
    void inversePreOrder(TreeNode* root, int level, vector<int>& ans){
        if(root == NULL) return ;
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        inversePreOrder(root->left, level+1, ans);
        inversePreOrder(root->right, level+1, ans);
    }
    vector<int> leftView(TreeNode *root) {
        vector<int> ans;
        int level = 0;
        inversePreOrder(root, level,ans);
        return ans;
    }
};

int main(){


    return 0;
}