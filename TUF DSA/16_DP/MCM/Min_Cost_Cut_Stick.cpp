// Min_Cost_Cut_Stick.cpp
#include<bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<int>& cuts){
    if(i > j) return 0;
    int mini = INT_MAX;

    for(int ind = i; ind <= j ; ind++){
       int cost = cuts[j+1] - cuts[i-1] + func(i, ind-1, cuts) + func(ind+1, j, cuts); 
       mini = min(mini, cost);
    }
    return mini;
}

int cost(int n, int c, vector<int>& cuts){
    cuts.push_back(n);              // at last.
    cuts.insert(cuts.begin(),0);     // inserts the element at the front.
    sort(cuts.begin(), cuts.end());

    return func(1, c, cuts);
}

int main(){
    vector<int> cuts = {1,3,4,5};       // if given not sorted then firstly sort the complete array and then perform the steps.
    cout << "the minimum cost is : " << cost(7, cuts.size(), cuts);
    return 0;
}