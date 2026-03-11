#include<vector>
#include<iostream>
using namespace std;
int solve(vector<int>& a,int n,int idx,int time,vector<vector<int>>& dp){
    if(idx>=n) return 0;
    if(dp[idx][time]!=-1) return dp[idx][time];
    int take=a[idx]*time+solve(a,n,idx+1,time+1,dp);
    int nottake=solve(a,n,idx+1,time,dp);
    return dp[idx][time]=max(take,nottake);
}
int main(){
vector<int> a = {-1, -8, 0, 5, -9};
    int n = a.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<solve(a,n,0,0,dp);
}