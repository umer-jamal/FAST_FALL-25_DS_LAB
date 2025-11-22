#include <iostream>
using namespace std;

struct Pair {
    int first;
    int second;
};

struct HashNode {
    int key;
    Pair value;
    HashNode* next;

    HashNode(int k, Pair v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
    static const int SIZE = 100;
    HashNode* table[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = nullptr;
    }

    void insert(int key, Pair value) {
        int index = hashFunction(key);
        HashNode* newNode = new HashNode(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    HashNode* search(int key) {
        int index = hashFunction(key);
        HashNode* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

void findPairs(int arr[], int n) {
    HashTable ht;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];
            HashNode* node = ht.search(sum);

            if (node != nullptr) {
                int a = node->value.first;
                int b = node->value.second;
                int c = arr[i];
                int d = arr[j];

                if (a != c && a != d && b != c && b != d) {
                    cout << "(" << a << ", " << b << ") and ("
                         << c << ", " << d << ")" << endl;
                    return;
                }
            }

            Pair p;
            p.first = arr[i];
            p.second = arr[j];
            ht.insert(sum, p);
        }
    }

    cout << "No pairs found" << endl;
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    findPairs(arr1, 7);
    int arr2[] = {3, 4, 7, 1, 12, 9};
    findPairs(arr2, 6);
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    findPairs(arr3, 7);

    return 0;
}
