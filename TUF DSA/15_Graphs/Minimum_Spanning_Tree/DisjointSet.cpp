#include<bits/stdc++.h>
using namespace std;

// The TC is O(4alpha)....which is almost O(constant).

class Disjoint{
    vector<int> rank, parent, size;
public:
    Disjoint(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){      // here i have done the path compression....connected the node to the ultimate parent.
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void uniounByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{       // if both rank are same then we can attach any one with the other.
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void uniounBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{   // if its equal or greater than...we still attach it...then why to write the else if then else..so we are combining both.
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    Disjoint ds(7);

            // this is done by rank;

    // ds.uniounByRank(1,2);
    // ds.uniounByRank(2,3);
    // ds.uniounByRank(4,5);
    // ds.uniounByRank(6,7);
    // ds.uniounByRank(5,6);

    // // if 3 and 7 belong to the same component or nor...lets check;
    // if(ds.findUParent(3) == ds.findUParent(7)){
    //     cout << "Same" << endl;
    // }
    // else{
    //     cout << "Not same" << endl;
    // }

    // ds.uniounByRank(3,7);

    // if(ds.findUParent(3) == ds.findUParent(7)){
    //     cout << "Same" << endl;
    // }
    // else{
    //     cout << "Not same" << endl;
    // }


                // done by size.....this is more intutive.

    ds.uniounBySize(1,2);
    ds.uniounBySize(2,3);
    ds.uniounBySize(4,5);
    ds.uniounBySize(6,7);
    ds.uniounBySize(5,6);

    // if 3 and 7 belong to the same component or nor...lets check;
    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same" << endl;
    }
    else{
        cout << "Not same" << endl;
    }

    ds.uniounBySize(3,7);

    if(ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same" << endl;
    }
    else{
        cout << "Not same" << endl;
    }

    return 0;
}