#include<bits/stdc++.h>
using namespace std;

/*      LC = 146
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    The functions get and put must each run in O(1) average time complexity.
*/

class Node{
public:
    int key, val;
    Node *next;
    Node *prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    unordered_map<int, Node*> mpp;
    int cap;
    Node *head = new Node(-1,-1), *tail = new Node(-1, -1);

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertAtHead(Node* node){
        node->next = head->next;        // attached the new Node to the next node of head so that we dont loose the List.
        node->prev = head;

        node->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node){
        Node* previous = node->prev;
        Node* ahead = node->next;

        previous->next = ahead;
        ahead->prev = previous;

        node->next = nullptr;
        node->prev = nullptr;
    }
    
    int get(int key) {
        // if we dont find the ele in the map, we return -1.
        if(mpp.find(key) == mpp.end()){
            return -1;
        }

        // if we do, then we find and return the val, but as we get it, we have to place it ahead of everyone.
        Node* node = mpp[key];

        deleteNode(node);
        insertAtHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;

            deleteNode(node);
            insertAtHead(node);
        }
        else{
            if(mpp.size() == cap){
                Node* node = tail->prev;       // remove the LRU from DLL, means the one prev to tail.
                mpp.erase(node->key);       // erase the key from map.
                deleteNode(node);
            }

            Node* node = new Node(key, value);
            mpp[key] = node;

            insertAtHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){


    return 0;
}