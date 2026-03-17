/*
In this you are given 2 array and you have to make both the array increasing and 
you can swap the only from array 1 to array 2 and that too same index;


so what we do is that we will make the one bool and that we make the record the swaped value
we will just do compare both the array with the prev value and then if found that value need to be swapped then in that condition we will swap that
*/
#include<iostream>
#include<vector>
using namespace std;
int MinSwap(vector<int>& a,vector<int>& b,int index,bool swapped,vector<vector<int>>& dp){
    if(index>=a.size()) return 0;
    int ans=INT_MAX;
    int prev=a[index-1];
    int prev2=b[index-1];
    if(dp[index][swapped]!=-1) return dp[index][swapped];
    if(swapped){
        swap(prev,prev2);
    }
    if(a[index]>prev && b[index]>prev2){
        ans=MinSwap(a,b,index+1,false,dp);
    }
    if(a[index]>prev2 && b[index]>prev){
        ans=min(ans,1+MinSwap(a,b,index+1,true,dp));
    }
    dp[index][swapped]=ans;
    return dp[index][swapped];
}
int minSwapToMakeIncreasing(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return MinSwap(a, b, 1, false, dp);
}

int main() {
    vector<int> a = {1, 3, 5, 4};
    vector<int> b = {1, 2, 3, 7};

    int ans = minSwapToMakeIncreasing(a, b);
    cout << "Minimum swaps required = " << ans << endl;

    return 0;
}