#include<bits/stdc++.h>
using namespace std;

/*      LC = 92
    Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
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

    ListNode* reverseBetween(ListNode* head, int left, int right){
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i = 0 ; i < left-1 ; i++){      // this brings the prev pointer just before the start of reversing node.
            prev = prev->next;
        }

        ListNode* curr = prev->next;        // initially points to the first node of reversing part.

        for(int i = 0 ; i < right-left ; i++){          // we have to change the links "The no. of nodes - 1 times. so that the first node becomes the last and we change the links"
            ListNode* front = curr->next;
            curr->next = front->next;
            front->next = prev->next;
            prev->next = front;
        }
        return dummy->next;
    }
};


                    //  A NEW APPRAOCH, simple and logical. but quite a long code.

/*
    class Solution {
        ListNode* newTail;
    public:
        ListNode* reverse(ListNode* head, ListNode* tail){
            ListNode* curr = head;
            ListNode* prev = NULL;
            
            //original head becomes the new Tail.
            newTail = head;

            while(curr != tail){
                ListNode* front = curr->next;
                curr->next = prev;

                prev = curr;
                curr = front;
            }

            return prev;
        }
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(head == NULL || left == right) return head;

            ListNode* dummyNode = new ListNode(-101);
            dummyNode->next = head;

            // Final node just before left.
            ListNode* prev = dummyNode;

            for(int i = 0 ; i < left-1 ; i++){
                prev = prev->next;
            }

            // final node just after right.
            ListNode* tail = head;

            for(int i = 1 ; i < right ; i++){
                tail = tail->next;
            }

            tail = tail->next;

            // Now found both head and tail, so i have to change and reverse the list from head->tail to tail -> head.
            ListNode* newHead = reverse(prev->next, tail);

            prev->next = newHead;
            newTail->next = tail;

            return dummyNode->next;
        }
    };
*/

int main(){
    /*
        Input: head = [1,2,3,4,5], left = 2, right = 4
        Output: [1,4,3,2,5]
    */

    return 0;
}