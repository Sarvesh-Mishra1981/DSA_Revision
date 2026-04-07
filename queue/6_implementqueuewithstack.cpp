#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Queue{
    public:
    stack<int> st1,st2;
    bool isEmpty(){
        return st1.size();
    }
    void push(int x){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
     int pop() {
        if (st1.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int x = st1.top();
        st1.pop();
        return x;
    }

    int front() {
        if (st1.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return st1.top();
    }

};
int main(){

}