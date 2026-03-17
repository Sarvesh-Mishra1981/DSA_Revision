#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int target,int n,int idx,vector<vector<int>>& dp){
    if(target==0) return 1;
    if(idx>=n) return 0;
    if(target<0) return 0;
    if(dp[idx][target]!=-1) return dp[idx][target];
    int inc=solve(a,target-a[idx],n,idx+1,dp);
    int exc=solve(a,target,n,idx+1,dp);
    return dp[idx][target]=(inc || exc);
}
int main(){
 vector<int> a = {1, 5, 11, 5};
 int sum=0;
 for(int i=0;i<a.size();i++){
    sum+=a[i];}
     vector<vector<int>> dp(a.size()+1,vector<int>((sum/2)+1,-1));
    if(sum%2==0){
        cout<<solve(a,sum/2,a.size(),0,dp);
    }else{
        cout<<0<<endl;
    }
}