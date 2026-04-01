#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void stockspan(vector<int>& a,int n){
    stack<int> st;
    cout<<1<<" ";
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            st.pop();
        }
        cout<<(st.empty()?i+1:i-st.top());
        cout<<" ";
        st.push(i);
    }
}

int main(){
  vector<int> a{13,15,12,14,16,8,5,4,10,30};
  stockspan(a,a.size());
}