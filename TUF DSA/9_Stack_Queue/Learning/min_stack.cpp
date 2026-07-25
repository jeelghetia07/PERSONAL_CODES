#include<bits/stdc++.h>
using namespace std;

/*      LC = 155
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int value) pushes the element value onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.

    
*/

// brute force is simply take <val, min> and keep pushing into the stack,
using ll = long long;
class MinStack {
public:
    stack<ll> st;
    ll mini = 1e9;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        // this formula came from val < mini   -->   2*val - mini < val   -->
        else{
            if(val > mini) st.push(val);
            else{
                ll newVal = (2LL*val - mini);
                st.push(newVal);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
            ll n = st.top();
            st.pop();
            if(n < mini){
                mini = 2LL*mini - n;
            }
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        else{
            ll n = st.top();
            if(mini < n) return n;
            else return mini;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){


    return 0;
}