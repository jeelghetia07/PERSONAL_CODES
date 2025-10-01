#include<iostream>
using namespace std;

class TreeNode{
    int data;
public:
    TreeNode(int d){
        data = d;
    }
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Balanced{
public:
    int maxHeight(TreeNode* root){
        if(root == NULL) return 0;

        int LHS = maxHeight(root->left);
        int RHS = maxHeight(root->right);
        if(LHS == -1 && RHS == -1) return -1;
        if(abs(LHS-RHS) > 1) return -1;

        return 1 + max(LHS, RHS);
    }
    bool CheckIfBalanced(TreeNode* root){
        if(maxHeight(root) == -1) return false;
        else{
            return true;
        }      
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    // root->left->right->left = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Balanced b;
    bool ans = b.CheckIfBalanced(root);
    if(ans){
        cout << "Balanaced.";
    }
    else{
        cout << "Not balanaced.";
    }
    return 0;
}