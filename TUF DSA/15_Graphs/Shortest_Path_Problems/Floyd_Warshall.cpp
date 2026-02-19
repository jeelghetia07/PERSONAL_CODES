#include<bits/stdc++.h>
using namespace std;

/*
    You are given a weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
    The graph may contain negative edge weights, but it does not contain any negative weight cycles.

    Your task is to find the shortest distance between every pair of nodes i and j in the graph.

    Note: Modify the distances for every pair in place
*/

void floydWarshall(vector<vector<int>> &dist){    
    int n = dist.size();
    for(int via = 0 ; via < n ; via++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(dist[i][via] != INT_MAX && dist[via][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], (dist[i][via]+dist[via][j]));
            }
        }
    }

    for(int i = 0 ; i < n ; i++){       // to mark unreachable states with -1.
        for(int j = 0 ; j < n ; j++){
            if(dist[i][j] == INT_MAX){
                dist[i][j] = -1;
            }
        }
    }

    /*
        if in the interview its asked that how to detect negative cycles the i can do this
        for(int i = 0 ; i < n ; i++){
            if(dist[i][i] < 0){
                cout << 
            }
        }
    */
}

int main(){
    vector<vector<int>> dist = {{0, 4, INT_MAX, 5, INT_MAX}, {INT_MAX, 0, 1, INT_MAX, 6}, {2, INT_MAX, 0, 3, INT_MAX}, {INT_MAX, INT_MAX, 1, 0, 2}, {1, INT_MAX, INT_MAX, 4, 0}};
    int n = dist.size();

    floydWarshall(dist);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}