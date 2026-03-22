#include<bits/stdc++.h>
using namespace std;

/*      LC = 19
    Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n){      // TC = O(2*len)
        if(head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0 ; i < n ; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(fast->next != NULL){      // stop at the last node
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* dltNode = slow->next;
        if(slow->next->next == NULL) {
            slow->next = NULL;
        }
        else{
            slow->next = slow->next->next;
        }
        return head;
    }



    // ListNode* removeNthFromEnd(ListNode* head, int n) {         // TC = O(2*lenOfLL)/.....SC = O(1)
    //     if(head == NULL) return head;
    //     int cnt = 0;
    //     ListNode* temp = head;

    //     while(temp != NULL){
    //         cnt++;
    //         temp = temp->next;
    //     }

    //     int res = cnt-n;    
    //     if(res == 0) return head->next;

    //     temp = head;
    //     while(temp != NULL){
    //         res--;
    //         if(res == 0) break;
    //         temp = temp->next;
    //     }

    //     ListNode* deleteNode = temp->next;
    //     if(temp->next->next == NULL) {
    //         temp->next = NULL;
    //     }
    //     else{
    //         temp->next = temp->next->next;
    //     }

    //     delete deleteNode;
    //     return head;
    // }
};

int main(){
    // head = [1,2,3,4,5], n = 2

    return 0;
}