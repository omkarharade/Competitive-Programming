// this sum not done yet
#include <bits/stdc++.h>
using namespace std;

int matPuzz(int **arr, int **visited, int inx, int iny, int x1, int y1, int x2, int y2){

    if( x1 == x2 && y1 == y2){
        cout << "found" << endl;
        return 1;
    }
    else if(x1 < inx || x1 > x2 || y1 < iny || y1 > y2){
        return 0;
    }

    else if(arr[x1][y1] == 1){
        return 0;
    }

    else{

        return (
            matPuzz(arr, visited, inx, iny, x1-1, y1, x2, y2)+
            matPuzz(arr, visited,inx, iny, x1+1, y1, x2, y2)+
            matPuzz(arr, visited, inx, iny, x1, y1-1, x2, y2)+
            matPuzz(arr, visited, inx, iny, x1, y1+1, x2, y2)
            );
    }
    
}

int main(){
    
    int m, n;
    cout << "Enter no. of rows and columns" << endl;
    cin >> m >> n;
    int **arr = new int*[m];
    int **visited = new int*[m];
    

    cout << "Enter Matrix Info" << endl;

    for (int i = 0; i < m; i++)
    {
        cout << "Enter " << n<< " elements in row " << i+1 << endl;
        arr[i] = new int[n];
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = false;
        }
        
    }
    cout << "Enter initial position " << endl;

    int currx, curry;
    cin >> currx >> curry;


    cout << matPuzz(arr, visited, 0, 0, currx-1, curry-1, m-1, n-1) << endl;
    
    return 0;
}