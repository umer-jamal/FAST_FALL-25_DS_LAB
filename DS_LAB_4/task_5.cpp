#include<iostream>
using namespace std;


void sortForBirthYear(int *arr,int n){
    // int max = arr[0];
    // for (int i = 0; i <n; i++)
    // {
    //     if (arr[i]>max)
    //     {
    //         max = arr[i];
    //     }
        
    // }

   int *ans = new int[n];
   int count[10] = {0};

   for (int i = 0; i < n; i++)
   {
        int ind = arr[i]%10;
        count[ind]++;
    }
    
    for (int i = 1; i < 10; i++)
    {
        count[i] +=count[i-1];
   }
   
   for (int i = n-1; i >= 0; i--)
   {
       int ind = arr[i]%10;
       ans[count[ind] - 1] = arr[i];
       count[ind]--;

   }

   for (int i = 0; i < n; i++)
   {
        arr[i] = ans[i];
   }
   
   delete[] ans;
   
   
   
    
    
}

int main()
{

    int arr[6] = {2022, 2023, 2024, 2022, 2023, 2024};
    sortForBirthYear(arr,6);
    for (int i = 0; i <6; i++)
    {
        cout<<arr[i]<<"  ";
    }
    

return 0;
}
