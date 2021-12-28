#include <bits/stdc++.h>
using namespace std;

int countAns = 0;

void display(vector<vector<bool>> &grid, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]){
                cout << "Q ";
            }
            else
                cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool isSafe(vector<vector<bool>> &grid, int row, int col , int n){

    for (int i = row-1; i >= 0 ; i--)
    {
        if(grid[i][col])
            return false;
        
    }

    for (int i = row -1, j = col - 1; i >= 0 && j >= 0; i--,j--)
    {
        if(grid[i][j])
            return false;
        
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--,j++)
    {
        if(grid[i][j])
            return false;
        
    }
        return true;
    
}

void countNQueen(vector<vector<bool>> &grid, int currRow, int n){

    if(currRow == n){
        display(grid, n);
        countAns++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if(isSafe(grid, currRow, i, n)){

            grid[currRow][i] = true;
            countNQueen(grid, currRow+1, n);
            grid[currRow][i] = false;
            
        }
    }
    
}

int main(){

    int n;
    cin>> n;
    cout << "\n\n";
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    countNQueen(grid, 0, n);
    cout <<countAns << endl;
    return 0;
}