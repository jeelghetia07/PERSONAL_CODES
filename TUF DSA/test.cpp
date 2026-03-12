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

        int ans = 0;

        for(int i = 1 ; i < n ; i++){
            if(arr[i] + arr[i-1] == 7 || arr[i] == arr[i-1]) ans++, i++;
        }
        cout << ans << endl;
    }

    return 0;
}