#include <bits/stdc++.h>
using namespace std;

void sumTriangle(int arr[], int n){

    if(n == 1){
        cout << arr[0] << endl;
        return;
    }

    int temp[n-1];

    for (int i = 0; i < n-1; i++)
    {
        temp[i] = arr[i] + arr[i+1];
    }
    
    sumTriangle(temp, n-1);
    

    for (int i = 0; i < n; i++){

        cout << arr[i] << " ";

    }
    cout<< "\n";

}

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    sumTriangle(arr, 5);
    return 0;
}