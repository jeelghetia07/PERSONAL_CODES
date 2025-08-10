#include<iostream>
#include<algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d1,Node* n1){
        data = d1;
        next = n1;
    }
    Node(int d1){
        data = d1;
        next = nullptr;
    }
};


                            // TOURTOISE & HARE algo   (SLOW AND FAST ALGO) //

bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}


                            // BRUTE FORCE APPROACH //

// bool hasCycle(Node *head){
//     Node* temp = head;
//     unordered_map<Node* , int> mpp;
//     while(temp != nullptr){
//         if(mpp.find(temp) != mpp.end()){
//             return true;
//         }
//         mpp[temp] = 1;
//         temp = temp->next;
//     }
//     return false;
// }

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
    five->next = thir;    // creating a cycle.
    five->next = nullptr;    // if we do this.....then no loop detected.
    
    if(hasCycle(head)){
        cout << "loop detected." << endl;
    }
    else{
        cout << "No loop detected." << endl;
    }

    delete head;
    delete sec;
    delete thir;
    delete four;
    delete five;

    return 0;
}