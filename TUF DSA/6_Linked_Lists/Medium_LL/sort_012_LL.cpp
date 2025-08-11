#include<iostream>
#include<algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d ,Node* n){
        data = d;
        next = n;
    }
    Node(int d1){
        data = d1;
        next = nullptr;
    }
};


Node* sort012(Node* head){
    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);
    Node* zero = zerohead;
    Node* one = onehead;
    Node* two =twohead;
    Node* temp = head;

    while(temp != NULL ){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else if(temp->data == 2){
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    if(onehead->next != nullptr) {
        zero->next = onehead->next;
    } else {
        zero->next = twohead->next;
    }

    one->next = twohead->next;

    Node* newhead;
    if(zerohead->next != nullptr) {
        newhead = zerohead->next;
    } else if(onehead->next != nullptr) {
        newhead = onehead->next;
    } else {
        newhead = twohead->next;
    }

    // Clean up dummy heads
    delete zerohead;
    delete onehead;
    delete twohead;

    return newhead;
}



// void sort012(Node* head){
//     Node* temp = head;
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;

//     while(temp != NULL){
//         if(temp->data == 0) count0++;
//         else if(temp->data == 1) count1++;
//         else if(temp->data == 2) count2++;
//         temp = temp->next;
//     }

//     temp = head;

//     while(temp != NULL){
//         if(count0 != 0){
//             temp->data = 0;
//             count0--;
//         }
//         else if(count1 != 0){
//             temp->data = 1;
//             count1--;
//         }
//         else if(count2 != 0){
//             temp->data = 2;
//             count2--;
//         }
//         temp = temp->next;
//     }
// }

int main(){
    Node* head = new Node(1);
    Node* sec = new Node(0);
    Node* thir = new Node(1);
    Node* four = new Node(0);
    Node* five = new Node(2);
    Node* six = new Node(1);
    Node* seven = new Node(2);

    head->next = sec;
    sec->next = thir;
    thir->next = four;
    four->next = five;
    five->next = six;    
    six->next = seven;
    seven->next = nullptr;

    cout << "original list : " << endl;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    head = sort012(head);
    cout << endl;
    cout << "sorted list : " << endl;
    temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}