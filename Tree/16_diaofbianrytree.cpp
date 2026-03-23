#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node* left,*right;
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
int res=0;
int solve(Node* root){
    if(root==NULL) return 0;
    int lh=solve(root->left);
    int rh=solve(root->right);
    res=max(res,lh+rh+1);
    return 1+max(lh,rh);
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
    solve(head);
    cout<<res<<endl;
    return 0;
}
