#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d = 0)
    {
        data = d;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        tail = head = NULL;
    }

    void push_back(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            return;
        }
    }
    void push_front(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }
    }
    void concatenate(DoublyLinkedList *d)
    {
        this->tail->next = d->head;
        d->head->prev = this->tail;
        this->tail = d->tail;
        this->tail->next = NULL;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    DoublyLinkedList L;
    DoublyLinkedList M;
    M.push_back(6);
    M.push_back(7);
    M.push_back(8);
    M.print();

    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.push_front(1);
    L.print();

    L.concatenate(&M);
    L.print();
    return 0;
}
