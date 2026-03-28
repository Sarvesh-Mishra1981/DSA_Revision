#include<vector>
#include<iostream>
using namespace std;
class Mypair {
public:
    int diff;  
    int val;  
    Mypair(int d, int v) {
        diff = d;
        val = v;
    }
};

struct cmp {
    bool operator()(Mypair &a, Mypair &b) {
        return a.diff < b.diff; 
    }
};
void kcloset(vector<int>& a,int k,int x){
    int n=a.size();
    priority_queue<Mypair,vector<Mypair>,cmp> pq;
    for(int i=0;i<k;i++){
        pq.push(Mypair(abs(a[i]-x),a[i]));
    }
    for(int i=k+1;i<a.size();i++){
        int diff=abs(a[i]-x);
        if(pq.top().diff>diff){
            pq.pop();
            pq.push(Mypair(diff,a[i]));
        }
    }
    while(!pq.empty()){
        cout<<pq.top().val<<" ";
        pq.pop();
    }   
}
int main(){
    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 3, x = 7;
    kcloset(arr,k,x);
}