#include <iostream>
using namespace std;

class MessageQueue {
private:
    string messages[100];
    int front;
    int rear;
    int size;
    int timeToPush;
    int timeToPop;

public:
    MessageQueue(int pushTime, int popTime) {
        front = 0;
        rear = -1;
        size = 0;
        timeToPush = pushTime;
        timeToPop = popTime;
    }

    void enqueue(string msg) {
        if (size == 100) {
            cout << "Queue is full. Cannot add message.\n";
            return;
        }

        cout << "\nAdding message: \"" << msg << "\" ";
        for (int i = 0; i < timeToPush; i++) cout << ".";

        rear++;
        messages[rear] = msg;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "No messages to process.\n";
            return;
        }

        cout << "\nProcessing message: \"" << messages[front] << "\" ";
        for (int i = 0; i < timeToPop; i++) cout << ".";

        front++;
        size--;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    MessageQueue m(3, 5);
    m.enqueue("My");
    m.enqueue("Name is");
    m.enqueue("Umer");
    m.enqueue("Goodbye!");

    while (!m.isEmpty()) m.dequeue();

    return 0;
}
