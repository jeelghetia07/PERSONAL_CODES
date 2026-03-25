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
        for(int i = 0 ; i < left-1 ; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for(int i = 0 ; i < right-left ; i++){
            ListNode* front = curr->next;
            curr->next = front->next;
            front->next = prev->next;
            prev->next = front;
        }
        return dummy->next;
    }
};

int main(){
    /*
        Input: head = [1,2,3,4,5], left = 2, right = 4
        Output: [1,4,3,2,5]
    */

    return 0;
}