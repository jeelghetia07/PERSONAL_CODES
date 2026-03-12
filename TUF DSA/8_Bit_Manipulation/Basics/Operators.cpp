#include<bits/stdc++.h>
using namespace std;

int AND(int a, int b){
    return a & b;
}

int OR(int a, int b){
    return a | b;
}

int XOR(int a, int b){
    return a ^ b;
}

int NOT(int a){
    return (~a);
}


int main(){
    int a = 5;  // 0101
    int b = 3;  // 0011

    int ans1 = AND(a,b);
    int ans2 = OR(a,b);
    int ans3 = XOR(a,b);
    int ans4 = NOT(a);

    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    cout << ans4 << endl;

    return 0;
}