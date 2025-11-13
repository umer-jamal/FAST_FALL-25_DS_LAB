#include<iostream>
using namespace std;

bool isMaxHeap(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        if (2*i+1<n && arr[i]<arr[2*i+1])
        {
            return false;
        }
        if (2*i+2<n && arr[i]<arr[2*i+2])
        {
            return false;
        }
    }
    return true;
    
}
bool isMinHeap(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        if (2*i+1<n && arr[i]>arr[2*i+1])
        {
            return false;
        }
        if (2*i+2<n && arr[i]>arr[2*i+2])
        {
            return false;
        }
    }
    return true;
    
}

bool isBinaryHeap(int *arr,int n){
    return isMaxHeap(arr,n) || isMinHeap(arr,n);
}



int main(){
    int a[] = {8,7,6,5,4};
    cout<<isBinaryHeap(a,5);
}