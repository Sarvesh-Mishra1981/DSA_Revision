#include<iostream>
#include<vector>
using namespace std;

bool Dfsrec(vector<int> adj[],int v,vector<bool>& vis,vector<bool>& rec,int src){
    vis[src]=true;
    rec[src]=true;
    for(auto x: adj[src]){
        if(!vis[x]){
            return Dfsrec(adj,v,vis,rec,x);
        }
        else if(rec[src]){
            return true;
        }
    }
    rec[src]=false;
    return false;
}


bool Dfs(vector<int> adj[],int v){
    vector<bool> vis(v,false);
    vector<bool> rect(v,false);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            return Dfsrec(adj,v,vis,rect,i);
        }
    }return false;
    
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