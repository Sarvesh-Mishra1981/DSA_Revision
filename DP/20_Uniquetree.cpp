#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>& dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=solve(i-1,dp)*solve(n-i,dp);
    } 
    return ans;
}
int main(){
int n=4;
vector<int> dp(n+1,-1); 
cout<<solve(n,dp)<<endl;
}