#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<limits>
#include<set>
using namespace std;
/*
in this algo what we do is that we made a finalised vcetor in that we make graph element a finalised then what we do is thta
we update the distance 
this is for the both the undirected as well as directed graph and hence thert is another way of applying this 
that is what we will do is that we will make the priority queue and in that we will put the element and then go to its
top childs and then tarverse and update their distance.
*/
vector<int> DijkstraAlgo(vector<vector<int>>& edges, int V, int E, int S) {
    // Step 1: Build adjacency list
    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // undirected graph
    }

    // Step 2: Distance array
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;

    // Step 3: Min-heap priority queue -> {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, S});

    // Step 4: Dijkstra loop
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        // Skip if we already found a better path
        if (d > dist[node]) continue;

        for (auto [nbr, wt] : adj[node]) {
            if (d + wt < dist[nbr]) {
                dist[nbr] = d + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    return dist;
}
int main(){
    int V = 5, E = 6;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 4}, {1, 2, 1},
        {1, 3, 7}, {2, 4, 3}, {3, 4, 1}
    };
    int S = 0;

    vector<int> dist = DijkstraAlgo(edges, V, E, S);

    cout << "Shortest distances from source " << S << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
    return 0;
}