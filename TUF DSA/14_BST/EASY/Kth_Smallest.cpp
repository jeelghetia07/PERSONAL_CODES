//Kth_Smallest.cpp
#include<iostream>
#include<vector>
#include<climits>
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

class KTH_SMALL{
public:
    // void inorder(TreeNode* root, vector<int>& ans){
    //     if(!root){
    //         return;
    //     }
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    //     return;
    // }

    // pair<int, int> Kthsmallestele(TreeNode* root, int k){
    //     vector<int> ans;
    //     inorder(root, ans);
    //     int kLar = ans[ans.size()-k];
    //     int kSmall = ans[k-1];
    //     return make_pair(kLar,kSmall);
    // }
    void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;

        reverseInorder(node->right, counter, k, kLargest);

        counter++;

        if (counter == k) {
            kLargest = node->val;
            return;
        }

        reverseInorder(node->left, counter, k, kLargest);
    }

    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;

        inorder(node->left, counter, k, kSmallest);
        counter++;
        if (counter == k) {
            kSmallest = node->val;
            return;
        }

        inorder(node->right, counter, k, kSmallest);
    }

    pair<int, int> findKth(TreeNode* root, int k) {
        int kSmallest = INT_MIN, kLargest = INT_MIN;
        int counter = 0; 

        inorder(root, counter, k, kSmallest);
        
        counter = 0; 
        reverseInorder(root, counter, k, kLargest);

        return make_pair(kSmallest, kLargest);
    }
};

void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main(){

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    KTH_SMALL kObj;
    int k = 3;
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = kObj.findKth(root, k);

    cout << "Kth largest element: " << kthElements.first << endl;
    cout << "Kth smallest element: " << kthElements.second << endl;

    return 0;
}