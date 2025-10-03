#include<iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode(int v){
        val = v;
    }
    TreeNode* left;
    TreeNode* right;
};

class IDENTICAL{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL){
            return (p==q);
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }
};

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);

    IDENTICAL id;
    bool ans = id.isSameTree(root, root1);
    cout << "its " << ans << " that the trees are identical." << endl;
    return 0;
}