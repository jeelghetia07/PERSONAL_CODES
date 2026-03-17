#include<bits/stdc++.h>
using namespace std;

// void printS(int ind, vector<int> &ds, int curSum , int sum, int arr[], int n){       // to print all subsequences.
//     if(ind == n){
//         if(curSum == sum){
//             for(auto it : ds) cout << it << " ";
//             cout << endl;
//         }
//         return;
//     }
//     ds.push_back(arr[ind]);
//     curSum += arr[ind];
//     printS(ind+1, ds, curSum, sum, arr, n);
//     curSum -= arr[ind];
//     ds.pop_back();
//     printS(ind+1, ds, curSum, sum, arr, n);
// }



// bool printS(int ind, vector<int> &ds, int curSum , int sum, int arr[], int n){   // any 1 subsequence.
//     if(ind == n){
//         // condition satisfied.
//         if(curSum == sum){
//             for(auto it : ds) cout << it << " ";
//             cout << endl;
//             return true;
//         }
//         else return false;
//     }

//     ds.push_back(arr[ind]);
//     curSum += arr[ind];

//     if(printS(ind+1, ds, curSum, sum, arr, n) == true) return true;

//     curSum -= arr[ind];
//     ds.pop_back();

//     if(printS(ind+1, ds, curSum, sum, arr, n) == true) return true;

//     return false;
// }



int_fast16_t printS(int ind, int curSum , int sum, int arr[], int n){       // to count all subsequences.
    if(curSum > sum) return 0;
    if(ind == n){
        if(curSum == sum){
            return 1;
        }
        else return 0;
    }

    curSum += arr[ind];
    int left = printS(ind+1, curSum, sum, arr, n);

    curSum -= arr[ind];
    int right = printS(ind+1, curSum, sum, arr, n);

    return left + right;
}


int main(){                     // the TC is O(2^n)....becoz..for every index...there are 2 choices...pick or not pick.
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    int ans = printS(0, 0, sum, arr, n);
    cout << "The total no. of subsequence is : " << ans << endl;

    return 0;
}