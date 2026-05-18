#include<bits/stdc++.h>
using namespace std;

/*      LC = 3464
    You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.

    You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.

    You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.

    Return the maximum possible minimum Manhattan distance between the selected k points.

    The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
*/

class Solution {
public:
    using ll = long long;

    vector<ll> pos;

    int maxDistance(int side, vector<vector<int>>& points, int k) {

        // Step 1: Convert 2D → 1D
        for (auto &p : points) {
            int x = p[0], y = p[1];

            if (x == 0) pos.push_back(y);                      // left edge
            else if (y == side) pos.push_back(side + x);       // top edge
            else if (x == side) pos.push_back(3LL * side - y); // right edge
            else pos.push_back(4LL * side - x);                // bottom edge
        }

        sort(pos.begin(), pos.end());

        // Step 2: Binary Search on answer
        int low = 1, high = side;

        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (can(mid, side, k)) {
                low = mid;       // try bigger
            } else {
                high = mid - 1;  // go smaller
            }
        }

        return low;
    }

    bool can(int D, int side, int k) {

        int n = pos.size();

        // Try each starting point
        for (int i = 0; i < n; i++) {

            ll start = pos[i];
            ll limit = start + 4LL * side - D;  // circular limit

            ll last = start;
            int count = 1;

            // Try picking next points
            for (int step = 0; step < k - 1; step++) {

                // Find next point ≥ last + D
                auto it = lower_bound(pos.begin(), pos.end(), last + D);

                if (it == pos.end() || *it > limit) {
                    count = 0;
                    break;
                }

                last = *it;
                count++;
            }

            if (count >= k) return true;
        }

        return false;
    }
};

int main(){


    return 0;
}