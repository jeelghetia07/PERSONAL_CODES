#include<bits/stdc++.h>
using namespace std;

class FLOOD{
    void dfs(int row,int col, vector<vector<int>>& ans,vector<vector<int>>& img, int newColour, int delrow[], int delcol[], int iniColour){
        ans[row][col] = newColour;    // we colour the node with the new colour.
        int n = img.size();
        int m = img[0].size(); 
        for(int i = 0 ; i < 4 ; i++){      // 4 neighbours.
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            // this checks the validity...
            // if the nr and nc are valid or not...and then if the neighbour has the same initialcolour or not...and if the new pixel is not coloured.....then and then only we colour it .
            if((nr >= 0 && nr < n && nc >= 0 && nc < m) && (img[nr][nc] == iniColour && ans[nr][nc] != newColour)){
                dfs(nr, nc, ans, img, newColour, delrow, delcol, iniColour);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img , int sr, int sc, int newColour){
        int iniColour = img[sr][sc];      // this gets the initial Colour.
        vector<vector<int>> ans = img;
        int delrow[] = {-1, 0, +1, 0};      // this is for finding the 4 neighbours
        int delcol[] = {0, +1, 0, -1};
        dfs(sr,sc,ans,img, newColour, delrow, delcol, iniColour);
        return ans;
    }
};

int main(){
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
    // sr = 1, sc = 1, newColor = 2  	
	FLOOD obj;
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}