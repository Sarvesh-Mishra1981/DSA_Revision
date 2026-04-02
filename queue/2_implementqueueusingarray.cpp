#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};

class Queue{
    public:
    Node* front,*rear;
    int size;
    Queue(){
        front=NULL;
        rear=NULL;
        size=0;
    }
    void enqueue(int x){
        Node* temp=new Node(x);
        if(front==NULL) {
            front=temp;
            rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void dequeue(){
        if(front==NULL) return;
        size--;
        Node* temp=front;
        front=front->next;
        if(front==NULL) return;
        delete(temp);
    }
    bool isEmpty(){
        return(front==NULL);
    }
    int getFront(){
        if(front==NULL) return -1;
        return front->val;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl; 

    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl;  

    cout << "Queue size: " << q.size << endl;  

    q.dequeue();
    q.dequeue();
    q.dequeue();  

    return 0;
}