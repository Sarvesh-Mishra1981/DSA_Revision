#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int d){
    unordered_map<int,int> dp;
    int ans=INT_MIN;
    for(int i=0;i<a.size();i++){
        int diff=a[i]-d;
        int temp=0;
        if(dp.count(diff)){
            temp=dp[diff];
        }
        dp[a[i]]=temp+1;
        ans=max(ans,temp);
    }
    return ans;
}
int main(){
vector<int> a = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int d = -2;
    // so the basic approch is that what we will do is that we will make the dp that will store the number of the nub before that 
    // with the same d. so we will jsut do that and in the emd i will just return that
    cout<<solve(a,d)<<endl;
}