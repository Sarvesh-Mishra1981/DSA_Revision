/*
see we can for from sq only when we have same number of 1 in the down right and diagonal and if thy arere not same then
we have to select the minimum of all than and from there we can form thta much big sq.
*/
#include<vector>
#include<iostream>
using namespace std;
int LargestSq(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j,int& maxi){
    if(i>=matrix.size() || j>=matrix[0].size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int down=LargestSq(matrix,dp,i+1,j,maxi);
     int diagonal=LargestSq(matrix,dp,i+1,j+1,maxi);
    int right=LargestSq(matrix,dp,i,j+1,maxi);
    if(matrix[i][j]==1){
        int ans=1+min(down,min(right,diagonal));
        dp[i][j]=ans;
        maxi=max(maxi,ans);
        return dp[i][j];
    }
    else {
        return dp[i][j]=0;
    }
}
int main(){
  vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = 0;

    LargestSq(matrix, dp, 0, 0, maxi);

    cout << "Largest square of 1s has side length: " << maxi << endl;
    cout << "Maximum area of square: " << maxi * maxi << endl;

    return 0;
}