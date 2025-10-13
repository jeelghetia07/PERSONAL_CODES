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

class FLOOR_BST{
public:
    int findfloor(TreeNode* root, int key){
        if(root == NULL) return -1;
        int floor = -1;

        while(root){
            if(root->val == key){
                floor = root->val;
                return floor;
            }
            if(key < root->val){
                root = root->left;
            }
            else{
                floor = root->val;
                root = root->right;
            }
        }
        return floor;
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);

    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);

    FLOOR_BST fb;
    int ans = fb.findfloor(root, 7);

    cout << "The ans is  : " << ans; 
    return 0;
}