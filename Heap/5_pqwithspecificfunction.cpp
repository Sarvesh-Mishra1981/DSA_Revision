#include<vector>
#include<iostream>
using namespace std;

class Triplet{
    public:
    int val;
    int apos;
    int vpos;
    Triplet(int x,int y,int z){
        val=x;
        apos=y;
        vpos=z;
    }
};
class Mycmp{
    public:
    bool operation(Triplet const a,Triplet const b){
        return a.val>b.val;
    }
};
int main(){
    priority_queue<Triplet,vector<Triplet>,Mycmp> pq;
}