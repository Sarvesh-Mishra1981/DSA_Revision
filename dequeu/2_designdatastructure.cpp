#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Mydsg{
    public:
    deque<int> dq;
    bool isEmpty(){
        return dq.size()==0;
    }
    void insertmax(int v){
        dq.push_back(v);
    }
    void insertmin(int v){
        dq.push_front(v);
    }
    int getmax(){
        if(dq.empty()) return -1;
        int val=dq.back();
        return val;
    }
    int getmin(){
        if(dq.empty()) return -1;
        int val=dq.front();
        return val;
    }
    void popmax(){
        dq.pop_back();
        return;
    }
     void popmin(){
        dq.pop_front();
        return;
    }
};
int main(){
 
}