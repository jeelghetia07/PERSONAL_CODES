#include<iostream>
#include<ctype.h>
#include <climits>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode(int d){
        data = d;
    }
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class MAXPATHSUM{
public:
    int maximumPathSum(TreeNode* root){
        int maxi = INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }
    int maxSum(TreeNode* root, int& maxi){
        if(root == NULL){
            return 0;
        }

        int lhs = max(0, maxSum(root->left, maxi));
        int rhs = max(0, maxSum(root->right, maxi));

        maxi = max(maxi, root->data + lhs + rhs);
        return (root->data + max(lhs,rhs));
    }
};

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    MAXPATHSUM ms;
    int ans = ms.maximumPathSum(root);
    cout << "The max sum is : " << ans << endl;
    return 0;
}
