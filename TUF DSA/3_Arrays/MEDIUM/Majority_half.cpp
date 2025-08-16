#include<iostream>
#include<algorithm>
#include<vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Majority{
public:
    int majorityElement(vector<int>& arr){
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            for(int j = 0 ; j < n ; j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            if(count > (n/2)) return arr[i];
        }
        return 0;
    }
};

int main(){
    vector<int> arr = {1,2,0,1,2,1,2,2,2};
    Majority m;
    int ans = m.majorityElement(arr);
    cout << "the ans is : " << ans << endl;
    return 0;
}