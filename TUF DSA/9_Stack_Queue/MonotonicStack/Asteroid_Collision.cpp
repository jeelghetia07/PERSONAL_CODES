#include<bits/stdc++.h>
using namespace std;

/*      LC = 735
    We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

    For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

    Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<bool> alive(n, true);

        stack<int> st;

        for(int i = 0 ; i < n ; i++){
            if(asteroids[i] > 0) st.push(i);
            else{
                while(!st.empty()){
                    int top = st.top();
                    if(asteroids[top] < abs(asteroids[i])){
                        alive[top] = false;
                        st.pop();
                    }
                    else if(asteroids[top] > abs(asteroids[i])){
                        alive[i] = false;
                        break;
                    }
                    else{
                        alive[top] = false;
                        alive[i] = false;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            if(alive[i]) ans.push_back(asteroids[i]);
        }

        return ans;
    }
};

int main(){
    /*
        Example 1:

        Input: asteroids = [5,10,-5]
        Output: [5,10]
        Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.


        Example 2:

        Input: asteroids = [8,-8]
        Output: []
        Explanation: The 8 and -8 collide exploding each other.


        Example 3:

        Input: asteroids = [10,2,-5]
        Output: [10]
        Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

        
        Example 4:

        Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
        Output: [-6,2,4]
        Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.
    */

    return 0;
}