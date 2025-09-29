#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include <unordered_map>
using namespace std;


class Next2{
public: 
    vector<int> nextGreaterElement(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 2*n-1 ; i >= 0 ; i--){
            while(st.size() > 0 && st.top() <= arr[i%n]){
                st.pop();
            }
            if(i < n){
                if(st.empty()) ans[i] = -1;
                else{
                    ans[i] = st.top();
                }
            }
            st.push(arr[i%n]);
        }
        return ans;
    }
};


int main(){
    vector<int> arr = {1,2,3,4,3};
    Next2 n;
    vector<int> ans = n.nextGreaterElement(arr);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}