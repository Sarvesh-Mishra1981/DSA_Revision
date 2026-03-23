#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
   Node(int x){
    val=x;
    left=NULL;
    right=NULL;
   }
};
void solve(Node* root,int k){
if(root==NULL) return;
if(k==0) {
    cout<<root->val<<" ";
}
else {
    solve(root->left,k-1);
    solve(root->right,k-1);
}
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
    solve(head,3);
    return 0;
}