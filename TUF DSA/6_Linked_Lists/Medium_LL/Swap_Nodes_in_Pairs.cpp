#include<bits/stdc++.h>
using namespace std;

/*      LC = 24
    Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* prev = dummyHead;

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            ListNode* front = curr->next;
            curr->next = front->next;
            front->next = prev->next;
            prev->next = front;
            prev = curr;

            curr = curr->next;
        }
        return dummyHead->next;
    }
};

int main(){
    /*
        Input: head = [1,2,3,4]
        Output: [2,1,4,3]
    */

    return 0;
}