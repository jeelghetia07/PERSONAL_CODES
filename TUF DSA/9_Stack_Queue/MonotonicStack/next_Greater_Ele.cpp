#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

class NEXT{
public:
    vector<int> nextgreaterele(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n-1 ; i >= 0 ; i--){
            while(st.size() > 0 && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()){
                // ans.push_back(-1);           // this stores the ans in the reverse order in this case....because the loop is running reverse...so we just write below ans...that gives the proper ans.
                ans[i] = -1;
            }
            else{
                // ans.push_back(st.top());
                ans[i] = st.top();
            } 
            st.push(arr[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {3,6,2,4,8,6,1,9,15,11,12,70};
    NEXT n;
    vector<int> ans = n.nextgreaterele(arr);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}