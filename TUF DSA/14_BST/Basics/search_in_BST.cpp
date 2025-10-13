#include<iostream>
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

class SEARCH_BST{
public:
    TreeNode* searchinBST(TreeNode* root, int v){
        if(root == NULL) return NULL;
        while(root != NULL && root->val != v){
            root = (v > root->val) ? root->right : root->left;
        }
        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    root->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(13);
    root->right->right->left = new TreeNode(12);
    root->right->right->right = new TreeNode(15);

    SEARCH_BST sb;
    TreeNode* ans = sb.searchinBST(root,12);

    if (ans != NULL)
        cout << "The node found: " << ans->val << endl;
    else
        cout << "Value not found in BST" << endl;
    return 0;
}