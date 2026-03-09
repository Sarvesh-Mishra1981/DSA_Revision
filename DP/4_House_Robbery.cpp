#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int n,int idx,vector<int>& dp){
    if(idx==n-1) return a[idx];
    if(idx>=n) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int take=a[idx]+solve(a,n,idx+2,dp);
    int notatke=solve(a,n,idx+1,dp);
    return dp[idx]=max(take,notatke);
}
int main(){
    vector<int> houses = {2, 3, 2}; 
    vector<int> a,b;
    int n=houses.size();
    for(int i=0;i<n-1;i++){
        a.push_back(houses[i]);
    }for(int i=1;i<n;i++){
b.push_back(houses[i]);
    }
    vector<int> dp1(n,-1),dp2(n,-1);
    cout<<max(solve(a,n-1,0,dp1),solve(b,n-1,0,dp2));
   
}