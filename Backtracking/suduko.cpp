#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<vector<int>>& grid,int n,int row,int col,int x){
    for(int i=0;i<n;i++){
        if(grid[row][i]==x || grid[i][col]) return false;
    }
    int sq=sqrt(n);
    int rs=row-(row%sq);
    int cs=col-(col%sq);
    for(int i=0;i<sq;i++){
        for(int j=0;j<sq;j++){
            if(grid[i+rs][j+cs]==x) return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& grid,int n){
    int i=0,j=0;
    for(;i<n;i++){
        for(;j<n;j++){
            if(grid[i][j]==0){
                break;
            }
        }
    }
    if(i==n-1 && j==n-1) return true;
    for(int x=1;x<9;x++){
        if(issafe(grid,n,i,j,x)){
        grid[i][j]=x;
        if(solve(grid,n)) return true;

        grid[i][j]=0;
        }
    }
}
int main(){

}