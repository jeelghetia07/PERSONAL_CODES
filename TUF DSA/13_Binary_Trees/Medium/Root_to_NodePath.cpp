#include<iostream>
#include<vector>
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

class ROOT2NODEPATH{
public:
    bool checkPath(TreeNode* root, vector<int>& ans, int B){
        if(!root) return false;
        ans.push_back(root->val);
        if(root->val == B){
            return true;
        }
        if(checkPath(root->left, ans, B) || checkPath(root->right, ans, B)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    vector<int> roottonodepath(TreeNode* root, int B){
        vector<int> ans;
        if(root == NULL) return ans;
        checkPath(root,ans,B);
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

    int b = 7;
    ROOT2NODEPATH r;
    vector<int> ans = r.roottonodepath(root,b);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}