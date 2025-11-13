#include<iostream>
using namespace std;


class minHeap{
    int *array;
    int maxSize;
    int size;
    public:
    minHeap(int s){
        array = new int[s];
        size = 0;
        maxSize = s;
    }

    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<array[i]<<"  ";
        }
        cout<<endl;
        
    }

    void insert(int data){
        if (size>=maxSize)
        {
            cout<<"Overflow\n";
            return;
        }
        
        array[size] = data;
        heapifyUp(size);
        size++;
    }
    int getParent(int ind){
        return (ind-1) /2;
    }
    int getLeft(int ind){
        return 2*ind+1;
    }
    int getRight(int ind){
        return 2*ind+2;
    }
    void heapifyUp(int ind){
        if (ind==0)
        {
            return;
        }
        if (array[ind]<array[getParent(ind)])
        {
            swap(array[ind],array[getParent(ind)]);
            ind = getParent(ind);
            heapifyUp(ind);
        }
        return;
        
    }

    void deleteVal(){
        if (size==0)
         {
            cout<<"Underflow\n";
            return;
         }
        
        array[0] = array[size-1];
        size--;
        heapifyDown(0);

         
    }

   void heapifyDown(int ind) {
    int smallest = ind;
    int left = getLeft(ind);
    int right = getRight(ind);

    if (left < size && array[left] < array[smallest])
        smallest = left;
    if (right < size && array[right] < array[smallest])
        smallest = right;

    if (smallest != ind) {
        swap(array[ind], array[smallest]);
        heapifyDown(smallest);
    }
}

};

class maxHeap{
    int *array;
    int maxSize;
    int size;
    public:
    maxHeap(int s){
        array = new int[s];
        size = 0;
        maxSize = s;
    }
    int getParent(int ind){
        return (ind-1) /2;
    }
    int getLeft(int ind){
        return 2*ind+1;
    }
    int getRight(int ind){
        return 2*ind+2;
    }
    void insert(int data){
        if (size>=maxSize)
        {
            cout<<"Overflow\n";
            return;
        }
        
        array[size] = data;
        heapifyUp(size);
        size++;
    }   
    void heapifyUp(int ind){
         if (ind==0)
        {
            return;
        }
        if (array[ind]>array[getParent(ind)])
        {
            swap(array[ind],array[getParent(ind)]);
            ind = getParent(ind);
            heapifyUp(ind);
        }
        return;
    }
    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<array[i]<<"  ";
        }
        cout<<endl;
        
    }
    void deleteVal(){
        if (size==0)
         {
            cout<<"Underflow\n";
            return;
         }
        
        array[0] = array[size-1];
        size--;
        heapifyDown(0);

         
    }

    void heapifyDown(int ind) {
    int smallest = ind;
    int left = getLeft(ind);
    int right = getRight(ind);

    if (left < size && array[left] > array[smallest])
        smallest = left;
    if (right < size && array[right] > array[smallest])
        smallest = right;

    if (smallest != ind) {
        swap(array[ind], array[smallest]);
        heapifyDown(smallest);
    }
}

    void update(int i,int key){
        array[i] = key;
        deleteVal();
    }

   
};


int main(){
    // minHeap h(5);
    // h.insert(5);
    // h.insert(20);
    // h.insert(10);
    maxHeap h2(10);
    h2.insert(4);
    h2.insert(5);
    h2.insert(6);
    h2.insert(7);
    h2.insert(8);
    h2.print();
    h2.update(0,1);
    h2.print();
}