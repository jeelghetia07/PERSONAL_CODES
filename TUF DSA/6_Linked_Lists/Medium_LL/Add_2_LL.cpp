#include<iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode(int d){
        data = d;
    }
    ListNode* next = nullptr;
};

class ADD{
public:
    ListNode* addTwoLL(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1) sum += temp1->data;
            if(temp2) sum += temp2->data;
            ListNode* newNode = new ListNode(sum % 10);     // this will add the node having the value between 0-9...and remaining will be carry for the next node's sum.

            carry = sum / 10;             // this will be added in the next node.
            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};

void display(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    ListNode* l1 = new ListNode(2);
    ListNode* sec1 = new ListNode(4);
    ListNode* thir1 = new ListNode(3);

    l1->next = sec1;
    sec1->next = thir1;
    thir1->next = nullptr;

    ListNode* l2 = new ListNode(5);
    ListNode* sec2 = new ListNode(6);
    ListNode* thir2 = new ListNode(4);

    l2->next = sec2;
    sec2->next = thir2;
    thir2->next = nullptr;

    ADD ad;
    ListNode* ansHead = ad.addTwoLL(l1,l2);

    display(ansHead);
    return 0;
}