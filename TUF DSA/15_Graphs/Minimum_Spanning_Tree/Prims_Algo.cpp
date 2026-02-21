#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(V);
    
    for(auto &e : edges){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }
    
    vector<int> vis(V, 0);
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    pq.push({0, {0, -1}});      // here im inserting the parent becoz in some questions its asked to return the edges.
    
    int sum = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int dis = it.first;
        int node = it.second.first;
        
        if(vis[node]) continue;
        
        vis[node] = 1;
        sum += dis;
        
        for(auto v : adj[node]){
            int ver = v.first;
            int d = v.second;
            
            if(!vis[ver]){
                pq.push({d, {ver, node}});
            }
        }
    }
    return sum;
}

int main(){
    int V = 3, E = 3;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};

    int sum = spanningTree(V, edges);
    cout << "The minimum sum is : " << sum << endl;

    return 0;
}