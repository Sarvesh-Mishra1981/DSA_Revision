#include<iostream>
#include<vector>
using namespace std;
void klargest(vector<int>& a,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    int n=a.size();
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int i=k+1;i<n;i++){
        if(pq.top()<a[i]){
            pq.pop();
            pq.push(a[i]);
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main(){
 vector<int> a{ 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
 int k=3;
    klargest(a,k);
}