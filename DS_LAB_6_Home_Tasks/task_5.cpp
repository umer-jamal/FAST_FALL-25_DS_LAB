#include<iostream>
using namespace std;

class Checkpoint{
    int size;
    int currentSize;
    int front;
    int rear;
    int *arr;
    public:
    Checkpoint(int s){
        size = s;
        currentSize = 0;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void enqueue(int d){
        if (currentSize<size)
        {
            rear = (rear+1)%size;
            arr[rear] = d;
            currentSize++;
            return;
        }
        else{
            cout<<"Queue is full please wait\n";
        }
        
    }

    void dequeue(){
        front = (front+1)%size;
        arr[front] = -1;
        currentSize--;
    }

    void display(){
        int j = 0;
        for (int i =0; j<size  ; j++,i++)
        {
            cout<<arr[i]<< "  ";
        }
        cout<<endl;
    }
};


int main(){
    Checkpoint c(5);
    
    c.enqueue(2);
    c.enqueue(4);
    c.enqueue(6);
    c.enqueue(7);
    c.enqueue(21);
    c.display();
    c.dequeue();
    c.display();
    c.enqueue(5);
    c.display();
}