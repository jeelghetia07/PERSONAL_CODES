#include<bits/stdc++.h>
using namespace std;

class DISTANCE{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));    // created the visited matrix.
        vector<vector<int>> dis(n, vector<int>(m,0));        // the distance matrix.
        queue<pair<pair<int,int>, int>> q;             // this will store {{row, col}, steps} ...the steps are to the nearest 1.

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){             // we first start from the 1's in the grid....becoz...from 1 the nearest 0 will be at 1 step (vice versa)..
                    q.push({{i,j}, 0});          // and the 1 itself will be the nearest to itself so it is at dis 0;
                    vis[i][j] = 1;         // we then marked the starting node as 1.
                }
                else{
                    vis[i][j] = 0;          // all other as 0;
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};          // to check all 4 sides.
        int delcol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dis[row][col] = steps;                  // as soon as we get the row col and steps.....mark it in the distance matrix .

            for(int i = 0 ; i < 4 ; i++){           // then check the 4 dir nodes and push to the queue.
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){       // to check if its valid...or not....and if the nrow and ncol node is 0...then only we have to go further.
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return dis;
    }
};

int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,0,0}
    };
	
	DISTANCE obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}