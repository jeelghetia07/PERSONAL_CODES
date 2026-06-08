#include<bits/stdc++.h>
using namespace std;

/*      LC = 99
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
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
    TreeNode* firstV;       // first violation
    TreeNode* prev;
    TreeNode* middleV;      // if there are adjecent violations, the middle will store the 2nd V and then we will not find the last one, and hence swap the first and middle.
    TreeNode* lastV;        // if there are non adj violations, then we will have the 3 violations, and hence here we will swap the first and the last violation.
public:
    void inorder(TreeNode* root){               // here basially we are doing, the inorder traversal and here, left / root(here is the main business occuring) / right.
        if(root == NULL) return;

        inorder(root->left);

        if((prev != NULL) && (prev->val > root->val)){      // here we found a violation.
            if(firstV == NULL){      // this is for only if there is no first violation encounterd.
                firstV = prev;
                middleV = root;
            }
            else{           // after first is set, we only update the lastone.
                lastV = root;
            }
        }
        prev = root;        // update the prev everytime after finding or not finding a violation.
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        firstV = middleV = lastV = NULL;

        prev = new TreeNode(INT_MIN);       // creating a random prev variable.
        inorder(root);

        if(firstV && lastV) swap(firstV->val, lastV->val);          // this is the non adj case.
        else swap(firstV->val, middleV->val);         // this is the adjecnet case.
    }
};

int main(){


    return 0;
}