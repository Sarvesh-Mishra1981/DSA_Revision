#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<vector<int>>& maze,int i,int j,int n){
    return (i<n && j<n && maze[i][j]==1);
}
bool solve(vector<vector<int>>& maze,int n,int i,int j,string ans){
    if(i==n-1 && j==n-1) {
        return true;
    }
    if(issafe(maze,i,j,n)){
        maze[i][j]=1;
        if(solve(maze,n,i+1,j,ans+'D')|| solve(maze,n,i,j+1,ans+'R')){
            return true;
        }
        maze[i][j]=0;
    }
    return false;
}
int main(){
vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int n=4;
    string ans="";
    if(!solve(maze1,n,0,0,ans)){
        cout<<" No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        cout<<ans<<endl;
    }
}