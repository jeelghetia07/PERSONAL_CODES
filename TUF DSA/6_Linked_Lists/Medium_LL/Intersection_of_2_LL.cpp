#include<bits/stdc++.h>
using namespace std;

/*      LC = 160
    Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

    For example, the following two linked lists begin to intersect at node c1:
    The test cases are generated such that there are no cycles anywhere in the entire linked structure.

    Note that the linked lists must retain their original structure after the function returns.
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
    ListNode* collisonPoint(ListNode *smaller, ListNode *bigger, int d){
        ListNode* t1 = smaller;
        ListNode* t2 = bigger;

        for(int i = 0 ; i < d ; i++){
            t2 = t2->next;
        }

        while(t1 != NULL && t2 != NULL){
            if(t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
    ListNode* getIntersectionNode(ListNode *head1, ListNode *head2){
        if(head1 == NULL || head2 == NULL) return NULL;
        ListNode* temp = head1;
        int n1 = 0, n2 = 0;

        while(temp != NULL){
            n1++;
            temp = temp->next;
        }

        temp = head2;
        while(temp != NULL){
            n2++;
            temp = temp->next;
        }

        if(n1 < n2){
            return collisonPoint(head1, head2, n2-n1);
        }
        return collisonPoint(head2, head1, n1-n2);
    }



    // ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    //     ListNode* temp = head1;
    //     unordered_map<ListNode*, int> mpp;
    //     while(temp != NULL){
    //         mpp[temp] = 1;
    //         temp = temp->next;
    //     }

    //     temp = head2;
    //     while(temp != NULL){
    //         if(mpp.find(temp) != mpp.end()){
    //             return temp;
    //         }
    //         mpp[temp] = 1;
    //         temp = temp->next;
    //     }
    //     return NULL;
    // }
};

int main(){


    return 0;
}