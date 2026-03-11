/*
In this there 3 people and u can choosse any pizza and one frnd in clockwise and one anticlock u need to choose the puzza such that 
it has max value
basic idea--:
1. if choosen then move +2 coz one will choose next and even if not choosem then we will move +1
using idea of dp
*/
#include<iostream>
#include<vector>
using namespace std;
int pizzaWithSlice(vector<int>& a,int index,int n,int endindex,vector<vector<int>>& dp){
    if(n==0 || index>endindex) return 0;
    if(dp[index][n]!=-1) return dp[index][n];
    int take=a[index]+pizzaWithSlice(a,index+2,n-1,endindex,dp);
    int nottake=pizzaWithSlice(a,index+1,n,endindex,dp);
    dp[index][n]= max(take,nottake);
    return  dp[index][n];
}
int main(){
 vector<int> a = {1, 2, 3, 6, 1, 2};
    int n = a.size();

    int slices = n / 3;

    vector<vector<int>> dp1(n, vector<int>(slices + 1, -1));
    int case1 = pizzaWithSlice(a, 0, slices, n - 2, dp1);
    vector<vector<int>> dp2(n, vector<int>(slices + 1, -1));
    int case2 = pizzaWithSlice(a, 1, slices, n - 1, dp2);

    int ans = max(case1, case2);

    cout << "Maximum pizza slices you can eat: " << ans << endl;

    return 0;
}