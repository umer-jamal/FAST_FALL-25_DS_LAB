#include <iostream>
using namespace std;

void mergeParts(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void sortMerge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sortMerge(arr, left, mid);
        sortMerge(arr, mid + 1, right);
        mergeParts(arr, left, mid, right);
    }
}

void mergeSortedArrays(int a[], int n1, int b[], int n2, int res[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
        res[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < n1) res[k++] = a[i++];
    while (j < n2) res[k++] = b[j++];
}

int main() {
    int first[10], second[10];
    cout << "Enter 10 elements for first array:\n";
    for (int i = 0; i < 10; ++i) cin >> first[i];
    cout << "Enter 10 elements for second array:\n";
    for (int i = 0; i < 10; ++i) cin >> second[i];

    sortMerge(first, 0, 9);
    sortMerge(second, 0, 9);

    int merged[20];
    mergeSortedArrays(first, 10, second, 10, merged);

    cout << "\nCombined sorted array:\n";
    for (int i = 0; i < 20; ++i)
        cout << merged[i] << " ";
    cout << endl;

    return 0;
}
