#include<iostream>
#include<algorithm>
#include<vector>
#include <climits>
using namespace std;

class Container{
public:
    int maxArea(vector<int>& arr){
        int n = arr.size();
        int left = 0, right = n-1;
        int maxi = INT_MIN , area, mini;
        while(left < right){
            int length = right-left;
            mini = min(arr[left], arr[right]);
            area = length * mini;
            maxi = max(maxi ,area);
            if(arr[left] < arr[right]) left++;
            else right--;
        }
        return maxi;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Container c;
    int ans = c.maxArea(height);
    cout << "The max water stored in the container has area of : " << ans <<  endl;
}