#include<iostream>
#include<vector>
using namespace std;
int solve(int start,int end,vector<vector<int>>& dp){
    if(start>=end) return 0;
    int ans=INT_MAX;
    if(dp[start][end]!=-1) return dp[start][end];
    for(int i=start;i<=end;i++){
        ans=min(ans,i+max(solve(start,i-1,dp),solve(i+1,end,dp)));
    }
    return dp[start][end]=ans;
}
int main(){
     int n=5;
     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
     cout<<solve(0,n,dp);
}