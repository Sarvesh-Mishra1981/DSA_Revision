#include<iostream>
#include<vector>
using namespace std;

void targen(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& low,
            vector<int>& dec, vector<vector<int>>& res,
            int parent, int src, int& timer){

    vis[src] = true;
    low[src] = dec[src] = timer++;

    for(auto x : adj[src]){

        if(x == parent) continue;

        if(!vis[x]){
            targen(adj, vis, low, dec, res, src, x, timer);

            low[src] = min(low[src], low[x]);

            // bridge condition
            if(low[x] > dec[src]){
                res.push_back({src, x});
            }
        }
        else{
            low[src] = min(low[src], dec[x]);
        }
    }
}

vector<vector<int>> FindGraph(vector<vector<int>>& a, int v, int e){

    vector<vector<int>> adj(v);

    // build undirected graph
    for(int i=0;i<e;i++){
        int u = a[i][0];
        int vv = a[i][1];

        adj[u].push_back(vv);
        adj[vv].push_back(u);
    }

    vector<bool> vis(v,false);
    vector<int> low(v,0), dec(v,0);

    vector<vector<int>> res;
    int timer = 0;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            targen(adj, vis, low, dec, res, -1, i, timer);
        }
    }

    return res;
}

int main(){
    int v = 5;
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,0}, {1,3}, {3,4}
    };

    int e = edges.size();

    vector<vector<int>> bridges = FindGraph(edges, v, e);

    cout << "Bridges in the graph are:\n";
    for (auto& b : bridges) {
        cout << b[0] << " -- " << b[1] << endl;
    }

    return 0;
}