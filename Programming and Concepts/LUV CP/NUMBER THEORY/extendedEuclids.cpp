#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int gcd(int a, int b, int &x, int &y) {

	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int d = gcd(b, a % b, x1, y1);

	x = y1;
	y = x1 - y1 * (a / b);

	return d;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	int a, b, x, y;

	cin >> a >> b;

	cout << gcd(16, 10, x, y) << nline;

	cout << "x = " << x << " y = " << y << nline;

	return 0;
}