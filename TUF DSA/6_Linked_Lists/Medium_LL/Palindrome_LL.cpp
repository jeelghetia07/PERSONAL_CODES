#include<bits/stdc++.h>
using namespace std;

/*      LC = 234
    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        ListNode*newHead1 = reverse(newHead);



        // ListNode* temp = head;

        // stack<int> st;

        // while(temp != NULL){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;

        // while(!st.empty()){
        //     if(st.top() == temp->val){
        //         st.pop();
        //     }
        //     else{
        //         return false;
        //     }
        //     temp = temp->next;
        // }
        return true;
    }
};

int main(){
    // LL = [1, 2, 2, 1]....ans is true;....
    // LL = [1, 2].....ans is false;

    return 0;
}