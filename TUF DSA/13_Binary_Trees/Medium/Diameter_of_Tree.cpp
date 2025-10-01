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

class Diameter{                     // its basically the longest path from any node to any node...it may or may not pass from the root node.
public: 
    int diameterOfTree(TreeNode* root){
        int dai = 0;
        height(root, dai);
        return dai;
    }
private:
    int height(TreeNode* root, int& d){
        if(root == NULL) return 0;

        int lhs = height(root->left, d);
        int rhs = height(root->right, d);

        d= max(d, lhs + rhs);

        return 1 + max(lhs,rhs);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Diameter d1;
    int ans = d1.diameterOfTree(root);
    cout << "The diameter of the tree is : " << ans << endl;
    return 0;
}