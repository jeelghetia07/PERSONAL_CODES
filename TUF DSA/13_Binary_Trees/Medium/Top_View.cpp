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

class TOPVIEW{
public:
    vector<int> topviewoftree(TreeNode* root){
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;     //this will extract the node only from the "it".
            int level = it.second;
            if(mpp.find(level) == mpp.end()) mpp[level] = node->val;

            if(node->left) q.push({node->left, level-1});
            if(node->right) q.push({node->right, level+1});
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
    root->left->right->left = new TreeNode(6);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);

    TOPVIEW tp;
    vector<int> ans = tp.topviewoftree(root);

    display(ans);
    return 0;
}