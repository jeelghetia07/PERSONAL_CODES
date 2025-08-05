#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Check{
public:
    bool check_sort(vector<int>& arr){
        int n = arr.size();
        for(int i = 0 ; i < n-1 ; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    Check c;
    cout << c.check_sort(arr) << endl;
    return 0;
}