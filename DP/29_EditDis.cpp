#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solve(string a,string b,int n,int m,int i,int j,vector<vector<int>>& dp){
    if(i==a.size()) return (m-i);
    if(j==b.size()) return (n-i);
    int ans=0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[i]){
        ans=solve(a,b,n,m,i+1,j+1,dp);
    }else{
        ans=min(1+solve(a,b,n,m,i+1,j,dp),min(1+solve(a,b,n,m,i,j+1,dp),1+solve(a,b,n,m,i+1,j+1,dp)));
    }
    return dp[i][j]=ans;
}
int main(){
 string word1 = "intention";
    string word2 = "execution";

    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<solve(word1,word2,n,m,0,0,dp)<<endl;
}