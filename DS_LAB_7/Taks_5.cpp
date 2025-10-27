#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node* getLast(Node* node) {
    while (node && node->next)
        node = node->next;
    return node;
}

Node* partitionList(Node* head, Node* tail) {
    Node* pivot = head;
    Node* prev = head;
    Node* curr = head;

    while (curr != tail->next) {
        if (curr->data < pivot->data) {
            swap(curr->data, prev->next->data);
            prev = prev->next;
        }
        curr = curr->next;
    }

    swap(pivot->data, prev->data);
    return prev;
}

void quickSortHelper(Node* head, Node* tail) {
    if (!head || head == tail) return;
    Node* pivot = partitionList(head, tail);
    quickSortHelper(head, pivot);
    quickSortHelper(pivot->next, tail);
}

Node* quickSortList(Node* head) {
    Node* tail = getLast(head);
    quickSortHelper(head, tail);
    return head;
}

int main() {
    Node* head = new Node(30);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(5);

    cout << "\nList before sorting:\n";
    printList(head);

    head = quickSortList(head);

    cout << "\nList after sorting:\n";
    printList(head);

    cout << endl;
    return 0;
}
