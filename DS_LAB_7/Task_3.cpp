#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time;
};

void mergeByTime(vector<Runner>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<Runner> leftPart(leftSize);
    vector<Runner> rightPart(rightSize);

    for (int i = 0; i < leftSize; ++i)
        leftPart[i] = arr[left + i];
    for (int j = 0; j < rightSize; ++j)
        rightPart[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftPart[i].time < rightPart[j].time)
            arr[k++] = leftPart[i++];
        else
            arr[k++] = rightPart[j++];
    }

    while (i < leftSize)
        arr[k++] = leftPart[i++];
    while (j < rightSize)
        arr[k++] = rightPart[j++];
}

void sortRunners(vector<Runner>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    sortRunners(arr, left, mid);
    sortRunners(arr, mid + 1, right);
    mergeByTime(arr, left, mid, right);
}

int main() {
    const int total = 6;
    vector<Runner> runners(total);

    for (int i = 0; i < total; ++i) {
        cout << "Enter name of runner " << i + 1 << ": ";
        getline(cin >> ws, runners[i].name);
        cout << "Enter finish time (in seconds): ";
        cin >> runners[i].time;
    }

    sortRunners(runners, 0, total - 1);

    cout << "\nTop 5 fastest runners:\n";
    for (int i = 0; i < 5; ++i)
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].time << " seconds\n";
}
