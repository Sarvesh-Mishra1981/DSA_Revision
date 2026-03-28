/*
this is the important q of finding the medin of the each element*/
#include<iostream>
#include<vector>
using namespace std;
void median(vector<int>& a){
    int n=a.size();
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> e;
    s.push(a[0]);
    for(int i=1;i<n;i++){
        int val=a[i];
        if(s.size()>e.size()){
            if(val>s.top()){
                e.push(val);
            }
            else{
            e.push(s.top());
            s.pop();
            s.push(val);
        }
        cout<<(s.top()+e.top())/2<<" ";
        }else{
            if(val<=s.top()){
                s.push(val);
            }else{
                e.push(val);
                s.push(e.top());
                e.pop();
            }
            cout<<s.top()<<" ";
        }
    }
}
int main(){
vector<int> a{25,7,10,15,12};
median(a);
}