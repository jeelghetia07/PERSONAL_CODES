#include<bits/stdc++.h>
using namespace std;

/*
    There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

    You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto &e : flights){
        adj[e[0]].push_back({e[1], e[2]});
    }

    vector<int> dis(n, 1e9);
    queue<pair<int, pair<int, int>>> q;     // {stops, node, cost};
    q.push({0, {src, 0}});

    dis[src] = 0;

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k) continue;
        
        for(auto v : adj[node]){
            int neighbour = v.first;
            int edw = v.second;

            if(cost + edw < dis[neighbour] && stops <= k){
                dis[neighbour] = cost + edw;
                q.push({stops+1, {neighbour, dis[neighbour]}});
            }
        }
    }

    if(dis[dst] == 1e9) return -1;
    return dis[dst];
}

int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, k = 1;

    cout << "The min cost is : " << findCheapestPrice(flights.size(), flights, src, dst, k);
    return 0;
}