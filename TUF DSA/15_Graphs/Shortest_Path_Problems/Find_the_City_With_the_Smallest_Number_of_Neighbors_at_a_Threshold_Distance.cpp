#include<bits/stdc++.h>
using namespace std;

/*  LC = 1334

    There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

    Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

    Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

*/

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) { // solved using both dijkstra's and floyd warshal.....the floyd is very faster than dijkstra's.
    int cityCnt = n, cityNo = -1;
    
    for(int src = 0 ; src < n ; src++){
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({dist[src], src});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int d = it.first;
            int node = it.second;
            
            if(dist[node] < d) continue;
            
            for(auto v : adj[node]){
                int ver = v.first;
                int edw = v.second;
                
                if(d + edw < dist[ver]){
                    dist[ver] = d + edw;
                    pq.push({dist[ver], ver});
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(dist[i] <= distanceThreshold){
                cnt++;
            }
        }
        
        if(cnt <= cityCnt){
            cityCnt = cnt;
            cityNo = src;
        }
    }
    
    return cityNo;
    
    
    
                    // Floyd Warshall Algorithm
    
    
    // vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    // for(auto &e : edges){
    //     dist[e[0]][e[1]] = e[2];
    //     dist[e[1]][e[0]] = e[2];
    // }
    
    // for(int i = 0 ; i < n ; i++){
    //     dist[i][i] = 0;
    // }
    
    // for(int via = 0 ; via < n ; via++){
    //     for(int i = 0 ; i < n ; i++){
    //         for(int j = 0 ; j < n ; j++){
    //             if(dist[i][via] != INT_MAX && dist[via][j] != INT_MAX){
    //                 dist[i][j] = min(dist[i][via] + dist[via][j], dist[i][j]);
    //             }
    //         }
    //     }
    // }
    
    // int cntCity = n, cityNo = -1;
    
    // for(int i = 0 ; i < n ; i++){
    //     int cnt = 0;
    //     for(int j = 0 ; j < n ; j++){
    //         if(dist[i][j] <= distanceThreshold){
    //             cnt++;
    //         }
    //     }
    //     if(cnt <= cntCity){
    //         cntCity = cnt;
    //         cityNo = i;
    //     }
    // }
    // return cityNo;
}

int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};  // ans = 3;
    int distanceThreshold = 4;

    int ans = findTheCity(n,edges,distanceThreshold);
    cout << "The ans is : " << ans;
}