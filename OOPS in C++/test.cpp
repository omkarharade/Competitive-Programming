#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
typedef long long ll;

long long sum(long long num) {

	return num * (num + 1) / 2;
}
void solve() {

	int n, s;
	cin >> n >> s;

	if (n >= s) {
		cout << sum(s) << nline;
	}
	else {
		cout << sum(s) - sum(s - n) << nline;
	}

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;

	while (t--) {

		solve();
	}

	return 0;
}