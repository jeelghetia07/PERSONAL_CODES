#include<bits/stdc++.h>
using namespace std;

// class CYCLE{
//     bool detect(int src, vector<int> adj[], int vis[]){       // i have passed the source node...adj list, visited array.
//         vis[src] = 1;
//         queue<pair<int, int>> q;
//         q.push({src, -1});     // the initial node has the parent -1...it comes from nowhere.

//         while(!q.empty()){
//             int node = q.front().first;
//             int parent = q.front().second;
//             q.pop();

//             for(auto adjNode : adj[node]){
//                 if(!vis[adjNode]){
//                     vis[adjNode] = 1;
//                     q.push({adjNode, node});
//                 }
//                 else if(parent != adjNode){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// public:
//     bool isCycle(int V, vector<int> adj[]){
//         int vis[V] = {0};
//         for(int i = 0 ; i < V ; i++){
//             if(!vis[i]){
//                 if(detect(i, adj, vis)) return true;
//             }
//         }
//         return false;
//     }
// };


class CYCLE{
    bool dfs(int node, int parent, int vis[], vector<int> adj[]){
        vis[node] = 1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, node, vis, adj) == true) return true;
            }
            else if(adjNode != parent){         // if anyone returns the true.....no need to check any further possibilites becoz...we have already found a cycle in the graph.
                return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]){
        int vis[V] = {0};
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj) == true) return true;
            }
        }
        return false;
    }
};


int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    // vector<int> adj[4] = {{}, {2,3}, {1, 3}, {1,2}};
    CYCLE obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}