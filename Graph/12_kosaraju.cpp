#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include <unordered_map>
using namespace std;


void toposort(unordered_map<int,list<int>>& adj,stack<int>& st,int src,vector<bool>& vis){
    vis[src]=true;
    for(auto x:adj[src]){
        if(!vis[x]){
            toposort(adj,st,x,vis);
        }
    }
    st.push(src);
}
unordered_map<int,list<int>> findadjrev(vector<vector<int>>& edges,int V,int E){
    unordered_map<int,list<int>> mp;
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        mp[v].push_back(u);
    }
    return mp;
}
unordered_map<int,list<int>> findadj(vector<vector<int>>& edges,int V,int E){
    unordered_map<int,list<int>> mp;
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        mp[u].push_back(v);
    }
    return mp;
}
void dfs(unordered_map<int,list<int>>& adj,int s,vector<bool>& vis){
    vis[s]=true;
    for(auto x:adj[s]){
        if(!vis[x]){
            dfs(adj,x,vis);
        }
    }
}
int Kosaraju_Algo(vector<vector<int>>& edges,int V,int E){
    //we need to find the adj matrix
    unordered_map<int,list<int>> adj=findadj(edges,V,E);

    //we need to find topo sort
    stack<int> st;
    vector<bool> vis(V,false);
    toposort(adj,st,0,vis);

    //we need to reverse the thing
    unordered_map<int,list<int>> adjrev=findadjrev(edges,V,E);

    //mainthing
    int cnt=0;
    vector<bool> vis1(V,false);
    while(!st.empty()){
        int top=st.top();
        st.pop();
        for(auto x:adj[top]){
            if(!vis1[x]){
                cnt++;
                dfs(adjrev,x,vis1);
            }
        }
    }
    return cnt;
}
int main(){
  int V=5,E=5;
    vector<vector<int>> edges = {
        {0,1},{1,2},{2,0},{1,3},{3,4}
    };

    cout<<"Number of Strongly Connected Components = "<<Kosaraju_Algo(edges,V,E)<<endl;

    return 0;
}