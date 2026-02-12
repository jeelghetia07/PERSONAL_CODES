#include<bits/stdc++.h>
using namespace std;

class DISTANCE{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
            }
        }
        
        vector<vector<int>> dis(n, vector<int>(m));
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            dis[r][c] = d;
            
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, d+1});
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