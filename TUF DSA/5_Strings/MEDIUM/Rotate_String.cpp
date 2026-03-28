#include<bits/stdc++.h>
using namespace std;

/*      LC = 796
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

    A shift on s consists of moving the leftmost character of s to the rightmost position.

    For example, if s = "abcde", then it will be "bcdea" after one shift.
*/

class Solution {
public:
    // bool rotateString(string s, string goal){
    //     int n = s.size(), m = goal.size();

    //     if(n != m) return false;

    //     string str = s + s;     // doubling th string.
        
    //     return str.find(goal) != string::npos;      // this npos represents a very large number to represent an invalid pos.
    // }

    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();

        if(n != m) return false;

        for(int i = 0 ; i < n ; i++){       // here the rotated is doing the left shift operation to check all possibilites but his takes O(n@) time....one for iterating all char and other for string matching.
            string rotated = s.substr(i) + s.substr(0, i);      // for (0,0) it means.....0 to -1.
            if(rotated == goal) return true;
        }
        return false;
    }
};

int main(){


    return 0;
}