#include<iostream>
#include<vector>
using namespace std;

bool issafe(vector<vector<int>>& chess,int row,int col,int n){
    for(int i=0;i<col;i++){
        if(chess[row][i]==1) return false;
    }
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(chess[i][j]==1) return false;
    }

    // lower-left diagonal
    for(int i=row, j=col; i<n && j>=0; i++, j--){
        if(chess[i][j]==1) return false;
    }

    return true;
}

bool solve(vector<vector<int>>& chess,int n,int col){
    if(col==n){
        return true;
    }

    for(int i=0;i<n;i++){
        if(issafe(chess,i,col,n)){
            chess[i][col]=1;

            if(solve(chess,n,col+1)){
                return true;
            }

            chess[i][col]=0;
        }
    }

    return false;
}

int main(){
    int n=4;
    vector<vector<int>> chess(n,vector<int>(n,0));

    if(!solve(chess,n,0)){
        cout<<"NO"<<endl;
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}