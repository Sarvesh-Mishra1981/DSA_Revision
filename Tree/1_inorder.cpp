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
void solve(Node* root){
    if(root!=NULL){
        solve(root->left);
        cout<<root->val<<" ";
        solve(root->right);
    }
}
int main(){
     Node* head=new Node(10);
    head->left=new Node(20);
    head->right=new Node(30);
    solve(head);
}