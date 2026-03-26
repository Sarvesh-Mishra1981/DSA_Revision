#include<iostream>
#include<vector>
using namespace std;

int Bellamford(vector<vector<int>>& a,int src,int des,int n,int e){
    vector<int> dis(n+1,INT_MAX);
    dis[src]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<e;j++){
            int u=a[j][0];
            int v=a[j][1];
            int d=a[j][2];
            if(dis[u]!=INT_MAX){
                if(dis[u]+d<dis[v]){
                    dis[v]=dis[u]+d;                
                }
            }
        }
    }
   return dis[des];

}

int main(){
  int n = 4; // number of vertices
    int edges = 5;
    vector<vector<int>> a = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -3},
        {1, 3, 2},
        {2, 3, 4}
    };
     int src = 0, dest = 3;
     cout<<Bellamford(a,src,dest,n,edges)<<endl;

}