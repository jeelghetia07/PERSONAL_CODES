#include<bits/stdc++.h>
using namespace std;

/*      LC = 1042
    You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

    All gardens have at most 3 paths coming into or leaving it.

    Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

    Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists
*/

// its a mixture of graph and greedy.

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<vector<int>> adj(n+1);

    for(auto &e : paths){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> ans;
    vector<int> vis(n+1, 0);

    for(int node = 1 ; node <= n ; node++){
        if(!vis[node]){
            bool used[5] = {false};

            for(auto neig : adj[node]){
                int c = vis[neig];
                used[c] = true;     // we have used this colour.
            }

            for(int c = 1 ; c <= 4 ; c++){
                if(used[c] == false){
                    vis[node] = c;
                    ans.push_back(vis[node]);
                    break;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n = 3;
    vector<vector<int>> paths = {{1,2},{2,3},{3,1}};
    // ans = [1,2,3];
}