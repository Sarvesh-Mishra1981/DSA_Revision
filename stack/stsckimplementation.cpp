#include<vector>
#include<iostream>

#include<stack>
using namespace std;

int main(){
stack<int> st;
st.push(20);
st.pop();
cout<<st.top()<<endl;
if(st.empty()){
cout<<"Yes"<<endl;
}
}