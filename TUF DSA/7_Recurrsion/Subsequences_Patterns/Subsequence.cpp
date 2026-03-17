#include<bits/stdc++.h>
using namespace std;

void subsQ(int ind, vector<int> ds, int arr[], int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " ";
        }
    }
    ds.push_back(arr[ind]);
    subsQ(ind+1, ds, arr, n);
    ds.pop_back();
}

int main(){
    int arr[] = {3,1,2};
    int n = 3;

    vector<int> ds;
    subsQ(0, ds, arr, n);
    return 0;
}