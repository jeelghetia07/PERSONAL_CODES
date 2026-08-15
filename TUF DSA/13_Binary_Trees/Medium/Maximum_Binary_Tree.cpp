#include<bits/stdc++.h>
using namespace std;

/*      LC = 654
    You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

    Create a root node whose value is the maximum value in nums.
    Recursively build the left subtree on the subarray prefix to the left of the maximum value.
    Recursively build the right subtree on the subarray suffix to the right of the maximum value.
    Return the maximum binary tree built from nums.
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
    // its said that, build left side tree, by the max value from left to right being the root.
    // its said that, build right side tree, by the max value from right to left being the root.
    TreeNode* buildTree(int l, int r, vector<int>& nums){
        if(l > r) return NULL;
        
        int maxi = l;  
        for(int i = l+1 ; i <= r ; i++){
            if(nums[i] > nums[maxi])
                maxi = i;
        }

        TreeNode* root = new TreeNode(nums[maxi]);

        root->left = buildTree(l, maxi-1, nums);
        root->right = buildTree(maxi+1, r, nums);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        int n = nums.size();
        return buildTree(0, n-1, nums);
    }
};

int main(){


    return 0;
}