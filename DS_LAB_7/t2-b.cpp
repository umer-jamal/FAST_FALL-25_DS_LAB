#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0)
    {
        data = d;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_back(int d)
    {
        Node *temp = new Node(d);
        if (!head)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void merge(List *list)
    {
        Node *t1 = head;
        Node *t2 = list->head;
        Node *next1, *next2;

        while (t1 != NULL && t2 != NULL)
        {
            next1 = t1->next;
            next2 = t2->next;

            t1->next = t2;
            t2->next = next1;

            t1 = next1;
            t2 = next2;
        }

        list->head = t2;
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
    List l1, l2;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(7);
    l2.push_back(8);

    l1.print();
    l2.print();
    l1.merge(&l2);
    l1.print();
    l2.print();
}