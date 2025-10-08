#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node(int d){
        data = d;
    }
    Node* next = nullptr;
};

class MIDDLE{
public:
    Node* middleofLL(Node* head){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL || fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL || fast->next == nullptr) return slow;
        }
        return head;
    }
};

int main(){
    Node* head = new Node(1);
    Node* sec = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = sec;
    sec->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    MIDDLE m1;
    Node* ans = m1.middleofLL(head);
    cout << "The Middle node is : " << ans->data << endl;
    return 0;
}