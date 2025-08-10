#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

public:
    Node(int data1 , Node* next1){    // this constructor is used for setting the dataa(val) and the next address.
        data = data1;
        next = next1;
    }

public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* Array2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;     // or we can say that mover = temp.   both is one and the same.
        mover = temp;
    }
    return head;
}

int LengthLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
        cnt++; 
    }
    return cnt;
}

int checkifPresent(Node* head , int val){
    Node* temp = head;
    while(temp){
        if((temp->data) == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {12,5,8,7,6,9,8,5,44,32,4,7,78,99};
    Node* head = Array2LL(arr);
    Node* temp = head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "length of the LL is : " << LengthLL(head) << endl;
    cout << checkifPresent(head,32) << endl;
    // cout << "the head is pointing to : " << head->data << endl;
}