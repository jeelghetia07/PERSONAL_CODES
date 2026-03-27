#include<bits/stdc++.h>
using namespace std;

/*      LC = 25
    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
    ListNode* findKthNode(ListNode* head, int k){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            if(cnt == k) break;
            head = head->next;
        }

        return head;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL){
            ListNode* KthNode = findKthNode(temp, k);
            if(KthNode == NULL){
                if(prevLast)
                    prevLast->next = temp;
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            ListNode* newHead = reverse(temp);
            if(temp == head){
                head = newHead;
            }
            else{
                prevLast->next = newHead;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};

int main(){
    /*
        Input: head = [1,2,3,4,5], k = 2
        Output: [2,1,4,3,5]
    */

    return 0;
}