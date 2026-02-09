// Largest_Rec_area_Histogram.cpp
#include<bits/stdc++.h>
using namespace std;

int largestRect(vector<int>& arr){
    int n = arr.size();
    stack<int> st;

    int leftSmall[n], rightSmall[n];
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()) leftSmall[i] = 0;
        else leftSmall[i] = st.top()+1;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n-1 ; i>= 0 ; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()) rightSmall[i] = n-1;
        else rightSmall[i] = st.top()-1;
        st.push(i);
    }

    int maxAns = 0;
    for(int i = 0 ; i < n ; i++){
        maxAns = max(maxAns, arr[i]*(rightSmall[i]-leftSmall[i]+1));
    }
    return maxAns;
}

int main(){
    vector<int> arr = {2, 1, 5, 6, 2, 3, 1};
    cout << "The max rectangle area is : " << largestRect(arr);

    return 0;
}