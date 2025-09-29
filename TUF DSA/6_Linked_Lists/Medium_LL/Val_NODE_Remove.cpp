// Val_NODE_Remove.cpp
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class REMOVE_NODE{
    Node* head;
    Node* tail;
public:
    REMOVE_NODE(){
        head = tail = NULL;
    }
    Node* removeNode(Node* head, int val){
        while(head != NULL && head->data == val){
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->next->data == val){
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};

int main(){
    Node* head = new Node(1);
    Node* sec = new Node(2);
    Node* thir = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(3);

    head->next = sec;
    sec->next = thir;
    thir->next = four;
    four->next = five;
    five->next = six;
    six->next = nullptr;

    cout << "original list : " << endl;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    REMOVE_NODE rn;
    head = rn.removeNode(head,3);

    cout << "new list : " << endl;
    temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
    return 0;
}