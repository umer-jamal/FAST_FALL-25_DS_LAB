#include <iostream>
#include <vector>
using namespace std;

int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int num : arr)
        if (num > mx) mx = num;
    return mx;
}

void countingSort(vector<int>& arr, int exp, bool ascending) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    if (ascending) {
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
    } else {
        for (int i = 8; i >= 0; i--)
            count[i] += count[i + 1];
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSortAscending(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp, true);
}

void radixSortDescending(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp, false);
}

int main() {
    vector<int> arr = {5, 75, 10, 8, 24, 2, 32};
    cout << "Original array:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n\n";

    vector<int> asc = arr;
    radixSortAscending(asc);
    cout << "Ascending order:\n";
    for (int num : asc) cout << num << " ";
    cout << "\n\n";
    vector<int> desc = arr;
    radixSortDescending(desc);
    cout << "Descending order:\n";
    for (int num : desc) cout << num << " ";
    cout << "\n";

    return 0;
}
