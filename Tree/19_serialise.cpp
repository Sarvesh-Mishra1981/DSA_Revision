/*
so the actual thing is that when we calculte the node through recursive thing then the tc is O(2^n)
so what we do is that we check that if the tree is complete then we will just do the lh to,power 2 

*/
#include<iostream>
using namespace std;
#include<queue>
#include<stack>
class Node {
public:
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
vector<int> ser;
void serialise(Node* root){
    if(root==NULL){
        ser.push_back(-1);
    }
    ser.push_back(root->val);
    serialise(root->left);
    serialise(root->right);
}
int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    head->left->left->left = new Node(8);
    head->left->left->right = new Node(9);
    head->left->right->left = new Node(10);
    head->left->right->right = new Node(11);
    head->right->left->left = new Node(12);
    head->right->left->right = new Node(13);
    head->right->right->left = new Node(14);
    head->right->right->right = new Node(15);
    serialise(head);
    for(int i=0;i<ser.size();i++){
        cout<<ser[i]<<" ";
    }
    return 0;
}