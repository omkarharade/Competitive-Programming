#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int totalJumps(int totalSteps) {

	if (totalSteps == 0) return 1;
	if (totalSteps < 0) return 0;

	return totalJumps(totalSteps - 1) + totalJumps(totalSteps - 2) + totalJumps(totalSteps - 3);

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int totalSteps = 4;

	cout << totalJumps(totalSteps) << nline;


	return 0;
}