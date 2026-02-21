#include<iostream>
#include <vector>
#include<queue>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode(int v){
        val = v;
    }
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class InOrder{
public:
    void In(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        In(root->left, ans);
        ans.push_back(root->val);
        In(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ans;
        In(root,ans);
        return ans;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    InOrder in;
    vector<int> ans = in.inorderTraversal(root);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}