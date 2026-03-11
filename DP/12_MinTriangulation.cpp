#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int n,int i,int j,vector<vector<int>>& dp){
    if(j-i==1) return 0;
    int ans=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i+1;k<j;k++){
        ans=min(ans,a[i]*a[j]*a[k]+solve(a,n,i,k,dp)+solve(a,n,k+1,j,dp));
    }
    return dp[i][j]=ans;
}
int main(){
 vector<int> v = {1, 3, 1, 4, 1, 5};

    int n = v.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<solve(v,n,0,n-1,dp)<<endl;
}