#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int idx,vector<int>& b,int n,vector<int>& dp){
    if(idx>=n){
        return 0;
    }
    if(dp[idx]!=-1) return dp[idx];
    int op1=b[0]+solve(a,idx+1,b,n-1,dp);
    int i;
    for(i=idx;i<n && a[i]<a[idx]+7;i++);
    int op2=b[1]+solve(a,i,b,n,dp);
    for(i=idx;i<n && a[i]<a[idx]+30;i++);
    int op3=b[1]+solve(a,i,b,n,dp);
    return dp[idx]=min(op1,min(op2,op3));

}
int main(){
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 15}; 
    int n = days.size();
    vector<int> dp(n+1,-1);
    cout<<solve(days,0,cost,n,dp)<<endl;
}