#include<bits/stdc++.h>
using namespace std;

/*      LC = 21
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {     // tc = O(n1 + n2).....SC = O(1)
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* DummyList = new ListNode(-1);
        ListNode* temp = DummyList;

        while(t1 && t2){
            if(t1->val <= t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        while(t1){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }

        while(t2){
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }

        return DummyList->next;
    }
};

int main(){
    /*
        Input: list1 = [1,2,4], list2 = [1,3,4]
        Output: [1,1,2,3,4,4]
    */

    return 0;
}