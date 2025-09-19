#include<iostream>
using namespace std;


int recursiveArraySum(int **arr,int *size,int row,int col,int n){ // n = no of rows
    static int sum = 0;
    
    if (row==n-1 && col==size[row])
    {
        return sum;
    }
    if (col==size[row])
    {
        row++;
        col = 0;
    }
    sum+=arr[row][col];
    return recursiveArraySum(arr,size,row,col+1,n);

    

    
}

int main()
{
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    int **arr = new int*[n];
    int *size = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter size of row "<<i+1<<" : ";
        cin>>size[i];
        arr[i] = new int[size[i]];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout<<"\tRow "<<i+1<<endl;
        for (int j = 0; j < size[i]; j++)
        {
            cout<<"Enter element "<<j+1<<" : ";
            cin>>arr[i][j];
            sum+= arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < size[i]; j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Sum of this multi dimensional array is : ";
    cout<<recursiveArraySum(arr,size,0,0,n);
    
return 0;
}
