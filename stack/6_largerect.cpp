#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int n){
    stack<int> st;
    int res=0;
    for(int i=0;i<n;i++){
          while(!st.empty() && a[st.top()]>=a[i]){
            int top=st.top();
            st.pop();
            int ans=a[top]*(st.empty()?i:i-top-1);
            res=max(res,ans);
    }
    st.push(i);
    }
     while(!st.empty()){
            int top=st.top();
            st.pop();
            int ans=a[top]*(st.empty()?n:n-top-1);
            res=max(res,ans);
    }
return res;
}
int main(){
 vector<int> a{6, 2, 4, 5, 1, 5, 6};
 cout<<solve(a,a.size());

}