#include<bits/stdc++.h>
using namespace std;


                // MEMOZIATION

// int func(int ind1, int ind2, int cnt, string& s1, string& s2, int n, vector<vector<vector<int>>>& dp) {
//     if(ind1 < 0 || ind2 < 0)
//         return cnt;
//     if(dp[ind1][ind2][cnt] != -1) return dp[ind1][ind2][cnt];
//     int ans = cnt;

//     if(s1[ind1] == s2[ind2]) {
//         int len = cnt+1;

//         int start1 = ind1 - len + 1;         
//         // start1 shows the index in s1 where the palindrome substring starts.
//         // ind1 = ending index of the substring, len = length of the substring.
//         int start2 = n - 1 - ind2;          // start2 shows the index in s1 that corresponds to ind2 in the reversed string (mirror index)

//         if(start1 == start2)
//             ans = max(ans, len);

//         ans = max(ans, func(ind1-1, ind2-1, len, s1, s2, n, dp));
//     }

//     ans = max(ans, func(ind1-1, ind2, 0, s1, s2, n, dp));
//     ans = max(ans, func(ind1, ind2-1, 0, s1, s2, n, dp));

//     return dp[ind1][ind2][cnt] = ans;
// }

// int LongestPali(string& s1) {
//     string s2 = s1;
//     reverse(s2.begin(), s2.end());
//     int n = s1.size();

//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

//     return func(n-1, n-1, 0, s1, s2, n, dp);
// }




                // TABULATION.....3D dp

// int LongestPali(string& s1) {
//     string s2 = s1;
//     reverse(s2.begin(), s2.end());
//     int n = s1.size();
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));

//     int ans = 1;

//     for(int ind1 = 1 ; ind1 <= n ; ind1++){
//         for(int ind2 = 1 ; ind2 <= n ; ind2++){
//             for(int cnt = 0 ; cnt <= n ; cnt++){

//                 int curr = dp[ind1][ind2][cnt];

//                 if(s1[ind1-1] == s2[ind2-1]) {
//                     int len = cnt+1;

//                     int start1 = ind1 - len + 1;         
//                     // start1 shows the index in s1 where the palindrome substring starts.
//                     // ind1 = ending index of the substring, len = length of the substring.
//                     int start2 = n - ind2 + 1;          // start2 shows the index in s1 that corresponds to ind2 in the reversed string (mirror index)

//                     if(start1 == start2)
//                         curr = max(curr, len);

//                     if(ind1 > 1 && ind2 > 1 && len <= n)
//                         curr = max(curr, dp[ind1-1][ind2-1][len]);
//                 }

//                 if(ind1 > 1)
//                     curr = max(curr, dp[ind1-1][ind2][0]);
//                 if(ind2 > 1)
//                     curr = max(curr, dp[ind1][ind2-1][0]);

//                 dp[ind1][ind2][cnt] = curr;

//                 ans = max(ans, curr);
//             }
//         }
//     }
//     return ans;;
// }



                // TABULATION APPROACH 2D DP

int LongestPali(string& s){
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int ans = 1;

    for(int i = 0 ; i < n ; i++){
        dp[i][i] = true;            // the element itself is palindirome....in aba...a == a and b is plaindrome.
    }

    for(int len = 2 ; len <= n ; len++){
        for(int i = 0 ; i+len-1 < n ; i++){     // the checking of ele should be 01 12 23 34...so length is 2 and index checking is from i = 0  to j = 1.
            int j = i+len-1;

            if(s[i] == s[j]){
                if(len == 2 || dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans = max(ans, len);
                }
            }
        }
    }
    return ans;
}


int main() {
    string s = "babad";
    cout << LongestPali(s);
}
