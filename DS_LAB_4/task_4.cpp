#include<iostream>
using namespace std;


bool isDuplicateExist(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]==arr[j])
            {
                return 1;
            }
            
        }
        
    }
    return 0;
    
}

int main()
{
    int arr[4] = {1,1,4,5};
    cout<<isDuplicateExist(arr,4);


return 0;
}
