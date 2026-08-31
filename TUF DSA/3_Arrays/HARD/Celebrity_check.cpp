#include<bits/stdc++.h>
using namespace std;

/*      GFG
    A celebrity is a "person who is known to all but does not know anyone" at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

    Note: Follow 0-based indexing
*/

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {       // here the main twist is that we have to check 2 conditions.
                                                    // 1). A -> B (A knows B, hence A is useless) , 2). A -> B (A doesnt know B, B is useless)
        int cand = 0;
        int n = mat.size();
        for(int i = 1 ; i < n ; i++){       // this will find the celebrity candidate.
            if(mat[cand][i] == 1 && cand != i){
                cand = i;
            }
        }
        
        for(int i = 0 ; i < n ; i++){       // for verifying that if the celebrity does not know anyone else.
            if(mat[cand][i] == 1 && i != cand) return -1;       // here 1 means that cand -> i, hence this proves that cele knows someone, but thats practically impossible.
        }
        
        for(int i = 0 ; i < n ; i++){       // for verifying that everyone knows the celebrity.
            if(mat[i][cand] == 0 && i != cand){         // 0 means that i -> cand, i doesnt know the celebrity.
                return -1;
            }
        }
        
        return cand;
    }

    /*
        int celebrity(vector<vector<int>>& mat) {
            int cele = 0;
            int n = mat.size();
            int m = mat[0].size();
            
            int top = 0, down = n-1;
            
            while(top < down){
                if(mat[top][down] == 1) top++;
                else down--;
            }
                
            cele = top;
            
            for(int i = 0 ; i < n ; i++){
                if(i == cele) continue;
                if(mat[cele][i] == 1 || mat[i][cele] == 0) return -1;
            }
            
            return cele;
        }
    */
};

int main(){
    /*
        Input: mat[][] =[[1, 1, 0],
                        [0, 1, 0],
                        [0, 1, 1]]
        Output: 1
        Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.


        Input: mat[][] = [[1, 1], 
                        [1, 1]]
        Output: -1
        Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.

        
        Input: mat[][] = [[1]]
        Output: 0
    */

    return 0;
}