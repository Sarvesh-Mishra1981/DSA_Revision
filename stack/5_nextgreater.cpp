#include<iostream>
#include<vector>
using namespace std;
void nextgrt(vector<int>& a,int n){
     stack<int> st;
     vector<int> ans(n);
    st.push(n-1);
   ans[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
        ans[i]=(st.empty()?-1:a[st.top()]);
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
     vector<int> a{13,15,12,14,16,8,5,4,10,30};
     int n=a.size();
     nextgrt(a,n);
}