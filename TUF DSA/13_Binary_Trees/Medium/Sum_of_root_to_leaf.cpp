#include<bits/stdc++.h>
using namespace std;

/*      LC = 129
    You are given the root of a binary tree containing digits from 0 to 9 only.

    Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

    A leaf node is a node with no children.
*/

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void func(TreeNode* root, string &temp, vector<string> &ans){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            temp.push_back(root->val+'0');
            ans.push_back(temp);
            temp.pop_back();

            return ;
        }

        temp.push_back(root->val+'0');
        func(root->left, temp, ans);
        func(root->right, temp, ans);
        temp.pop_back();

        return ;
    }
    int sumNumbers(TreeNode* root) {
        string temp = "";
        vector<string> ans;

        int res = 0;

        func(root, temp, ans);

        for(int i = 0 ; i < ans.size() ; i++){
            res += stoi(ans[i]);
        }

        return res;
    }
};

int main(){
    /*
        
    */

    return 0;
}