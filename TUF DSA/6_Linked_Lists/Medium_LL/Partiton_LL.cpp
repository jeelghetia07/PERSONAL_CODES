#include<bits/stdc++.h>
using namespace std;

/*      LC = 86
    Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* greater = new ListNode(-101);
        ListNode* lesser = new ListNode(-101);

        ListNode* gre = greater;
        gre->next = NULL;
        ListNode* less = lesser;
        less->next = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            if(temp->val < x){
                less->next = temp;
                less = temp;
            }
            else{
                gre->next = temp;
                gre = temp;
            }
            temp = temp->next;
        }
        gre->next = NULL;

        less->next = greater->next;
        return lesser->next;
    }
};

int main(){
    /*
        Input: head = [1,4,3,2,5,2], x = 3
        Output: [1,2,2,4,3,5]


        Example 2:

        Input: head = [2,1], x = 2
        Output: [1,2]
    */

    return 0;
}