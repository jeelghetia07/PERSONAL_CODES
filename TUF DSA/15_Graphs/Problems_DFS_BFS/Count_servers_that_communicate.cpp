#include<bits/stdc++.h>
using namespace std;

/*      LC = 1267
    You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

    Return the number of servers that communicate with any other server.
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int canComminicate = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    // this means that, at that (i,j)th point, if i see more servers in that row[i] or col[j], means that, (i,j)th server, will definitely comminicate with the rest, so we simply add the (i,j) server to the ans.
                    if(row[i] > 1 || col[j] > 1) canComminicate++;
                }
            }
        }

        return canComminicate;
    }
};

int main(){
    /*
        Example 1:

        Input: grid = [[1,0],[0,1]]
        Output: 0
        Explanation: No servers can communicate with others.


        Example 2:

        Input: grid = [[1,0],[1,1]]
        Output: 3
        Explanation: All three servers can communicate with at least one other server.
        
        Example 3:

        Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
        Output: 4
        Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
        

        Constraints:

        m == grid.length
        n == grid[i].length
        1 <= m <= 250
        1 <= n <= 250
        grid[i][j] == 0 or 1
    */

    return 0;
}