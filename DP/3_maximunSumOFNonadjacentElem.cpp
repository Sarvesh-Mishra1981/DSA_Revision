#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int idx,int n,vector<int>& dp){
    if(idx==n-1){
        return a[idx];
    }
    if(idx >= n){
    return 0;
}
    if(dp[idx]!=-1) return dp[idx];
    int take=a[idx]+solve(a,idx+2,n,dp);
    int nottake=solve(a,idx+1,n,dp);
    return dp[idx]=max(take,nottake);
}

int main(){
vector<int> a = {2, 7, 9, 3, 1};
    int n = a.size();
    vector<int> a1,a2;
    for(int i=0;i<n-1;i++){
            a1.push_back(a[i]);
        } 
         for(int i=1;i<n;i++){
            a2.push_back(a[i]);
        } 
    vector<int> dp1(n,-1),dp2(n,-1);
    cout<<max(solve(a1,0,a1.size(),dp1),solve(a2,0,a2.size(),dp2))<<endl;
}