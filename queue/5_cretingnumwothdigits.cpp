#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void solve(int n,int m,int k){
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int i=0;i<=k;i++){
        string top=q.front();
        cout<<top<<endl;
        q.pop();
        q.push(top+'5');
        q.push(top+'6');
    }
}
int main(){
 solve(5,6,8);
}