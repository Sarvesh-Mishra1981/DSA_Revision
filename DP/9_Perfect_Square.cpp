#include<vector>
#include<iostream>
using namespace std;
int solve(int target,vector<int>& dp){
    if(target==0){
        return 0;
    }
    if(dp[target]!=-1) return dp[target];
    int ans=target;
    for(int i=1;i*i<=target;i++){
        int temp=i*i;
        ans=min(ans,1+solve(target-temp,dp));
    }
    return ans;
}
int main(){
    int target=6;
    vector<int> dp(target+1,-1);
    cout<<solve(target,dp)<<endl;
}