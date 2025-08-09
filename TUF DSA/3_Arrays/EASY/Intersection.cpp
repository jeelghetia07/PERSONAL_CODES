#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

class Intersection{
public:
    vector<int> intersec(vector<int>& arr1 , vector<int>& arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_set<int> st, result;
        vector<int> ans;
        for(int i : arr1){
            st.insert(i);
        }
        
        for(int i : arr2){
            if(st.find(i) != st.end()){
                result.insert(i);
            }
        }

        for(int i : result){
            ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    int n1,n2;
    cout << "enter size of the arrays : " << endl;
    cin>> n1;
    cin >> n2;
    vector<int> nums1(n1),nums2(n2);
    cout << "enter elements for array 1 : ";
    for(int i = 0 ; i < n1 ; i++){
        cin >> nums1[i];
    }
    cout << "enter elements for array 2 : ";
    for(int i = 0 ; i < n2 ; i++){
        cin >> nums2[i];
    }
    Intersection I;
    vector<int> res = I.intersec(nums1,nums2);
    cout << "Intersection elemetns are : ";
    for(int i = 0 ; i < res.size() ; i++){
        cout << res[i] << " ";
    }
    return 0;
}