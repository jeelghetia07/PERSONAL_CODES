#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int temp){
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }

    int val = st.top();
    st.pop();

    insert(st, temp);

    st.push(val);
}

void sortStack(stack<int>& st){
    if(!st.empty()){
        int temp = st.top();
        st.pop();

        sortStack(st);

        insert(st, temp);
    }
}

int main(){
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    sortStack(st);

    return 0;
}