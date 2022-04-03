#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define ll long long

bool isOdd(int n) {
	return (n & 1);
}

int getBit(int n, int i) {

	int mask = (1 << i);

	return ((n & mask) > 0 ? 1 : 0 );
}


void setBit(int &n, int i) {

	int mask = (1 << i);
	n = n | mask;
}


void clearBit(int &n, int i) {

	int mask = ~(1 << i);
	n = n & mask;
}
void updateBit(int &n, int i, int v) {

	clearBit(n, i);
	int mask = (v << i);
	n = n | mask;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	setBit(n, 1);
	cout << n << nline;

	clearBit(n, 1);
	cout << n << nline;

	cout << getBit(n, 1);


	return 0;
}