#include<bits/stdc++.h>
using namespace std;

/*      LC = 108
    Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
*/

class TreeNode{
public:
    int val;
    TreeNode(int v){
        val = v;
    }
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Solution {
public:
    TreeNode* buildTree(int left, int right, TreeNode* root, vector<int>& arr){
        if(left > right) return NULL;

        int mid = (left + right)/2;
        TreeNode* node = new TreeNode(arr[mid]);

        node->left = buildTree(left, mid-1, node, arr);
        node->right = buildTree(mid+1, right, node, arr);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n-1;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);      // this creates the root of the tree.

        root->left = buildTree(left, mid-1, root, nums);
        root->right = buildTree(mid+1, right, root, nums);

        return root;
    }
};

int main(){


    return 0;
}