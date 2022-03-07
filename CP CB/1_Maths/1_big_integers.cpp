#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

void multiply(int *a, int &n, int num) {

	int carry = 0;

	for (int i = 0; i < n; i++)
	{
		int product = (a[i] * num) + carry;

		a[i] = product % 10;
		carry = product / 10;
	}

	while (carry) {
		a[n] = carry % 10;
		carry = carry / 10;
		n++;
	}
}
void bigFactorial(int number) {

	int *a = new int[1000];

	for (int i = 0; i < 1000; i++) {
		a[i] = 0;
	}

	a[0] = 1;
	int n = 1;

	for (int num = 2; num <= number; ++num)
	{
		multiply(a, n, num);
	}

	// printing the result

	for (int i = n - 1; i >= 0; i--) {
		cout << a[i];
	}

	delete [] a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	bigFactorial(n);


	return 0;
}