#include<bits/stdc++.h>
using namespace std;

/*      LC = 106
    Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        int n = inorder.size();
        int m = postorder.size();

        map<int, int> inMap;
        for(int i = 0 ; i < inorder.size() ; i++){
            inMap[inorder[i]] = i;
        }

        return buildTree(inorder, 0, n-1, postorder, 0, m-1, inMap);
    }
    TreeNode* buildTree(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& inMap){
        if(ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = inMap[postorder[pe]];
        int numsLeft = inRoot - is;

        root->left = buildTree(inorder, is, inRoot-1, postorder, ps, ps + numsLeft-1, inMap);
        root->right = buildTree(inorder, inRoot+1, ie, postorder, ps + numsLeft, pe-1, inMap);

        return root;
    }
};

int main(){
    vector<int> inorder = {40,20,50,10,60,30};
    vector<int> postorder = {40,50,20,60,30,10};

    Solution obj;
    TreeNode* root = obj.buildTree(inorder, postorder);

    return 0;
}