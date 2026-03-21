#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,vector<int>& b,int n,int m,int idx,int jdx,vector<vector<int>>& dp){
    if(idx>=n || jdx>=m){
        return 0;
    }
    if(dp[idx][jdx]!=-1) return dp[idx][jdx];
    int ans=0;
    if(a[idx]==b[jdx]){
        ans= 1+solve(a,b,n,m,idx+1,jdx+1,dp);
    }else{
        ans= max(solve(a,b,n,m,idx+1,jdx,dp),solve(a,b,n,m,idx,jdx+1,dp));
    }
    return dp[idx][jdx]=ans;
}
int main(){
vector<int> a = {1, 3, 4, 1, 2, 3};
    vector<int> b = {3, 4, 1, 2, 1, 3};

    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m,-1));
    cout<<solve(a,b,n,m,0,0,dp)<<endl;
}