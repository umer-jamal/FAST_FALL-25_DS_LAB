#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int >>arr,int n,int x,int y){
    if (x<n && y<n && arr[x][y]==1)
    {
        return 1;
    }
    return 0;
    
}

bool ratInMaze(vector<vector<int >>&arr,int n,int x,int y,int i,int j){
    if (x==i && y==j && arr[x][y]==1)
    {
        return 1;
    }
    
    if (isSafe(arr,n,x,y))
    {
        arr[x][y] = -1;
        if(ratInMaze(arr,n,x,y+1,i,j))
            return true;
        
        if(ratInMaze(arr,n,x+1,y,i,j))
            return true;

        if(ratInMaze(arr,n,x,y-1,i,j))
            return true;
        
            if(ratInMaze(arr,n,x-1,y,i,j))
            return true;

        arr[x][y] = 0;
        return false;
    }
    return false;
    
}

int main()
{
    int n = 4;
    vector<vector<int>> arr = { {1,1,1,1},
                                {0,0,0,1},
                                 {1,1,0,1},
                                {1,1,1,1} };

    cout<<ratInMaze(arr,4,0,0,3,3);

return 0;
}
