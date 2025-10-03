#include<iostream>
#include<vector>
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

class ZIGZAG{
public:
    vector<vector<int>> zigzagtravesal(TreeNode* root){
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);      // for storing the level elements in particular order....this isof size becoz...it may have left and right....and they will be twice(each once) the root...that we have put in the queue..

            for(int i = 0 ; i < size ; i++){  // fro storing the elements turn by turn in ASC / DESC order.
                TreeNode* node = q.front();          // take the FIFO element and make it the temporary root...and if it exist then add the left adn right of the particular node.
                q.pop();         // as we have stored it in the node......pop it from the queue.

                int index = (lefttoright) ? i : size-i-1;     // if the LtR is true...then start from left and if false...store from last of the row vector(having the element size of the queue.)
                                                            // most IMP step.
                row[index] = node->val;

                if(node->left != nullptr) q.push(node->left); 
                if(node->right != nullptr) q.push(node->right);

            }
            lefttoright = !lefttoright;
            ans.push_back(row);
        }
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    ZIGZAG z;
    vector<vector<int>> result = z.zigzagtravesal(root);

    for(auto &row : result){
        for(int i : row){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

