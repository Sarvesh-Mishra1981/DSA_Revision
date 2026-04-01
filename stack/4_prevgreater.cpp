#include<iostream>
#include<vector>
using namespace std;
void prevgreater(vector<int>& a,int n){
    stack<int> st;
    st.push(0);
    cout<<-1<<" ";
    for(int i=1;i<n;i++){
        while(!st.empty() && a[st.top()]<=a[i]){
            st.pop();
        }
        cout<<(st.empty()?-1:a[st.top()])<<" ";
        st.push(i);
    }
}
int main(){
     vector<int> a{13,15,12,14,16,8,5,4,10,30};
     prevgreater(a,a.size());
}