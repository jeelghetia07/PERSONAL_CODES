#include<iostream>
using namespace std;

class Node{
public:
    int data;    // this is the value of the node.
    Node* next;    // this is the pointer that points the next node's address.

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val); // dynamic object
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = NULL;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL doesnot exist" << endl;
            return ;
        }
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            return;
        }
        Node* temp = head;           // srting from the head.
        while(temp->next != tail){    // till the prevoius node.
            temp = temp->next;         // moving the temp node by node till the last second node.
        }
        temp->next = NULL;
        delete tail;    // this deletes its memeory not the variable.
        tail = temp;    // as the temp was the prevoius node..and now we dlted the tail..so the tail is asigned the temp.
    }

    void insert(int val, int pos){
        if(pos < 0){
            cout << "invalid pos \n";
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0 ; i < pos-1 ; i++){
            if(temp == NULL){
                cout << "invalid pos\n";
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;      // this says that..1 was pointed to 2....now by this we say that 4's next is to be pointed to temp(1)'s->next(2).
        temp->next = newNode;
    }

    int search(int key){
        int index = 0;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == key){
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
    
    void printLL(){
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;      // this represents i++;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // ll.push_back(4);
    // ll.push_back(5);

    // ll.pop_front();

    // ll.printLL();

    // ll.pop_back();

    ll.insert(4,1);
    cout << ll.search(4) << endl;

    ll.printLL();
    return 0;
}