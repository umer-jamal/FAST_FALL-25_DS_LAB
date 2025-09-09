#include<iostream>
using namespace std;

void selectionSort(int *arr,int n){
    int minInd = 0;
    for (int i = 0; i <n-1; i++)
    {
        minInd = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[minInd]>arr[j])
            {
                minInd = j;
            }
            
        }
        swap(arr[i],arr[minInd]);
    }
    
}


int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }
    
    selectionSort(arr,10);
    cout<<"Minimum 4 elements are: \n";
    for (int i = 0; i < 4; i++)
    {
        cout<<arr[i]<<" ";
    }
    

return 0;
}
