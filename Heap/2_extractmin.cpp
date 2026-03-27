/*
so the basic idea is that we will put the min element in the end and then remove that and then we will make the minheapy function

*/
#include<iostream>
#include<algorithm>
using namespace std;
class MinHeap{
    public:
    int *arr;
    int size;
    int capacity;
    MinHeap(int c){
        arr=new int(c);
        capacity=c;
        size=0;
    }
    int left(int i){ return arr[2*i+1];}
    int right(int i){return arr[2*i+2];}
    int parent(int i){return arr[abs(i-1)/2];}

void Minheapify(int i){
    int lt=left(i);
    int rt=right(i);
    int small=i;
    if(lt<size && arr[lt]<arr[small]){small=lt;}
    if(rt<size && arr[rt]<arr[small]){small=rt;}
    if(small!=i){
        swap(arr[i],arr[small]);
        Minheapify(small);
    }
}
void insert(int x){
    if(size==capacity) cout<<"Size is full"<<endl;
    size++;
    arr[size]=x;
    for(int i=size;i>=0 && arr[i]<arr[parent(i)];){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}
int extractmin(){
    if(size==0) return INT_MAX;
    if(size==1) return arr[0];
    swap(arr[0],arr[size]);
    int mini=arr[size];
    size--;
    Minheapify(0);
    return mini;
}
};

int main(){
    MinHeap h(10);

    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    return 0;
}