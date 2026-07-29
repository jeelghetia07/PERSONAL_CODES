#include<bits/stdc++.h>
using namespace std;

/*      LC = 437
    Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

    The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes);
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using ll = long long;
class Solution {
public:
    ll countFrom(TreeNode* node, ll remainingSum){
        if(node == NULL) return 0;

        ll ans = 0;

        // we found a valid path.
        if(node->val == remainingSum) ans++;  

        ans += countFrom(node->left, remainingSum - node->val);
        ans += countFrom(node->right, remainingSum - node->val);

        return ans;
    }
    // this will count from its root, how many paths exist from this node.
    ll dfs(TreeNode* node,  ll targetSum){
        if(node == NULL) return 0;

        // it counts from itself then adds the ones found from its left and right subtree.
        return countFrom(node, targetSum) + dfs(node->left, targetSum) + dfs(node->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        return dfs(root, targetSum);
    }
};

int main(){
    /*
        Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
        Output: 3
        Explanation: The paths that sum to 8 are shown.


        Example 2:

        Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
        Output: 3
    
        Constraints:
            The number of nodes in the tree is in the range [0, 1000].
            -109 <= Node.val <= 109
            -1000 <= targetSum <= 1000
    */

    return 0;
}