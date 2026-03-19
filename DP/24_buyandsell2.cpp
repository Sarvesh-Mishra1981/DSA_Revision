#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int n,bool buy,int idx,vector<vector<int>>& dp){
    if(idx>=n) return 0;
    int profit=0;
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    if(buy){
        profit=max(solve(a,n,buy,idx+1,dp),a[idx]+solve(a,n,!buy,idx+1,dp));
    }else{
        profit=max(solve(a,n,buy,idx+1,dp),solve(a,n,!buy,idx+1,dp)-a[idx]);
    }
    return dp[idx][buy]=profit;
}
int main(){
  vector<int> a = {7, 1, 5, 3, 6, 4};
  int n=6;
  vector<vector<int>> dp(n+1,vector<int>(2,-1));
  cout<<solve(a,6,0,0,dp)<<endl;
}