#include<iostream>
using namespace std;

class Node{
public:
    Node(int d){
        int data;
    }
    Node* left = nullptr;
    Node* right = nullptr;
};

class Height{
public:
    int maxHeight(Node* root){
        if(root == NULL) return 0;

        int LHS = maxHeight(root->left);
        int RHS = maxHeight(root->right);

        return 1 + max(LHS, RHS);
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Height h;
    int height = h.maxHeight(root);
    cout << "The height of the tree is : " << height << endl;
    return 0;
}