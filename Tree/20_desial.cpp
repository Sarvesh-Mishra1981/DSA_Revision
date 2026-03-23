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
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int empty=-1;
int in=0;
Node* deserialize(vector<int>& a){
   if(a.size()==0) return NULL;
   int val=a[in++];
   if(val==-1) return NULL;
   Node* root=new Node(val);
   root->left=deserialize(a);
   root->right=deserialize(a);
   return root; 
}
int main() {
    vector<int> a{1,2,4,8 ,-1 ,-1 ,9 ,-1, -1 ,5 ,10, -1, -1, 11, -1, -1, 3 ,6 ,12, -1, -1, 13, -1, -1, 7, -1, 15, -1 ,-1};
    Node* root= deserialize(a);
    preorder(root);
    return 0;
}