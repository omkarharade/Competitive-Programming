#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


void move(int n, char src, char helper, char des) {

	if (n == 0) return;

	move(n - 1, src, des, helper);
	cout << "shift disk " << n << " from " << src << " to " << des << nline;
	move(n - 1, helper, src, des );
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	move(n, 'A', 'B', 'C');


	return 0;
}