#include<bits/stdc++.h>
using namespace std;

/*      LC = 148
    Given the head of a linked list, return the list after sorting it in ascending order.
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
    ListNode* sortList(ListNode* head){         // this is the best way .....just read in chatgpt why....merge sort is not good due to more pointer handling and random memory access....this is best and CPU friendly
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        vector<int> list;

        while(temp != NULL){
            list.push_back(temp->val);
            temp = temp->next;
        }
        sort(list.begin(), list.end());
        int n = list.size();
        temp = head;

        for(int i = 0 ; i < n ; i++){
            temp->val = list[i];
            temp = temp->next;
        }
        return head;
    }



    // ListNode* findMiddle(ListNode* head){
    //     ListNode* fast = head;
    //     ListNode* slow = head;

    //     if(fast->next->next == NULL) return head;

    //     while(fast != NULL && fast->next != NULL){
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }
    //     return slow;
    // }

    // ListNode* MergeFinalList(ListNode* list1, ListNode* list2){
    //     ListNode* t1 = list1;
    //     ListNode* t2 = list2;

    //     ListNode* dummyHead = new ListNode(-1);
    //     ListNode* temp = dummyHead;

    //     while(t1 && t2){
    //         if(t1->val <= t2->val){
    //             temp->next = t1;
    //             t1 = t1->next;
    //         }
    //         else{
    //             temp->next = t2;
    //             t2 = t2->next;
    //         }
    //         temp = temp->next;
    //     }

    //     while(t1){
    //         temp->next = t1;
    //         temp = t1;
    //         t1 = t1->next;
    //     }

    //     while(t2){
    //         temp->next = t2;
    //         temp = t2;
    //         t2 = t2->next;
    //     }
    //     return dummyHead->next;
    // }

    // ListNode* MergeSort(ListNode* head){
    //     if(head == NULL || head->next == NULL) return head;
    //     ListNode* middle = findMiddle(head);

    //     ListNode* LeftSideHead = head;
    //     ListNode* RightSideHead = middle->next;
    //     middle->next = NULL;

    //     LeftSideHead = MergeSort(LeftSideHead);
    //     RightSideHead = MergeSort(RightSideHead);

    //     return MergeFinalList(LeftSideHead, RightSideHead);
    // }


    //         // this is the optimal approach.....but the TC here is O(nlogn)
    // ListNode* sortList(ListNode* head) {
    //     if(head == NULL || head->next == NULL){
    //         return head;
    //     }
        
    //     return MergeSort(head);
    // }
};



int main(){
    /*
        Input: head = [-1,5,3,4,0]
        Output: [-1,0,3,4,5]
    */

    return 0;
}