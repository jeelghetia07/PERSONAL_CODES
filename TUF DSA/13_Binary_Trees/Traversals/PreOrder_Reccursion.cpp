#include<iostream>
#include <vector>
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

class PreOrder{
public:
    void Pre(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return ;
        }
        ans.push_back(root->val);
        Pre(root->left, ans);
        Pre(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        Pre(root,ans);
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

    PreOrder p;
    vector<int> ans = p.preorderTraversal(root);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}