#include<iostream>
#include<vector>
#include<stack>
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

class BOUNDARY{
    bool isLeaf(TreeNode* root){          // helper function to check if its a leaf or not.
        return (root != NULL && root->left == nullptr && root->right == NULL);
    }
    void addLeftBoundary(TreeNode* root, vector<int>& ans){    
        TreeNode* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->val);
            if(curr->left != nullptr) curr = curr->left;
            else{
                curr = curr->right;
            }
        }
    }
    void addRightBoundary(TreeNode* root, vector<int>& ans){
        TreeNode* curr = root->right;
        stack<int> st;
        while(curr){
            if(!isLeaf(curr)) st.push(curr->val);
            if(curr->right != nullptr) curr = curr->right;
            else curr = curr->left; 
        }
        int size = st.size();
        for(int i = 0 ; i < size ; i++){
            ans.push_back(st.top());
            st.pop();
        }
    }
    void addLeaves(TreeNode* root, vector<int>& ans){
        if(isLeaf(root)){
            ans.push_back(root->val);
            return;
        }
        if(root->left) addLeaves(root->left,ans);
        if(root->right) addLeaves(root->right, ans);
    }
public:
    vector<int> boundaryTraversal(TreeNode* root){
        vector<int> ans;
        if(root == NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->val);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    BOUNDARY b;
    vector<int> ans = b.boundaryTraversal(root);
    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}
