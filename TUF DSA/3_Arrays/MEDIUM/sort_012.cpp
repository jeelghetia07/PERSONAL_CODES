#include<iostream>
#include<algorithm>
#include<vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Sort{
public:
    void sortans(vector<int>& arr){        // other option is that just count the number of 0 1 2 ...and just run 3 loops and asgn the values.
        int n = arr.size();
        int low = 0, mid = 0, high = n-1;

        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low], arr[mid]);
                low++ , mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main(){
    vector<int> arr = {2,0,2,1,1,0};
    int n = arr.size();

    Sort s;
    s.sortans(arr);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}