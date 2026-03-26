#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topo(vector<pair<int,int>>adj[],int v,stack<int>& s,int src,vector<bool>& vis){
    vis[src]=true;
    for(auto& x:adj[src]){
        if(!vis[x.first]){
            topo(adj,v,s,x.first,vis);
        }
    }
    s.push(src);
}

void getdis(vector<pair<int,int>> adj[],stack<int>& st,int src,int v,vector<int>& dis){
    dis[src]=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(dis[top]!=INT_MAX){
            for(auto& x:adj[top]){
                if((dis[top]+x.second)<dis[x.first]){
                    dis[x.first]=(dis[top]+x.second);
                }
            }
        }
    }
}

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
   adj[u].push_back({v, wt});
}
int main(){
    int V = 6; 
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 4, 4);
    addEdge(adj, 2, 5, 2);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 3, 4, -1);
    addEdge(adj, 4, 5, -2);
    stack<int> st;
    vector<bool> vis(V,false);
    topo(adj,V,st,0,vis);
    vector<int> dis(V,INT_MAX);
    getdis(adj,st,0,V,dis);
    for(int i=0;i<V;i++){
        cout<<dis[i]<<" ";
    }
    
}