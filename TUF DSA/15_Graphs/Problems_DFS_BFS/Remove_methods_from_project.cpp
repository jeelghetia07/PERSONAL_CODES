#include<bits/stdc++.h>
using namespace std;

/*      LC = 3310
    You are maintaining a project that has n methods numbered from 0 to n - 1.

    You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

    There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

    A group of methods can only be removed if no method outside the group invokes any methods within it.

    Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.
*/

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& suspicious){
        suspicious[node] = 1;

        for(auto it : adj[node]){
            if(!suspicious[it]){
                dfs(it, adj, suspicious);
            }
        }

        return ;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // filled the initial array.
        vector<int> res(n);
        iota(res.begin(), res.end(), 0);

        vector<vector<int>> adj(n);

        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        // this will find the suspicious methods.
        vector<int> suspicious(n, 0);

        vector<int> ans;
        bool ok = true;

        // every suspicious node will be marked.
        dfs(k, adj, suspicious);

        for(int i = 0 ; i < n ; i++){
            if(suspicious[i]) continue;

            for(auto it : adj[i]){
                if(suspicious[it]){
                    ok = false;
                    break;
                }
            }

            if(ok) ans.push_back(i);
        }

        if(!ok) return res;
        return ans;
    }
};


/*
class Solution {
    // all danger nodes are removable.
    bool ok = true;
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, int n, unordered_set<int> &st){
        vis[node] = 1;
        st.insert(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, n, st);
            }
        }

        return;
    }

    void DFS_Normal(int node, vector<int> &vis, vector<vector<int>> &adj, int n, unordered_set<int> &st, unordered_set<int> &finalSt){
        vis[node] = 1;
        if(!ok) return;

        if(adj[node].size() == 0) finalSt.insert(node);
        for(auto it : adj[node]){
            // we found that suspicious node.
            // node ----> it(danger)
            if(st.find(it) != st.end()){
                ok = false;         // we cany remove the danger nodes now so not ok.
                break;
            }
            else{
                finalSt.insert(node);
            }
        }

        return;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // filled the initial array.
        vector<int> res(n);
        iota(res.begin(), res.end(), 0);

        vector<vector<int>> adj(n);

        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(n, 0);
        unordered_set<int> st, finalSet;

        // mark all the suspiciuos nodes.
        dfs(k, vis, adj, n, st);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                DFS_Normal(i, vis, adj, n, st, finalSet);
            }
        }

        vector<int> ans;
        for(auto it : finalSet){
            ans.push_back(it);
        }

        // we cant remove the danger nodes.
        if(!ok) return res;
        return ans;
    }
};
*/

int main(){
    /*
        Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
        Output: [0,1,2,3]
        Explanation:
        Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

        Example 2:

        Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]
        Output: [3,4]

        Explanation:
        Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

        Example 3:        
        Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]
        Output: []
        Explanation:
        All methods are suspicious. We can remove them.

        

        Constraints:

        1 <= n <= 105
        0 <= k <= n - 1
        0 <= invocations.length <= 2 * 105
        invocations[i] == [ai, bi]
    */

    return 0;
}