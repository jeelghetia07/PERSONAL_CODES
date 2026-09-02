#include<bits/stdc++.h>
using namespace std;

/*      LC = 3568
    You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:

    'S': Starting position of the student
    'L': Litter that must be collected (once collected, the cell becomes empty)
    'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
    'X': Obstacle the student cannot pass through
    '.': Empty space
    You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.

    Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.

    Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.
*/

class Solution {
public:
    /*
        Is the cell valid?
            ↓
        Pay 1 energy
            ↓
        What did I land on?
        ↙       ↓       ↘
        L        R        ./S
        ↓        ↓        ↓
        update    reset    nothing
        mask      energy
        ↘       ↓       ↙
            check visited
                ↓
                push
    */

    bool isValid(int nr, int nc, int n, int m){
        return (nr >= 0 && nr < n && nc >= 0 && nc < m);
    }
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        
        int littersCnt = 0;
        pair<int, int> S_pos;

        vector<vector<int>> litterIndex(n, vector<int>(m, -1));     // this helps in assigning the litter index. so in future in the BFS we can actually know that which index litter have we picked up.

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(classroom[i][j] == 'S') S_pos = {i,j};
                if(classroom[i][j] == 'L'){
                    litterIndex[i][j] = littersCnt;
                    littersCnt++;
                }
            }
        }

        int targetLitters = (1 << littersCnt) - 1;         // if litters = 4, then 10000 - 1  ---> 1111.

        // {row, col, steps, collected_litters(bitmask), energy};
        queue<tuple<int, int, int, int, int>> q;
        q.push({S_pos.first, S_pos.second, 0, 0, energy});

        vector<vector<vector<vector<int>>>> vis(n, 
                                            vector<vector<vector<int>>>(m, 
                                            vector<vector<int>>(energy+1, 
                                            vector<int>(1 << littersCnt, 0))));

        vis[S_pos.first][S_pos.second][energy][0] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // we have used a tuple, and this is the syntax for removing it out.                                       
        while(!q.empty()){
            auto [row, col, currSteps, mask, currEnergy] = q.front();         // here the mask is collected_litters.
            q.pop();

            if(mask == targetLitters) return currSteps;

            if(currEnergy == 0) continue;

            for(int i = 0 ; i < 4 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(isValid(nr, nc, n, m) && (classroom[nr][nc] != 'X')){
                    int newEnergy = currEnergy-1;
                    int newMask = mask;

                    if(classroom[nr][nc] == 'L'){
                        int localLitterIndex = litterIndex[nr][nc];
                        newMask = mask | (1 << localLitterIndex);
                    }
                    else if(classroom[nr][nc] == 'R'){
                        newEnergy = energy;
                    }
                    
                    if(vis[nr][nc][newEnergy][newMask]) continue;

                    vis[nr][nc][newEnergy][newMask] = 1;
                    q.push({nr, nc, currSteps+1, newMask, newEnergy});
                }
            }
        }

        return -1;
    }
};

int main(){
    /*
        Example 1:

        Input: classroom = ["S.", "XL"], energy = 2
        Output: 2
        Explanation:

        The student starts at cell (0, 0) with 2 units of energy.
        Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
        A valid sequence of moves to collect all litter is as follows:
        Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
        Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
        The student collects all the litter using 2 moves. Thus, the output is 2.


        Example 2:

        Input: classroom = ["LS", "RL"], energy = 4
        Output: 3
        Explanation:

        The student starts at cell (0, 1) with 4 units of energy.
        A valid sequence of moves to collect all litter is as follows:
        Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
        Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
        Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
        The student collects all the litter using 3 moves. Thus, the output is 3.


        Example 3:

        Input: classroom = ["L.S", "RXL"], energy = 3
        Output: -1
        Explanation:

        No valid path collects all 'L'.

        

        Constraints:

        1 <= m == classroom.length <= 20
        1 <= n == classroom[i].length <= 20
        classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
        1 <= energy <= 50
        There is exactly one 'S' in the grid.
        There are at most 10 'L' cells in the grid.                 // this helps us think that we can represent them into a bitmask, like 1111111111.
    */

    return 0;
}