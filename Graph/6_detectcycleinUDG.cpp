#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool BFS(vector<int> adj[],int src,int par,vector<bool> vis){
    vis[src]=true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto& x:adj[top]){
            if(!vis[x]){
                vis[x]=true;
                return BFS(adj,x,src,vis);
            }else if(vis[x]&& x!=par){
                return true;
            }
        }
    }
    return false;
}


bool BFS_main(vector<int> adj[],int v){
       vector<bool> visited(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (BFS(adj, i,-1, visited))
                return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int v = 5;
    vector<int> adj[v];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    if (BFS_main(adj, v))
        cout << "\nCycle exists!\n";
    else
        cout << "\nNo cycle found.\n";

    return 0;
}