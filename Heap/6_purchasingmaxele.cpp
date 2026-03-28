#include<vector>
#include<iostream>
using namespace std;

int maxitem(vector<int>& a,int amt){
    int n=a.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    int res=0;
    while(!pq.empty()){
        if(pq.top()<=amt){
            res++;
            amt-=pq.top();
            pq.pop();
        }else{
            break;
        }
    }
    return res;
}
int main(){
    vector<int> a{1,12,5,111,200};
    cout<<maxitem(a,10)<<endl;
}