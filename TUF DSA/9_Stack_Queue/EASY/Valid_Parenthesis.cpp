#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Valid{
public: 
    bool checkValidity(string s){
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            
        }
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