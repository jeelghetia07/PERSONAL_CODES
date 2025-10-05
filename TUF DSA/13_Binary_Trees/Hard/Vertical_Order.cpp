#include<iostream>
#include<set>
#include<queue>
#include<map>
#include <vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode(int d){
        data = d;
    }
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class VERTICAL{
public:
    vector<vector<int>> verticalTraversals(TreeNode* root){
        map<int, map<int, multiset<int>>> nodes;     // this will store the nodes in the order and based on the vertical(cols) and level(rows).     // here the multiset can carry multiple values..and it automatically sorts the values.
        queue<pair<TreeNode* , pair<int,int>>> todo;    // (node, (vertical, level)).
        todo.push({root, {0,0}});

        while(!todo.empty()){         // this while loop will complete all the travesal and store it in the final map.
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;   // this will give us the node we pushed into the stack.
            int x = p.second.first;    // this will give the vertical {node, {"vertical", level}}.
            int y = p.second.second;   // this will give the level {node, {vertical, "level"}}.

            nodes[x][y].insert(temp->data);    // inserted the node val into the map at the 'x vertical' and the 'y level'.

            if(temp->left) todo.push({temp->left, {x-1, y+1}});
            if(temp->right) todo.push({temp->right, {x+1, y+1}});    // if there is a right node... then it will be added into the queue for the next process.
        }

        vector<vector<int>> ans;
        for(auto p : nodes){     // this will start from how the map is stored...its like map<int, map<int, set<int>>>...then it will start ascendingly for "1st int = x"..
            vector<int> col;
            for(auto q : p.second){      // this loop is for the inner map<int, set<int>>     "int = y".
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

void printResult(const vector<vector<int>>& result){
    for(auto level : result){
        for(auto node : level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    VERTICAL vt;
    vector<vector<int>> ans = vt.verticalTraversals(root);

    cout << "Vertical Travesal : " << endl;
    printResult(ans);
    return 0;
}