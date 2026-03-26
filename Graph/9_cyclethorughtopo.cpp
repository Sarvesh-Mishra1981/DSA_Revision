#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topo(vector<int> adj[],stack<int>& st,vector<bool> vis,int src){
    vis[src]=true;
    for(auto x:adj[src]){
        if(!vis[x]){
            topo(adj,st,vis,x);
        }
    }
    st.push(src);
}

bool Dfs(vector<int> adj[],int v){
    stack<int> st;
    vector<bool> vis(v,false);
    for(int i = 0; i < v; i++){
    if(!vis[i]){
        topo(adj, st, vis, i);
    }}
    int cnt=st.size();
    return cnt==v;

}
void addEdge(vector<int> adj[],int v,int u){
    adj[v].push_back(u);
}
int main(){
int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
  
    cout<<Dfs(adj,V)<<endl;

	return 0; 
}

