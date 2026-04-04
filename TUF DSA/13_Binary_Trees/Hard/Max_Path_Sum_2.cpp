#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special node to another special node.
    Note: Here special node is a node that is connected to exactly one different node.

    HERE THE MOST IMP THING IS THAT, IT SAYS A SPECIAL NODE (read the note carefully).........connected to exactly one diff node, thats possible only at the leaf level.....so the que is basically.

    MAX PATH SUM FROM LEAF TO ANOTHER LEAF.
*/

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int maxSum(TreeNode* node, int& maxi){
        if(node == NULL) return 0;
        
        int leftSum = maxSum(node->left, maxi);
        int rightSum = maxSum(node->right, maxi);
        
        if(node->left && node->right){      // update the maxi iff there exists the left and right node.
            maxi = max(maxi, node->data + leftSum + rightSum);
            return node->data + max(leftSum, rightSum);
        }
        if(node->left == NULL) return node->data + rightSum;        // if there is a skew tree then return this an ans.
        else return node->data + leftSum;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        
        int temp = maxSum(root, maxi);
        
        return (maxi == INT_MIN) ? temp : maxi;
    }
};

int main(){
    /*
        Input root = [-9, 6, -10];
        Output: -13 ( not 6) , we have to connected leaf to leaf.

        Input: root = [3, 4, 5, -10, 4, N, N]    
        Output: 16
        Explanation: 
            Maximum Sum lies between special node 4 and 5. 4 + 4 + 3 + 5 = 16.


        Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, 0, 4, -1, 10]
        Output:  27
        Explanation: 
            The maximum possible sum from one special node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)


        Input: root = [3, 4, 1, -10, 4]                        
        Output: 12
        Explanation: 
            Maximum Sum lies between special node 4 and 5. 4 + 4 + 3 + 1 = 12.
    */

    return 0;
}