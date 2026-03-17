#include<iostream>
#include<vector>
using namespace std;
int solve(int dices,int faces,int target,vector<vector<int>>& dp){
    if(target<0) return 0;
    if(target==0 && dices!=0) return 0;
    if(target!=0 && dices==0) return 0;
    if(dices==0 && target==0) return 1;
    if(dp[dices][target]!=-1) return dp[dices][target];
    int ans=0;
    for(int i=1;i<=faces;i++){
        ans+=solve(dices-1,faces,target-i,dp);
    }


return dp[dices][target]=ans;
}
int main(){
    int dices = 3;  
    int faces = 6;
    int target = 7;
    vector<vector<int>> dp(dices+1,vector<int>(target+1,-1));
    cout<<solve(dices,faces,target,dp)<<endl;
}