#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> Ksorted(vector<int>& a,int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    int index=0;
    vector<int> ans(n);
    for(int i=k+1;i<n;i++){
        ans[index++]=pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty()){
        ans[index++]=pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
     vector<int> a{10,9,7,8,4,70,50,60};
     int n=8;
     vector<int> ans=Ksorted(a,n,4);
     for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
     }
}