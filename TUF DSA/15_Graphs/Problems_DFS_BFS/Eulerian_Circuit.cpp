#include<bits/stdc++.h>
using namespace std;

/*      
    circuit visits every edge exactly one time. and reaches the start pos at the end.
*/

bool EulerianCircuit(int n, vector<vector<int>>& edges){
    vector<vector<int>> adj(n);

    for(auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    int start = -1;

    for(int i = 0 ; i < n ; i++){
        if(adj[i].size() > 0){
            start = i;
            break;
        }
    }

    if(start == -1) return true;     // if no vertices....then its a eulerian circuit.

    vector<int> vis(n, 0);

    stack<int> st;
    vis[start] = 1;
    st.push(start);
    
    while(!st.empty()){
        int node = st.top();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                st.push(it);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(adj[i].size() > 0 & !vis[i]) return false;
    }

    for(int i = 0 ; i < n ; i++){
        if(adj[i].size() % 2 != 0) return false; 
    }
    return true;
}

int main(){
    int n = 3;
    vector<vector<int>> edges = {{0,1},{0,2}};

    

    return 0;
}