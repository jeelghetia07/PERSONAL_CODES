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

class CEIL_BST{
public:
    int findceil(TreeNode* root, int key){
        if(root == NULL) return NULL;
        int ceil = -1;

        while(root){
            if(root->val == key){
                ceil = root->val;
                return ceil;
            }
            if(key > root->val){
                root = root->right;
            }
            else{
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }
};


int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);

    root->right = new TreeNode(13);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    CEIL_BST cb;
    int ans = cb.findceil(root, 8);

    cout << "The ceil is : " << ans << endl;
    return 0;
}