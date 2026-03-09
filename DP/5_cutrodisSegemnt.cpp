#include<iostream>
#include<vector>
using namespace std;
int solve(int l,int x,int y,int z,vector<int>& dp){
    if(l==0){
        return 0;
    }if(l<0){
        return INT_MIN;
    }
    if(dp[l]!=-1) return dp[l];
    int a=solve(l-x,x,y,z,dp);
    int b=solve(l-y,x,y,z,dp);
    int c=solve(l-z,x,y,z,dp);
    return dp[l]=max(a+1,max(b+1,c+1));
}
int main(){
    int l = 7, x = 5, y = 2, z = 2;
    vector<int> dp(l+1,-1);
    int ans=solve(l,x,y,z,dp);
    if(ans==INT_MIN) cout<<0<<endl;
    else cout<<ans<<endl;
}