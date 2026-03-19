#include<vector>
#include<iostream>
using namespace std;
int solve(vector<int>& a,int n,int k,bool buy,int idx){
    if(idx>=n) return 0;
    if(k==0) return 0;
    int profit=0;
    if(buy){
        profit=max(solve(a,n,k-1,!buy,idx+1)-a[idx],solve(a,n,k,buy,idx+1));
    }else{
        profit=max(solve(a,n,k,!buy,idx+1)+a[idx],solve(a,n,k,buy,idx+1));
    }
    return profit;

}
int main(){
 vector<int> a = {7, 1, 5, 3, 6, 4};
    int k = 2;
    int n=6;
    cout<<solve(a,n,k,0,0);
}