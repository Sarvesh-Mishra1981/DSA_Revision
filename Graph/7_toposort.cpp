#include<vector>
#include<iostream>
#include<queue>
using namespace std;
// the main idea of the toposort is that we sort on the basis of the reachblity
void toposort(vector<int> adj[],int v){
    queue<int> q;
    vector<int> inorder(v,0);
    for(int i=0;i<v;i++){
        for(auto x:adj[i])
       { inorder[x]++;}
    }
    for(int i=0;i<v;i++){
        if(inorder[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top=q.front();
        cout<<top<<" ";
        q.pop();
        for(auto x:adj[top]){
            if(--inorder[x]==0){
                q.push(x);
            }
        }
    }
}

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}
int main(){
int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
  
    cout << "Following is a Topological Sort of\n"; 
    toposort(adj,V);

	return 0; 
}