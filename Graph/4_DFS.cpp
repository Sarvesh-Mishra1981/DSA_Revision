#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<int> adj[],vector<bool> vis,int src){
    vis[src]=true;
    cout<<src<<" ";
    for(auto& x:adj[src]){
        if(!vis[x]){
            DFS(adj,vis,x);
        }
    }
}


void DFS_main(vector<int> adj[],int a){
    vector<bool> vis(a,false);
    for(int i=0;i<a;i++){
        if(!vis[i]){
            DFS(adj,vis,i);
        }
    }
}

void addEdge(vector<int> adj[],int v,int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}
int main(){
    int v=5;
    vector<int> adj[v];
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);
    DFS_main(adj,v);  
}