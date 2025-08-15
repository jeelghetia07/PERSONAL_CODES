#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Two_sum{
public:
    vector<int> gettwosum(vector<int>& arr, int tar){                  // [2,7,11,15]  tar = 9
        int n = arr.size();
        vector<int> ans;
        unordered_map<int,int> mpp;

        for(int i = 0 ; i < n ; i++){
            int a = arr[i];
            int rem = tar-a;
            if(mpp.find(rem) != mpp.end()){
                ans.push_back(mpp[rem]);           // pushes the remainder's index...which is the prevoius element...will push the index of 2..
                ans.push_back(i);                  // pushes this particular element's index...will push the index of 7.
                return ans;
            }
            mpp[a] = i;               // stores the index of all the elements in the map.
        }  
        return ans;      
    }
};

int main(){
    int n;
    cout << "size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int tar;
    cout << "enter the target u want to find : ";
    cin >> tar;

    Two_sum s;
    vector<int> res = s.gettwosum(arr,tar);

    for(int i = 0 ; i < res.size() ; i++){
        cout << res[i] << " ";
    }
}

