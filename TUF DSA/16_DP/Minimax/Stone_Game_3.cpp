#include<bits/stdc++.h>
using namespace std;

/*      LC = 1406
    Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

    Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

    The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

    The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

    Assume Alice and Bob play optimally.

    Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.
*/

class Solution {
public:
    int func(int i, vector<int>& arr, int n, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MIN, sum = 0;

        for(int k = 0 ; k < 3 && i + k < n ; k++){
            sum += arr[i+k];
            ans = max(ans, sum - func(i+k+1, arr, n, dp));
        }

        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = func(0, arr, n, dp);

        if(ans > 0){
            return "Alice";
        }
        else if(ans < 0) return "Bob";
        return "Tie";
    }
};


/*

    // here this means that Bob is trying to minimize Alices's score, but rather this game says, focus on your own score and increase it.

    Now ask yourself:
        If Bob is playing optimally, which option does he choose?

        If Bob only wants to minimize Alice's score, he'd choose

        20 vs 21

        so he'd choose Option A.

        But Bob actually wants to maximize his own score.

        His scores are

        19 vs 100

        so he'll choose Option B.

        See the difference?

        Bob is perfectly happy to let Alice score more points if it means he scores much more.



    class Solution {
    public:
        int func(int i, vector<int>& arr, int n){
            if(i >= n) return 0;

            int take_one = arr[i] + min({func(i+2, arr, n), func(i+3, arr, n), func(i+4, arr, n)});
            int take_two = 0, take_three = 0;
            if(i+1 <= n-1){
                take_two = (arr[i] + arr[i+1]) + min({func(i+3, arr, n), func(i+4, arr, n), func(i+5, arr, n)});
            }
            if(i+2 <= n-1){
                take_three = (arr[i] + arr[i+1] + arr[i+2]) + min({func(i+4, arr, n), func(i+5, arr, n), func(i+6, arr, n)});
            }

            return max({take_one, take_two, take_three});
        }
        string stoneGameIII(vector<int>& arr) {
            int n = arr.size();

            int sum = accumulate(arr.begin(), arr.end(), 0);
            int ans = func(0, arr, n);

            if(ans > sum-ans){
                return "Alice";
            }
            else if(ans < sum-ans) return "Bob";
            return "Tie";
        }
    };

*/

int main(){
    /*
        Try [-1,-2,-3];



        Example 1:

        Input: stoneValue = [1,2,3,7]
        Output: "Bob"
        Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.


        Example 2:

        Input: stoneValue = [1,2,3,-9]
        Output: "Alice"
        Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
        If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
        If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
        Remember that both play optimally so here Alice will choose the scenario that makes her win.


        Example 3:

        Input: stoneValue = [1,2,3,6]
        Output: "Tie"
        Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
        

        Constraints:

        1 <= stoneValue.length <= 5 * 104
        -1000 <= stoneValue[i] <= 1000
    */

    return 0;
}