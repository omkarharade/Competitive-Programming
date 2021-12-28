#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


int recurAtoi(char *str, int n) {

	if (n == 1) return *str - '0';

	return (10 * recurAtoi(str, n - 1) + str[n - 1] - '0');

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	char str[] = "123";

	int n = strlen(str);

	cout << recurAtoi(str, n) << nline;

	return 0;
}