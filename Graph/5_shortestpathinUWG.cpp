#include<vector>
#include<iostream>
#include<queue>
using namespace std;


void BFS(vector<int> adj[],int src,vector<bool>& vis,vector<int>& dis){
    vis[src]=true;
    dis[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto x:adj[top]){
            if(!vis[x]){
                dis[x]=dis[top]+1;
                q.push(x);
                vis[x]=true;
            }
        }
        }
}


void BFS_main(vector<int> adj[],int v,vector<int>& distance){
    vector<bool> visited(v+1,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            BFS(adj,i,visited,distance);
        }
    }
}
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printDis(vector<int>& dis,int v){
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }
}
int main(){
    int v=5;
    vector<int> adj[v];
    vector<int> distance(v+1,-1);
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);
    BFS_main(adj,v,distance);  
    printDis(distance,v);
}