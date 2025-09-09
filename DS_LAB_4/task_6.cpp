#include<iostream>
using namespace std;

void countingSort(int *arr,int n,int exp){
    int *ans = new int[n];
    int count[10] = {0};

    int ind = 0;
    for (int i = 0; i <n; i++)
    {
        ind = (arr[i] / exp)%10;
        count[ind]++;
    }
    
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1]; 
    }

    for (int i = n-1; i >=0; i--)
    {
        ind = (arr[i] / exp) %10;
        ans[count[ind]-1] = arr[i];
        count[ind]--;
    }
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
    
    delete[] ans;
}
    
    
void radixSort(int *arr,int n){
    int exp = 1;
    while (arr[0] /exp >0 ) // considering all elements have same digits
    {
        countingSort(arr,n,exp);
        exp *=10;
    }

}



int main()
{
    int arr[] = {452913, 100234, 987654,100001};
    radixSort(arr,4);
    for (int i = 0; i < 4; i++)
    {
        cout<<arr[i]<<"  ";
    }
    

return 0;
}
