#include<iostream>
#include<stack>
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

class REVERSE{
    Node* head;
    Node* tail;
public:
    REVERSE(){
        head = tail = NULL;
    }

    Node* reverseList(Node* head){

        if(head == NULL || head->next == nullptr){
            return head;
        }
        Node* newhead = reverseList(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;



        // Node* prev = NULL;
        // Node* temp = head;

        // while(temp != NULL){
        //     Node* front = temp->next;
        //     temp->next = prev;
        //     prev = temp;
        //     temp = front;
        // }
        // return prev;



        // stack<int> st;
        // Node* temp = head;

        // while(temp != NULL){
        //     st.push(temp->data);
        //     temp = temp->next;
        // }

        // Node* newtemp = head;
        // while(newtemp != NULL){
        //     newtemp->data = st.top();
        //     st.pop();
        //     newtemp = newtemp->next;
        // }
        // return head;
    }
};

int main(){
    Node* head = new Node(1);
    Node* sec = new Node(2);
    Node* thir = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);

    head->next = sec;
    sec->next = thir;
    thir->next = four;
    four->next = five;
    five->next = nullptr;

    cout << "original list : " << endl;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    REVERSE r;
    head = r.reverseList(head);

    cout << "reversed list : ";
    temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}