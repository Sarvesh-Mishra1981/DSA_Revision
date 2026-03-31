#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool matching(char a,char b){
    if((a=='(' && b==')') ||(a=='[' && b==']') || (a=='{' && b=='}')) return true;
    else return false;
}
bool isvalid(string& a){
    stack<char> st;
    for(int i=0;i<a.length();i++){
        if(a[i]=='(' || a[i]=='{' || a[i]=='['){
            st.push(a[i]);
        }else{
            if(matching(st.top(),a[i])){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    
    string s = "{([()])}";
    string b = "{([(])}";
       cout << isvalid(s) << endl; 
    cout << isvalid(b) << endl;

    return 0;

}