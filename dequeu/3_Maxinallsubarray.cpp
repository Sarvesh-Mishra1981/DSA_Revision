#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void solve(vector<int>& a,int n,int k){
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i=k;i<n;i++){
        cout<<a[dq.front()]<<" ";
         while(!dq.empty() && dq.front()<=i-k){
           dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()]<=a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
     cout<<a[dq.front()]<<" ";
}
int main(){
vector<int> a{1,3,5,4,2,6,9,5,3,7};
solve(a,a.size(),3);
}