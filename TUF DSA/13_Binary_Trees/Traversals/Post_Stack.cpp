#include<iostream>
#include <vector>
#include <stack>
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

class PostOrder{
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> ans; 
        stack<TreeNode*> st;
        if(root == NULL) return ans;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->right;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->left;
            }
        }
        return ans;
    }


    // vector<int> postorderTraversal(TreeNode* root){       // this is by using 2 diff stacks....
    //     vector<int> ans; 
    //     stack<TreeNode*> st1, st2;
    //     if(root == NULL) return ans;

    //     st1.push(root);
    //     while(!st1.empty()){
    //         root = st1.top();
    //         st1.pop();
    //         st2.push(root);
    //         if(root->left != nullptr) st1.push(root->left);
    //         if(root->right != nullptr) st1.push(root->right);
    //     }
    //     while(!st2.empty()){
    //         ans.push_back(st2.top()->val);
    //         st2.pop();
    //     }
    //     return ans;
    // }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    PostOrder p;
    vector<int> ans = p.postorderTraversal(root);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}