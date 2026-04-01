#include<vector>
#include<iostream>
using namespace std;
int rect(vector<int>& a,int n){
    stack<int> st;
    int res=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            int tp=st.top();
            st.pop();
            int ans=a[tp]*(st.empty()?i:i-tp-1);
            res=max(res,ans);
        }
        st.push(i);
    }
     while(!st.empty()){
            int tp=st.top();
            st.pop();
            int ans=a[tp]*(st.empty()?n:n-tp-1);
            res=max(res,ans);
        }
        return res;
}
int solve(vector<vector<int>>& a,int n,int m){
    int res=rect(a[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                a[i][j]+=a[i-1][j];
            }
        }
        res=max(res,rect(a[i],m));
    }
    return res;
}

int main(){
 vector<vector<int>> a{
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 1, 1}
    };
    cout<<solve(a,4,4)<<endl;
}