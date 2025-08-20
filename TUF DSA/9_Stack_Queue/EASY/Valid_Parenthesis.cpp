#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Valid{
public: 
    bool checkValidity(string s){
        int n = s.length();
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')){
                    st.pop();
                }
                else return false;
            }
        }
        return st.size() == 0;
    }
};

int main(){
    string s = "({[]}[]{})";
    Valid v;
    if(v.checkValidity(s)){
        cout << "its valid";
    }
    else{
        cout << "its invalid";
    }
    return 0;
}