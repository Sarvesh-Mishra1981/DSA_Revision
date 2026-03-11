#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int n,int target,vector<int>& dp){
    if(target==0){
        return 1;
    }
    if(target<0) return 0;
    if(dp[target]!=-1) return dp[target];
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=solve(a,n,target-a[i],dp);
    }
    return dp[target]=ans;

}
int main(){
 vector<int> nums = {1, 2, 3};
    int target = 4;
    vector<int> dp(target+1,-1);
    cout<<solve(nums,3,target,dp)<<endl;              
}