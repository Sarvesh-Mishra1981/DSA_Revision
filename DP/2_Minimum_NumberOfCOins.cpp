#include<iostream>
#include<vector>
using namespace std;

#include <climits>
int solve(vector<int>& a,int x,int n,vector<int>& dp){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MIN;
    }
    if(dp[x]!=-1) return dp[x];
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        int val=solve(a,x-a[i],n,dp);
        if(val!=INT_MIN){
            ans=min(ans,1+val);
        }
    }
    return dp[x]=ans;
}


int main(){
     vector<int> coins = {1, 2, 5}; 
    int x = 11;   
    vector<int> dp(x+1,-1);
    int res=solve(coins,x,3,dp);
    if(res==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<res<<endl;
    }
}