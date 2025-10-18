#include <iostream>
#include <string>
using namespace std;

/* To ensure that restaurant orders are processed in the order they were received,
 I would use a Queue data structure. A queue follows the FIFO (First-In-First-Out) principle,
 meaning the first order placed will be the first order processed
*/

/* i will create a order class where i would have an item array and quantity array
for each particular item then i will create a restaurant class where
 i have a queue of orders implemented using linked list
*/

/*Overflow: Since the queue is implemented using a linked list, it can grow dynamically.
 Overflow is not a concern unless the system memory is full.

Underflow: Before removing (dequeueing) an order, checking if
 the queue is empty using an isEmpty() function. If empty 
 displaying an appropriate message and returning early
 */

class Order
{
public:
    string *items;
    int *quantities;
    int size;

    Order(string items[], int quantities[], int size)
    {
        this->size = size;
        this->items = new string[size];
        this->quantities = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->items[i] = items[i];
            this->quantities[i] = quantities[i];
        }
    }
};

class Node
{
public:
    Order *order;
    Node *next;
    Node(Order *order)
    {
        this->order = order;
        next = nullptr;
    }
};

class RestaurantQueue
{
public:
    Node *front;
    Node *rear;

    RestaurantQueue()
    {
        front = rear = nullptr;
    }

    void addOrder(Order *order)
    {
        Node *newNode = new Node(order);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    Order *processOrder()
    { // dequeue
        if (isEmpty())
        {
            cout << "No orders to process (Underflow)" << endl;
            return nullptr;
        }
        Node *temp = front;
        Order *order = front->order;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        return order;
    }

    void displayOrders()
    {
        Node *temp = front;
        int j = 0;
        while (temp != nullptr)
        {
            cout << "\tOrder " << j + 1 << endl;
            for (int i = 0; i < temp->order->size; i++)
            {
                cout << temp->order->items[i] << " x " << temp->order->quantities[i] << endl;
            }
            cout << "---------------------------\n";
            j++;
            temp = temp->next;
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    RestaurantQueue rq;
    rq.processOrder();
    string items1[] = {"Burger", "Fries"};
    int quantities1[] = {2, 1};
    Order *o1 = new Order(items1, quantities1, 2);
    rq.addOrder(o1);
    string items2[] = {"Pizza", "Coke"};
    int quantities2[] = {1, 2};
    Order *o2 = new Order(items2, quantities2, 2);
    rq.addOrder(o2);
    rq.displayOrders();
    rq.processOrder();
    cout<<"After processing one order:" << endl;
    rq.displayOrders();

    return 0;
}
