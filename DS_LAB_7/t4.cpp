#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<string>> &arr, int n, int row, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][col] == "Q")
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j>=0; i--, j--)
    {
        if (arr[i][j] == "Q")
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j<n; i--, j++)
    {
        if (arr[i][j] == "Q")
        {
            return false;
        }
    }

    return true;
}

bool NQueens(vector<vector<string>> &arr, int n, int row)
{
    if (row == n)
    {
        return 1;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, n, row, col))
        {
            arr[row][col] = "Q";
            if (NQueens(arr, n, row + 1))
                return 1;
            arr[row][col] = ".";    
        }
    }
    return 0;
}

int main()
{

    vector<vector<string>> arr = {{".", ".", ".", "."},
                                  {".", ".", ".", "."},
                                  {".", ".", ".", "."},
                                  {".", ".", ".", "."}};

    cout << NQueens(arr, 4, 0);

    return 0;
}
