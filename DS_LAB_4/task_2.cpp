#include<iostream>
using namespace std;

void insertionSort(int *arr,int n){
    for (int i = 1; i < n; i++)
    {
        int cur = arr[i];
        int prev = i-1;
        while (prev>=0 && arr[prev]>cur)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        // swap(arr[prev+1],arr[i]);
        arr[prev+1] = cur;
        
    }
    // moving last (max) element to mid

    int mid = n/2;
    int max = arr[n-1];
    int j = n-2;
    while (arr[mid]!=max)
    {
        swap(arr[j],arr[j+1]);
        j--;

    }
    
}


int main()
{
    int arr[9] = { 20, 12, 15, 2, 10, 1, 13, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    

return 0;
}
