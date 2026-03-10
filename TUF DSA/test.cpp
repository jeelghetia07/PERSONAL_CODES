#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin >> testCases;

    while(testCases--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int curr = 1;
        int best = 1;

        for(int i = 1 ; i < n ; i++){
            if(arr[i] == arr[i-1]+1){
                curr++;
            }
            else if(arr[i] != arr[i-1]){
                curr = 1;
            }
            best = max(curr, best);
        }
        cout << best << endl;
    }
    return 0;
}