#include <bits/stdc++.h>
using namespace std;

void revString(string &str, int i, int j){
    // base case
    if(i >= j) return;

    // self work
    char ch = str[i];
    str[i] = str[j];
    str[j] = ch;

    // recursive intution
    revString(str, i+1, j-1);
}

int main(){
    string str = "timepass";

    revString(str, 0, str.length()-1);
    cout << str;
    return 0;
}

// an alternate code from techiedelight

// #include <iostream>
// #include <algorithm>
// using namespace std;
 
// // Recursive function to reverse a given string
// // Note string is passed as a reference parameter
// void reverse(string &str, int k)
// {
//     static int i = 0;
 
//     // if the end of the string is reached
//     if (k == str.length()) {
//         return;
//     }
 
//     reverse(str, k + 1);
 
//     if (i <= k) {
//         swap(str[i++], str[k]);
//     }
// }
 
// int main()
// {
//     string str = "Techie Delight";
 
//     reverse(str, 0);
//     cout << "Reverse of the given string is " << str;
 
//     return 0;
// }