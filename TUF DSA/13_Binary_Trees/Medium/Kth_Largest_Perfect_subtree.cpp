#include<bits/stdc++.h>
using namespace std;

/*      LC = 3319
    You are given the root of a binary tree and an integer k.

    Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if it doesn't exist.

    A perfect binary tree is a tree where all leaves are on the same level, and every parent has two children.
*/

class TreeNode{
    int data;
public:
    TreeNode(int d){
        data = d;
    }
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

            // TC = O(n) + O(n*logn) + O(k*logn) = O(n*logn)......visiting all nodes, inserting n nodes into pq, removing k-1 nodes.
            // SC = O(h) + O(n) = O(n).......the recursion stack space (height), and pq.

class Solution {
    // The largest ele will always be at the top.
    priority_queue<int> pq;
public:
    // checks if nodes on both sides are same or not.
    bool isPerfectBT(int left, int right){
        return (left - right) == 0;
    }
    
    int func(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lhs = func(root->left);
        int rhs = func(root->right);

        // here if any one node is not perfect, the parent will definitely not be perfect, so directly sreturn -1.
        if(lhs == -1 || rhs == -1) return -1;

        bool isOk = isPerfectBT(lhs, rhs);

        // if is perfect, then push into the pq.
        if(isOk){
            pq.push(1 + lhs + rhs);
        }
        // this means not perfect, so to represent not perfect, we return -1 as the size.
        else{
            return -1;
        }
        
        // if both nodes are equal, push the nodes of left and right and +1 (the node itself).
        return 1 + (lhs + rhs);
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(root == NULL) return 0;

        int ans = func(root);

        // this will stop at the point where we find the kth size.
        int end = k-1;

        // is elements are lesser than those we have to find, return -1.
        if(k > pq.size()) return -1;

        while(!pq.empty() && end--){
            pq.pop();
        }

        if(!pq.empty()) return pq.top();
        return -1;
    }
};

int main(){
    /*
        Example 1:

        Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
        Output: 3
        Explanation:

        The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are [3, 3, 1, 1, 1, 1, 1, 1].
        The 2nd largest size is 3.


        Example 2:

        Input: root = [1,2,3,4,5,6,7], k = 1
        Output: 7
        Explanation:

        The sizes of the perfect binary subtrees in non-increasing order are [7, 3, 3, 1, 1, 1, 1]. The size of the largest perfect binary subtree is 7.


        Example 3:

        Input: root = [1,2,3,null,4], k = 3
        Output: -1
        Explanation:

        The sizes of the perfect binary subtrees in non-increasing order are [1, 1]. There are fewer than 3 perfect binary subtrees.

        
        Constraints:

        The number of nodes in the tree is in the range [1, 2000].
        1 <= Node.val <= 2000
        1 <= k <= 1024
    */

    return 0;
}