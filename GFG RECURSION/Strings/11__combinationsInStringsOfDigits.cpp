#include <bits/stdc++.h>
using namespace std;

void combinations(char input[], int i, char output[], int outlength){

    if(input[i] == '\0'){

        output[outlength] = '\0';
        cout << output << "\n";
        return;
    }
    

    output[outlength] = input[i];
    output[outlength + 1] = ' ';

    combinations(input, i+1, output, outlength + 2);

    if(input[i+1] != '\0'){
        combinations(input, i+1, output, outlength +1);
    }

}

int main(){
    char input[] = "123";
    char output[100];
 
    // initialize output with empty string
    output[0] = '\0';
     
    combinations(input, 0, output, 0);
    return 0;
}