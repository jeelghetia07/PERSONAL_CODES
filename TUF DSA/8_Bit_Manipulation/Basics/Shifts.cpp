#include<bits/stdc++.h>
using namespace std;

int leftshift(int n){
    return n << 1;
}

int rightshift(int n){
    return n >> 1;
}

int main() {
    int x = 5;

    cout << "x << 1 " << leftshift(x) << endl;
    cout << "x >> 1 = " << rightshift(x) << endl;

    return 0;
}
