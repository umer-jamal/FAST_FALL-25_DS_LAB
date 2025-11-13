#include<iostream>
using namespace std;




void heapifyDown(int array[],int n,int ind) {
    int smallest = ind;
    int left = 2*ind+1;
    int right =2*ind+2 ;

    if (left < n && array[left] > array[smallest])
        smallest = left;
        
    if (right < n && array[right] >array[smallest])
        smallest = right;

    if (smallest != ind) {
        swap(array[ind], array[smallest]);
        heapifyDown(array,n,smallest);
    }
}

 

void convertMinHeap_MaxHeap(int *arr,int n){
    for (int i = n/2 -1; i >=0; i--)
    {
        heapifyDown(arr,n,i);
    }

}

int main(){
    int a[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    convertMinHeap_MaxHeap(a,10);

    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<"  ";
    }
    
}