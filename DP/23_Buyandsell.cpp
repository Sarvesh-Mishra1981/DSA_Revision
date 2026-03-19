#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int n){
int ans=0;
    for(int i=0;i<n-1;i++){
        if(a[i]<a[i+1]){
            ans+=(a[i+1]-a[i]);
        }
    }
    return ans;
}
int main(){
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout<<solve(a,6);
}