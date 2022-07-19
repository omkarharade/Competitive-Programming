#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int fib(int n) {

	if ((n == 0) or (n == 1)) return n;
	return fib(n - 1) + fib(n - 2);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here 0 1 1 2 3 5

	cout << fib(5) << nline;


	return 0;
}