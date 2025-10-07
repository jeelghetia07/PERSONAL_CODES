#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

class BOTTOMVIEW{
public:
    vector<int> bottomviewofTree(TreeNode* root){
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int line = p.second;     // here the line represents the vertical line.

            mpp[line] = node->val;   // its the exact opp of top view becoz..there we check if the element is in map...then dont update....here everytime we change the number obtained.

            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }

        for(auto p : mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};

void display(vector<int>& ans){
    for(int i : ans){
        cout << i << " ";
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    BOTTOMVIEW bv;
    vector<int> ans = bv.bottomviewofTree(root);

    display(ans);
    return 0;
}