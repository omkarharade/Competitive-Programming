#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

void printIncreasing(int n) {

	if (n == 0) return;

	printIncreasing(n - 1);
	cout << n << " ";
}

void printDecreasing(int n) {

	if (n == 0) return;

	cout << n << " ";
	printDecreasing(n - 1);

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	printIncreasing(10);
	cout << nline;
	printDecreasing(10);


	return 0;
}