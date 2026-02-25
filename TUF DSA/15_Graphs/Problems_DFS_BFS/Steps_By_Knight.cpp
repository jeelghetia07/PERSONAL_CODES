#include<bits/stdc++.h>
using namespace std;

/*
    we can implement this by a simple queue that will take a complexity of O(n2)....but this priority queue takes a complexity of O(n2 logn).
*/

int minStepToReachTarget(vector<int>& knight, vector<int>& target, int n){
    pair<int, int> tar = {target[0], target[1]};
    pair<int, int> init = {knight[0], knight[1]};
    
    vector<vector<int>> vis(n+1, vector<int>(n+1, 0));
    vis[init.first][init.second] = 1;
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {init.first, init.second}});
    
    int delrow[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int delcol[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int steps = it.first;
        int row = it.second.first;
        int col = it.second.second;
        
        if(row == tar.first && col == tar.second) return steps;
        
        for(int i = 0 ; i < 8 ; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            
            if(nr >= 1 && nr < n+1 && nc >= 1 && nc < n+1 && !vis[nr][nc]){
                vis[nr][nc] = 1;
                pq.push({steps + 1, {nr, nc}});
            }
        }
    }
    return -1;
}

int main(){
    // int n = 6;
    // vector<int> knightPo = {4, 5},targetPo = {1, 1};
    int n = 3;
    vector<int> knightPo = {3, 3},targetPo = {1, 1};

    int steps = minStepToReachTarget(knightPo, targetPo, n);
    cout << "The min steps to reach dst is : " << steps;

    return 0;
}