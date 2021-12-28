#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>

int totalPaths = 0;

void display(vvb& visited, vvi& grid, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1){
                cout << "x ";
            }
            else{
                cout << visited[i][j] << " ";
            }
        }
        cout << "\n";
    }
        cout << "\n\n";
    
}

bool isSafe(int i, int j, int n, vvb &visited ) {
    return i>= 0 && j >=0 && i < n && j < n && visited[i][j] == false;
}

void helper(int i, int j, int n, vvi &grid, vvb &visited ){
    if(i == n-1 && j == n-1) {
        totalPaths++;
        visited[i][j] = true;
        display(visited, grid, n);
        return;
    }

    if(!isSafe(i, j, n, visited)){
        // pruning
        return;
    }

    visited[i][j] = true;

    if(i+1 < n && grid[i+1][j] == 0){
        helper(i+1, j, n, grid, visited);
    }
    if(i-1 >= 0 && grid[i-1][j] == 0){
        helper(i-1, j, n, grid, visited);
    }
    if(j+1 < n && grid[i][j+1] == 0){
        helper(i, j+1, n, grid, visited);
    }
    if(j-1 >= 0 && grid[i][j-1] == 0){
        helper(i, j-1, n, grid, visited);
    }
    
    visited[i][j] = false;
    return;

}
void countRatMazePaths(vvi grid) {

    int n = grid.size();
    vvb visited(n, vector<bool>(n, false));
    
    helper(0, 0, n, grid, visited );
    cout << totalPaths;
}


int main(){

    int n;
    cin >> n;
    vvi grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << "\npossible paths are \n\n";
    countRatMazePaths(grid);

    
    return 0;
}