#include<bits/stdc++.h>
using namespace std;

/*      LC = 979
    You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

    In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

    Return the minimum number of moves required to make every node have exactly one coin.
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

/*
            EXPLANATION :-

    Whenever I see this problem, I should NOT think about moving coins one by one. That becomes very confusing. Instead, I should think that every node needs exactly 1 coin. After a subtree becomes balanced, it can either have extra coins left over or still need some coins. So during DFS, each child simply tells its parent: "I have x extra coins" or "I need x coins." If a child has 3 extra coins, those 3 coins must travel through the edge connecting it to its parent, so that costs 3 moves. If a child needs 3 coins, then 3 coins must travel through the same edge in the opposite direction, which also costs 3 moves. Therefore, the number of moves contributed by a child is always abs(balance). At each node, I first solve the left and right subtrees, count the moves needed to transfer their extra/missing coins, then calculate my own balance. My balance is: coins I currently have + extra coins received from children - 1 coin that I must keep for myself. Whatever remains is passed to my parent. If positive, I give coins to my parent; if negative, I ask my parent for coins. The answer is simply the total number of coins that cross all edges in the tree.

*/

int moves = 0;      // this is a global variable to find the total moves.
int dfs(TreeNode* node){
    if(node == NULL) return 0;

    int left = dfs(node->left);
    int right = dfs(node->right);

    moves += abs(left) + abs(right);      // this is mod due to the nodes might be needing the coins returning -1;

    return node->val + left + right -1;     // this -1 here represents the node's 1 coin.
}
int distributeCoins(TreeNode* root) {
    int find = dfs(root);

    return moves;
}


int main(){


    return 0;
}