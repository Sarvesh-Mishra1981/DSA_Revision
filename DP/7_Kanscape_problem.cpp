#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int cap,vector<int>& b,int n,vector<vector<int>>& dp){
    if(n==0){
        if(cap>=b[n]){
            return a[n];
        } else {
            return 0;
        }
    }
    if(dp[cap][n]!=-1) return dp[cap][n];
    int take;
    int nottake;
    if(b[n]<=cap){
        take=a[n]+solve(a,cap-b[n],b,n-1,dp);
    }
    nottake=solve(a,cap,b,n-1,dp);
    return dp[cap][n]=max(take,nottake);
}
int main(){
 vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    int n = value.size();
    vector<vector<int>> dp(capacity+1,vector<int>(n+1,-1));
    cout<<solve(value,capacity,weight,n-1,dp)<<endl;
}