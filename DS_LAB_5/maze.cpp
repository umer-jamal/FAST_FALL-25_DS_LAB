
#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    return (x < n && y < n && arr[x][y] == 1);
}

bool maze(int **arr, int **sol, int x, int y, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        sol[x][y] = 1;

        if (maze(arr, sol, x + 1, y, n))
            return true;
        if (maze(arr, sol, x, y + 1, n))
            return true;

        sol[x][y] = 0; // backtrack
        return false;
    }
    return false;
}

int main()
{
    int n = 2;
    int **arr = new int *[n];
    int **sol = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 0;
    arr[1][1] = 1;

    cout << maze(arr, sol, 0, 0, n);
}
