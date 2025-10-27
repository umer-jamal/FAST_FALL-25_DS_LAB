#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    float price;
    string description;
    bool available;
};

int partitionProducts(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j].price <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortProducts(Product arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partitionProducts(arr, low, high);
        quickSortProducts(arr, low, pivotIndex - 1);
        quickSortProducts(arr, pivotIndex + 1, high);
    }
}

int main() {
    const int n = 3;
    Product products[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter product " << i + 1 << " name: ";
        getline(cin >> ws, products[i].name);
        cout << "Enter description: ";
        getline(cin >> ws, products[i].description);
        cout << "Enter price: ";
        cin >> products[i].price;
        cout << "Available (1 for Yes / 0 for No): ";
        cin >> products[i].available;
        cin.ignore();
        cout << endl;
    }

    quickSortProducts(products, 0, n - 1);

    cout << "\nProducts sorted by price (ascending):\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". " << products[i].name
             << " | Price: " << products[i].price
             << " | Description: " << products[i].description
             << " | Available: " << (products[i].available ? "Yes" : "No") << endl;
    }

    return 0;
}
