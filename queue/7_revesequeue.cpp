#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void revese(queue<int>& q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){
  deque<int> d = {1, 2, 3, 4, 5, 6};
    queue<int> q(d);
    revese(q);
}