#include <bits/stdc++.h>
using namespace std;
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>

int combinations = 0;
void display(vvi& grid, int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
        
    }
        cout << "\n\n";
    
}

bool isSafe(vvi& grid, int i, int j, int n, vvb& visited){

    return i >= 0 && j >= 0 && i < n && j < n && visited[i][j] == false;
}

void knightsTour(vvi& grid, int i, int j, int n, int count, vvb& visited){

    if(count == n*n -1){
        grid[i][j] = count;
        combinations++;
        display(grid, n);
        return;
    }

    int xdir[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int ydir[8] = {-1,  1, -2,  2, -2, 2, -1, 1};

    grid[i][j] = count;
    visited[i][j] = true;

    for (int k = 0; k < 8; k++)
    {
        if(isSafe(grid, i+xdir[k], j+ydir[k], n, visited)){
            knightsTour(grid, i+xdir[k], j+ydir[k], n, count+1, visited);
        }
    }
    grid[i][j] = -1;
    visited[i][j] = false;
}

int main(){

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, -1));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    knightsTour(grid, 0, 0, n, 0, visited);
    cout << combinations << "\n";
    return 0;
}