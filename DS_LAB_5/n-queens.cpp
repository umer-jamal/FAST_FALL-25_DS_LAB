#include <iostream>
using namespace std;

bool isSafe(string **arr, int n, int row, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[row][i] == "F")
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (arr[i][col] == "F")
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == "F")
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (arr[i][j] == "F")
        {
            return false;
        }
    }

    return true;
}

void nFlags(string **arr, int n, int row)
{
    if (n == row)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, n, row, i))
        {
            arr[row][i] = "F";
            nFlags(arr, n, row + 1);

            arr[row][i] = ".";
        }
    }
}

int main()
{
    int n = 4;

    string **arr = new string *[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = new string[4];
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = ".";
        }
    }
    nFlags(arr, 4, 0);

    return 0;
}
