#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int tilesPlacing(int length) {

	int poss1 = 0, poss2 = 0;
	if (length > 0) poss1 = (1 + tilesPlacing(length - 1));
	if (length - 4 > 0) poss2 = (1 + tilesPlacing(length - 4));

	return poss1 + poss2;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here


	return 0;
}