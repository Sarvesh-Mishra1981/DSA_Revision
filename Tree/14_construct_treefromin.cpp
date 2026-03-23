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
int preidx=0;
Node* solve(vector<int>& inorder,vector<int>& preorder,int st,int end){
    if(st>end) return NULL;
    Node* root=new Node(preorder[preidx++]);
    int mid=0;
    for(int i=st;i<=end;i++){
        if(inorder[i]==root->val){
            mid=i;
            break;
        }
    }
    root->left=solve(inorder,preorder,st,mid-1);
    root->right=solve(inorder,preorder,mid+1,end);
    return root;

}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
   vector<int> a{40,20,50,10,30,80,70,90};
    vector<int> b{10,20,40,50,30,70,80,90};
    Node* root=solve(a,b,0,a.size()-1);
    preorder(root);
    return 0;
}