#include<bits/stdc++.h>
using namespace std;

class PROVINCIES{
    void DFS(int node, vector<int> adjLs[], int vis[]){
        vis[node] = 1;

        for(auto it : adjLs[node]){
            if(!vis[it]){
                DFS(it, adjLs, vis);
            }
        }
    }
public:
    int numberOfprovincies(vector<vector<int>> adj, int V){
        vector<int> adjList[V];

        for(int i = 0 ; i < V ; i++){       // here we are creating the adjecency list.
            for(int j = 0 ; j < V ; j++){
                if(adj[i][j] == 1 && i != j){        // i != j is for removing the self loops
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};   // the visited matrix;
        int count = 0;    

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                count++;
                DFS(i, adjList, vis);
            }
        }

        return count;
    }
};

int main(){
    vector<vector<int>> adj = {
        {1,0,1},
        {0,1,0},
        {1,0,1}
    };

    int V = 3;
    PROVINCIES obj;

    cout << obj.numberOfprovincies(adj,V) << endl;

    return 0;
}