#include<bits/stdc++.h>
using namespace std;

/*      LC = 109
    The list will be in a sorted manner.
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

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int v){
        val = v;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* findMiddle(ListNode* head, ListNode* tail){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    TreeNode* buildTree(ListNode* head, ListNode* tail){
        if(head == tail) return NULL;

        ListNode* mid = findMiddle(head, tail);      // this will give prev node.

        TreeNode* node = new TreeNode(mid->val);     // created the node.

        node->left = buildTree(head, mid);
        node->right = buildTree(mid->next, tail);

        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, NULL);       // here NULL means:- 1 -> 2 -> 3 -> 4 -> 5 -> "NULL". so we keep traversing till the end.
    }
};

int main(){


    return 0;
}