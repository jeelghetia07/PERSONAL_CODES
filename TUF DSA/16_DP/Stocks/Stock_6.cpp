#include<bits/stdc++.h>
using namespace std;

/*
    We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

    We can buy and sell the stock any number of times.
    In order to sell the stock, we need to first buy it on the same or any previous day.
    We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
    After every transaction, there is a transaction fee (‘fee’) associated with it.
*/ 

int f(int ind, int buy, vector<int>& arr, int n, vector<vector<int>>& dp, int fee){     // we can subtract the fees at buy time also and sell time also....its our choice.
    if(ind == n){
        return 0;
    }
    if(dp[ind][buy] != -1) return dp[ind][buy];
    int profit = 0;

    if(buy){
        profit = max(-arr[ind] + f(ind+1, 0, arr, n, dp, fee),
                        0 + f(ind+1, 1, arr, n, dp, fee));
    }
    else{
        profit = max(arr[ind] - fee + f(ind+1, 1, arr, n, dp, fee),
                        0 + f(ind+1, 0, arr, n, dp, fee));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int>& arr, int fee){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, arr, n, dp, fee);
}

int main(){
    vector<int> arr = {1,3,2,8,4,9};
    int fee = 2;
    cout << "Max profit is : " << maxProfit(arr, fee);
    return 0;
}