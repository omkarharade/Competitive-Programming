#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
vector<int> divisors[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif


	for (int i = 2; i < N; ++i)
	{
		for (int j = i ; j < N; j += i)
		{
			divisors[j]	.push_back(i);
		}
	}

	for (int i = 1; i < 10; ++i)
	{
		if (divisors[i].size() == 2) {
			cout << "YES" << nline;
		}
		else cout << "NO" << nline;
	}


	return 0;
}