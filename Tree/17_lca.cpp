#include<iostream>
using namespace std;
#include<queue>
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
Node* solve(Node* root,int num1,int num2){
    if(root==NULL) return NULL;
    if(root->val==num1 || root->val==num2){
        return root;
    }
    Node* lca1=solve(root->left,num1,num2);
    Node* lca2=solve(root->right,num1,num2);
    if(lca1!=NULL && lca2!=NULL) return root;
    else if(lca1!=NULL) return lca1;
    else return lca2;
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
    cout<<solve(head,4,12);
    return 0;
}