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

class Stack{
public:
    Node* TOP;
    int size;
    Stack(){
        TOP = NULL;
        size = 0;
    }
    void push(int val){
        Node* temp = new Node(val);   // storing the value in the temp node.
        temp->next = TOP;
        TOP = temp;
        size = size + 1;
    }
    void pop(){
        if(TOP == NULL){
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node* temp = TOP;
        TOP = TOP->next;
        delete temp;
        size--;
    }
    int top(){
        if (TOP == NULL) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return TOP->data;
    }
    int Size(){
        return size;
    }
    void display(){
        Node* temp = TOP;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Stack s;
    s.push(9);
    s.push(6);
    s.push(4);
    s.push(2);
    s.pop();
    s.top();
    s.push(12);
    s.display();
}