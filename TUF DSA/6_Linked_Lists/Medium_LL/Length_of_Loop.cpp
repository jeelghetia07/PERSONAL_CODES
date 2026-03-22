#include<bits/stdc++.h>
using namespace std;

/*      GFG
    Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

    Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.
*/

class Node{
public:
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL) return 0;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                int cnt = 1;
                fast = fast->next;
                
                while(slow != fast){
                    fast = fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        
        
        // Node* temp = head;
        // int timer = 1;
        
        // unordered_map<Node*, int> mpp;
        
        // while(temp != NULL){
        //     if(mpp.find(temp) != mpp.end()){
        //         int prevTimer = mpp[temp];
        //         return timer-prevTimer;
        //     }
        //     mpp[temp] = timer;
        //     temp = temp->next;
        //     timer++;
        // }
        return 0;
    }
};

int main(){
    // list is [1,2,3,4,5]....last node is attached to pos = 2 (1 based indexing)......ans = 4;

    return 0;
}