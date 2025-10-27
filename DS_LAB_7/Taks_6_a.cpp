#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void countingSort(int arr[], int n, int place) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; ++i)
        count[(arr[i] / place) % 10]++;

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSortArray(int arr[], int n) {
    int maxVal = findMax(arr, n);
    for (int place = 1; maxVal / place > 0; place *= 10)
        countingSort(arr, n, place);
}

int main() {
    int arr1[10], arr2[10];
    cout << "Enter 10 elements for arr1:\n";
    for (int i = 0; i < 10; ++i) cin >> arr1[i];
    cout << "Enter 10 elements for arr2:\n";
    for (int i = 0; i < 10; ++i) cin >> arr2[i];

    int merged[20];
    for (int i = 0; i < 10; ++i) merged[i] = arr1[i];
    for (int i = 0; i < 10; ++i) merged[10 + i] = arr2[i];

    radixSortArray(merged, 20);

    cout << "\nCombined sorted array (Radix Sort):\n";
    for (int i = 0; i < 20; ++i)
        cout << merged[i] << " ";
    cout << endl;

    return 0;
}
