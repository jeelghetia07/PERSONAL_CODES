#include<bits/stdc++.h>
using namespace std;

/*      LC = 82
    Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
*/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummyNode = new ListNode(-101);
        dummyNode->next = head;
        ListNode* prev = dummyNode;
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                while(curr->next != NULL && curr->val == curr->next->val){
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }

        return dummyNode->next;
    }
};

int main(){
    /*
        list = [1,1,2,3,3,4,5,5,6]...ans = [2,4,6];
    */

    return 0;
}