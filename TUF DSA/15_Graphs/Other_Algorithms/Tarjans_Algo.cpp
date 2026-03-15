#include<bits/stdc++.h>
using namespace std;

/*      LC = 1192
    There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

    A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

    Return all critical connections in the network in any order
*/

int timer = 1;      // this is the starting time of the insertions of the first node.

void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& timeofinsertion, vector<int>& lowesttime, vector<vector<int>>& ans){
    vis[node] = 1;
    timeofinsertion[node] = lowesttime[node] = timer;
    timer++;

    for(auto it : adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, vis, adj, timeofinsertion, lowesttime, ans);
            lowesttime[node] = min(lowesttime[node], lowesttime[it]);
            // check node------it.....is there a bridge
            if(lowesttime[it] > timeofinsertion[node]){
                ans.push_back({node, it});
            }
        }
        else{
            lowesttime[node] = min(lowesttime[node], lowesttime[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
    vector<vector<int>> adj(n+1);

    for(auto &e : connections){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> timeofinsertion(n+1), lowesttime(n+1), vis(n+1, 0);
    vector<vector<int>> ans;

    dfs(1, -1, vis, adj, timeofinsertion, lowesttime, ans);
    return ans;
}

int main(){
    int n = 12;
    vector<vector<int>> connections = {{1,2},{2,3},{3,4},{1,4},{4,5},{5,6},{6,7},{7,8},{8,9},{6,9},{8,10},{10,11},{11,12},{10,12}};

    // int n = 4;
    // vector<vector<int>> connections = {{1,2},{2,3},{1,3},{2,4}};

    vector<vector<int>> ans = criticalConnections(n, connections);

    for(auto it : ans){
        cout << "[";
        for(auto e : it){
            cout << e << " ";
        }
        cout << "]";
    }

    return 0;
}