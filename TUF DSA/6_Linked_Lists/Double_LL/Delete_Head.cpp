#include<bits/stdc++.h>
using namespace std;

class ListNode{
public: 
    int val;
    ListNode* next;
    ListNode* back;

    ListNode(int v, ListNode* n1,  ListNode* b1){
        val = v;
        next = n1;
        back = b1;
    }

    ListNode(int d){
        val = d;
        next = nullptr;
        back = nullptr;
    }
};

ListNode* convertArr2LL(vector<int>& arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;

    for(int i = 1 ; i < arr.size() ; i++){
        ListNode* temp = new ListNode(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

ListNode* deleteHead(ListNode* head){
    if(head == NULL) return head;
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    ListNode* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}

void print(ListNode* head){
    while(head != NULL){
        cout << head->val << "->";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {12,5,8,7};
    ListNode* head = convertArr2LL(arr);

    head = deleteHead(head);
    print(head);

    return 0;
}