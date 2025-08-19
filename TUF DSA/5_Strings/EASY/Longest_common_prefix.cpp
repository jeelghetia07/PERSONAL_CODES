#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Longest{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty()) return "";
        int n = strs.size();
        string prefix = strs[0];        // initializing prefix as flower in this case.

        for(int i = 1 ; i < n ; i++){            // runs from the 2nd ele till the last element in the strs becoz it compares the 1st and 2nd ele.
            while(strs[i].find(prefix) != 0){         // checks the prefix if its present in any of the elements till it becomes 0
                prefix= prefix.substr(0, prefix.length()-1);          // every time reduces the string from behind...and sees where the max ans is obtained.
                if(prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    Longest l1;
    string ans = l1.longestCommonPrefix(strs);

    cout << "The longest common prefix is : " << ans << endl;
    return 0;
}