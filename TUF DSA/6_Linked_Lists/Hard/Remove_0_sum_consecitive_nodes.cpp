#include<bits/stdc++.h>
using namespace std;

/*      LC = 1171
    Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
    After doing so, return the head of the final linked list.  You may return any such answer.
    (Note that in the examples below, all sequences are serializations of ListNode objects.)
*/

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int v){
        val = v;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        unordered_map<int, ListNode*> mpp;
        mpp[0] = dummyNode;

        ListNode* temp = head;
        int sum = 0;
        while(temp != NULL){
            sum += temp->val;

            // this will be pointing the node thats previous to the nodes that added up to form 0.
            if(mpp.count(sum)){
                ListNode* start = mpp[sum];
                
                ListNode* curr = start->next;
                int currSum = sum;

                while(curr != temp){            // we erase the old values that were in the map but after deleting some nodes, they still be present in the map, but in actuall they should not be there. (try the TC at last.)
                    currSum += curr->val;
                    mpp.erase(currSum);
                    curr = curr->next;
                }

                start->next = temp->next;
            }
            
            if(!mpp.count(sum))
                mpp[sum] = temp;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};


int main(){
    /*
        Example 1:
        Input: head = [1,2,-3,3,1]
        Output: [3,1]
        Note: The answer [1,2,1] would also be accepted.


        Example 2:
        Input: head = [1,2,3,-3,4]
        Output: [1,2,4]


        Example 3:
        Input: head = [1,2,3,-3,-2]
        Output: [1]

        Input
        head = [1,3,2,-3,-2,5,5,-5,1]

        Output = [1,5,5,-5,1]
        Expected = [1,5,1]
        

        Constraints:
        The given linked list will contain between 1 and 1000 nodes.
        Each node in the linked list has -1000 <= node.val <= 1000.
    */

    return 0;
}