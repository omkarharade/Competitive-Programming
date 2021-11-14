#include <bits/stdc++.h>
using namespace std;

int main(){
    
    stack <int> myStack;
    myStack.push(20);
    myStack.push(10);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);
    myStack.push(80);
    myStack.pop();
    myStack.pop();
    cout << myStack.size() << endl;

    cout << "The current element at the top of the stack is " << myStack.top();

    return 0;
}