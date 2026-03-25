#include<bits/stdc++.h>
using namespace std;

/*      LC = 83
    Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
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
        ListNode* dummyNode = new ListNode(-101);
        ListNode* prev = dummyNode;
        ListNode* temp = head;

        while(temp != NULL){
            if(prev->val != temp->val){
                prev->next = temp;
                prev = temp;
            }
            if(prev->val == temp->val && temp->next == NULL){
                prev->next = NULL;
            }
            temp = temp->next;
        }
        return dummyNode->next;
    }
};

int main(){
    /*
        list = [1,1,2]
        list = [1,1,2,3,3];
    */

    return 0;
}