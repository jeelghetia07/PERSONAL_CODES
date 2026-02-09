// Largest_Rec_area_Histogram.cpp
#include<bits/stdc++.h>
using namespace std;

                // OPTIMAL APPROACH

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;          // we are storing the indexes.
        int maxAns = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                int element = st.top();
                st.pop();
                int nse = i;        // as we only pop when we find a smaller element than the top....so obv the nse will be the i (which is smaller than top)....
                int pse = st.empty() ? -1 : st.top();
                maxAns = max(maxAns, arr[element] * (nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){    // if there are any elements left in the stack....for all them,....the nse will be n becoz....there are in the stack due to no further smaller elements(which can pop them out)....
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxAns = max(maxAns, arr[element] * (nse-pse-1));
        }
        return maxAns;
    }

            // BRUTE FORCE TC = O(3n)....SC = O(2N)+O(N)

// int largestRectangleArea(vector<int>& arr){
//     int n = arr.size();
//     stack<int> st;

//     int leftSmall[n], rightSmall[n];
//     for(int i = 0 ; i < n ; i++){
//         while(!st.empty() && arr[st.top()] >= arr[i]){
//             st.pop();
//         }
//         if(st.empty()) leftSmall[i] = 0;
//         else leftSmall[i] = st.top()+1;
//         st.push(i);
//     }

//     while(!st.empty()) st.pop();

//     for(int i = n-1 ; i>= 0 ; i--){
//         while(!st.empty() && arr[st.top()] >= arr[i]){
//             st.pop();
//         }

//         if(st.empty()) rightSmall[i] = n-1;
//         else rightSmall[i] = st.top()-1;
//         st.push(i);
//     }

//     int maxAns = 0;
//     for(int i = 0 ; i < n ; i++){
//         maxAns = max(maxAns, arr[i]*(rightSmall[i]-leftSmall[i]+1));
//     }
//     return maxAns;
// }


int main(){
    vector<int> arr = {2, 1, 5, 6, 2, 3, 1};
    cout << "The max rectangle area is : " << largestRectangleArea(arr);

    return 0;
}