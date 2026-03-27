#include<bits/stdc++.h>
using namespace std;

/*      LC = 61
    Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        if(k % len == 0) return head;
        
        k = k % len;
        int cnt = 1;
        ListNode* lastNode = head;
        while(cnt != len-k){
            cnt++;
            lastNode = lastNode->next;
        }

        ListNode* temp = lastNode->next;
        lastNode->next = NULL;

        tail->next = head;
        head = temp;
        return head;
    }
};

int main(){
    /*
        Input: head = [1,2,3,4,5], k = 2
        Output: [4,5,1,2,3]
    */

    return 0;
}