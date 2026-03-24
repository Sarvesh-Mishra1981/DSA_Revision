#include<iostream>
#include<vector>
using namespace std;
#include<queue>

void BFS(vector<int> adj[],int n,int src){
    vector<int> vis(n,false);
    vis[src]=true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout<<top<<" ";
        for(auto& x:adj[top]){
            if(!vis[x]){
                vis[x]=true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v=5;
    vector<int> adj[v];
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);
    BFS(adj,v,0);  
}