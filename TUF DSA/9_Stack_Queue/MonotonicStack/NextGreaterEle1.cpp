#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include <unordered_map>
using namespace std;

class Next1{
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2){
        int n = arr2.size();
        stack<int> st;
        unordered_map<int,int> mpp;
        
        for(int i = n-1 ; i >= 0 ; i--){         // becoz....to know the next greater element we have to know all the last elements.
            while(st.size() > 0 && st.top() <= arr2[i]){   //till the stack is not empty and till the elemenet in the stack is less than the arr2[i] ele...pop till that number..and then push the arr2[i] (max than other) number into the stack.
                st.pop();
            }
            if(st.empty()){          // if there is no element greater than the element arr2[i]...so its marked -1.
                mpp[arr2[i]] = -1;
            }
            else{
                mpp[arr2[i]] = st.top();       // this indicates that at index arr2[i] (number in the arr2) the value is which is in the top of stack.
            }
            st.push(arr2[i]);
        }
        vector<int> ans;
        for(int i : arr1){
            ans.push_back(mpp[i]);
        }
        return ans;
    }
};


int main(){
    vector<int> arr1 = {4,1,2};
    vector<int> arr2 = {1,3,4,2};
    Next1 n;
    vector<int> ans = n.nextGreaterElement(arr1,arr2);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}