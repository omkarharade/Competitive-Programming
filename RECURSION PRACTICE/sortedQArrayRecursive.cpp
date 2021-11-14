#include <bits/stdc++.h>
using namespace std;

bool sortedArray(int arr[], int n){

    if(n == 1)
        return true;

    if(n == 2 && arr[0] < arr[1])
        return true;
    
    else if(arr[n-2] < arr[n-1] && sortedArray(arr, n-1))
        return true;
    else return false;
}

int main(){
    int arr[] = {1,2,3,4,5};

    cout << sortedArray(arr, 5) << "\n";
    return 0;
}