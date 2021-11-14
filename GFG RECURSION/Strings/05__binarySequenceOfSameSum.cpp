#include <bits/stdc++.h>
using namespace std;

void sumOfSecondHalfBits(int diff, int start, int end, char* output){

    if(start > end){

        if(diff == 0)
            cout << output << " ";
        
        return;
    }

    output[start] = '0', output[end] = '0';
    sumOfSecondHalfBits(diff, start+1, end-1, output);

    output[start] = '0', output[end] = '1';
    sumOfSecondHalfBits(diff + 1, start+1, end-1, output);

    output[start] = '1', output[end] = '0';
    sumOfSecondHalfBits(diff -1, start+1, end-1, output);

    output[start] = '1', output[end] = '1';
    sumOfSecondHalfBits(diff, start+1, end-1, output);

    

}

int main(){
    
    int n = 3;

    // allocate string containing 2*n characters
    char output[2 * n + 1];
 
    // null terminate output array
    output[2 * n] = '\0';
 
    sumOfSecondHalfBits(0, 0, 2*n-1, output);
    return 0;
}