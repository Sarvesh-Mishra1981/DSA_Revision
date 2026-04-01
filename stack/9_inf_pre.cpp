#include<vector>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int pre(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool is(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string solve(string infix){
    stack<char> st;
    string ans="";
    for(char c:infix){
    if(isalpha(c)){
        ans+=c;
    }
    else if(c=='('){
        st.push(c);
    }else if(c==')'){
        while(!st.empty() && st.top()!='('){
            ans+=st.top();
            st.pop();
        }
        if (!st.empty()) st.pop();
    }else if(is(c)){
        while(!st.empty() && pre(st.top())>=pre(c)){
            st.pop();
        }
        st.push(c);
    }}
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
string prefix(string infix){
    reverse(infix.begin(),infix.end());
    for(auto x:infix){
        if(x==')'){
            x='(';
        }
        if(x=='('){
            x=')';
        }
    }
    string ans=solve(infix);
    reverse(ans.begin(),ans.end());
    return ans;

}
int main(){
string infix="(A-B/C)*(A/K-L)";
    cout << "Prefix: " << prefix(infix) << endl;
    return 0;
}