#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &coins, int V){
    vector<int> ans;
    int n = coins.size();

    for(int i = n-1 ; i >= 0 ; i--){
        while(V >= coins[i]){
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    int mini = ans.size();
    return mini;
}

int main(){
    vector<int> arr = {1,2,5,10,20,50,100,500,1000};   // here greedy will work becoz the sum of anny two coins doesnt exceed the next one.....if it exceeds we have to use DP.
    int V = 49;

    cout << "The minimum number of coins are : " << findMin(arr, V);
    return 0;
}