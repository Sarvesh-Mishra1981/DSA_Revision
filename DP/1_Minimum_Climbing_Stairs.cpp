#include<iostream>
#include<vector>
using namespace std;
int solve(int idx,vector<int>& a,vector<int>& dp){
    if(idx==0 || idx==1){
        return a[idx];
    }
    if(dp[idx]!=-1) return dp[idx];
    int pre=a[idx]+solve(idx-1,a,dp);
    int prevv=a[idx]+solve(idx-2,a,dp);
    return dp[idx]=min(pre,prevv);
}
int main(){
 vector<int> cost = {10, 15, 20};
    int n = cost.size();

    vector<int> dp(n, -1);
    int ans = min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));

    cout << "Minimum cost to reach the top: " << ans << endl;
    return 0;
}