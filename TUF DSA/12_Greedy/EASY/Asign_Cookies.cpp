#include<bits/stdc++.h>
using namespace std;

int findNumber(vector<int>& s, vector<int> &greed){
    int n = s.size();
    int m= greed.size();
    int l = 0, r = 0;

    while(l < n && r < m){
        if(s[l] >= greed[r]) r= r+1;
        l = l+1;
    }
    return r;
}

int main(){
    vector<int> s = {1,1,2,2,3,4};
    vector<int> greed = {1,3,3,4,5};

    cout << "The children assigned cookies are : " << findNumber(s, greed);
    return 0;
}