#include<iostream>
using namespace std;


void bubbleSort(string *arr,int n){
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        for (int j = i+1; j < n-i; j++)
        {
            if (arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
                flag = 1;
            }
            
        }
        if (!flag)
        {
            break;
        }
        
    }
    
}

int main()
{

string arr[] = {"banana", "apple", "cherry", "date", "grape"};
bubbleSort(arr,5);
for (int i = 0; i < 5; i++)
{
    cout<<arr[i]<<",  ";
}


return 0;
}
