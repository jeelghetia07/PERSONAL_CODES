#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given the root of a binary tree, determine whether the tree satisfies the Children Sum Property. In this property, each non-leaf node must have a value equal to the sum of its left and right children's values. A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.

    Return true if every node in the tree satisfies this condition, otherwise return false.
*/



class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    bool func(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        
        if(root->left){
            if(func(root->left) == false) return false;
        }
        if(root->right){
            if(func(root->right) == false) return false;
        }
        
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        
        if(sum != root->data) return false;
        
        return true;
    }
    bool isSumProperty(Node *root) {
        if(root == NULL) return true;
        return func(root);
    }
};

int main(){
    /*
        Input: root = [35, 20, 15, 15, 5, 10, 5]
        Output: True
        Explanation: Here, every node is sum of its left and right child.

        Input: root = [1, 4, 3, 5]
        Output: False
        Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
    */

    return 0;
}