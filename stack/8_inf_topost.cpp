#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool operand(char c){
    return (c=='+' || c=='-' || c=='/' || c=='*' || c=='^');
}
int pre(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string postfix(string infix,int n){
    stack<char> st;
    string ans;
    for(char c: infix){
        if(isalpha(c)){
            ans+=c;
        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
             if (!st.empty()) st.pop();
        }
        else if(operand(c)){
            while(!st.empty() && pre(st.top())>=pre(c)){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    return ans;
}
int main(){
    string infix="(A-B/C)*(A/K-L)";
    cout<<postfix(infix,infix.length())<<endl;
}